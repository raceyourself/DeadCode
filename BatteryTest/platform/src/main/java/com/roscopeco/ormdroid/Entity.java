/*
 * Copyright 2012 Ross Bamford
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. 
 */
package com.roscopeco.ormdroid;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Pattern;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.fasterxml.jackson.annotation.JsonIgnore;

import lombok.extern.slf4j.Slf4j;

/**
 * <p>Base class for persistent entities. The only hard requirements
 * for model classes are that they subclass this class, and that
 * they provide a (currently integral) primary key (see below).</p>
 * 
 * <p><code>Entity</code> is the primary class in ORMDroid, and is
 * where most interaction with the API will take place. A model class
 * will subclass this class, and will inherit its save() and delete()
 * methods from it. The simplest possible model class would be:</p>
 * 
 * <p><pre><code>
 * public class Person extends Entity {
 *   public int id;
 * }
 * </pre></code></p>
 * 
 * <p>This is obviously useless, as it holds no data other than the
 * (required) primary key. In order to actually store other data,
 * you would add further public fields. Entities may also define 
 * any methods you wish - these are never called by the framework</p>
 * 
 * <h3>Table & column names</h3>
 * 
 * <p>By default, the framework creates table names based on the 
 * fully-qualified name of the entity class. You can change this
 * behaviour by applying the {@link Table} annotation to the class,
 * e.g:</p>
 * 
 * <p><pre><code>
 * {@literal @}Table(name = "people")
 * public class Person extends Entity {
 *   // ...
 * }
 * </pre></code></p>
 * 
 * <p>Similarly, any column can be explicitly named using the
 * {@link Column} annotation:</p>
 * 
 * <p><pre><code>
 *   {@literal @}Column(name = "person_name")
 *   public String name;
 * </pre></code></p>
 *  
 * <h3>Primary key field</h3>
 * 
 * <p>In the example above, the framework automatically selects the 
 * primary key field based on it's name. Currently, the framework
 * will use the first field it finds named 'id' or '_id', and will
 * map these fields to database column '_id' in any case, unless
 * the field is explicitly named (see above).</p>
 * 
 * <p>It is possible to explicitly select the primary key column
 * using the {@link Column} annotation:
 * 
 * <p><pre><code>
 *   {@literal @}Column(primaryKey = true)
 *   public int myPrimaryKey;
 * </pre></code></p>
 * 
 * <p>It should be noted that, although you can use any data type
 * for primary key fields, parts of the framework currently expect
 * primary keys to be integers, and will behave in an indeterminite
 * manner if other types are used. This limitation primarily affects
 * the {@link Query} class, and the {@link #equals(Object)} and 
 * {@link #hashCode()} implementations defined in this class, and
 * will be removed in a future version.</p>
 * 
 * <h3>Private fields</h3>
 * 
 * By default, private fields are ignored when mapping model classes.
 * It is possible to force them to be mapped, however, using the
 * {@link Column} annotation
 * 
 * <p><pre><code>
 *   {@literal @}Column(forceMap = true)
 *   private String myPrivateField;
 * </pre></code></p>
 * 
 * <h3>Relationships</h3>
 * 
 * <p>The framework currently provides built-in support for 
 * one-to-one relationships - simply adding a field of an 
 * <code>Entity</code>-subclass type will cause that field to
 * be persisted when the containing object is persisted.</p>
 * 
 * <p>Many relationships are not currently natively supported,
 * but can easily be implemented using helper methods on your
 * model class. For example (taken from the ORMSample app):</p>
 * 
 * <p><pre><code>
 * public List<Person> people() {
 *   return query(Person.class).where("department").eq(id).executeMulti();
 * }
 * </pre></code></p>
 * 
 * <p>More support for such relationships (including entity type mappings
 * for {@link java.util.List} and {@link java.util.Map}) will be added in a 
 * future version.</p>
 * 
 * <p>If you have a bidirectional relationship, you must annotate one side
 * of that relationship with the 
 * <code>{@literal @}{@link Column}(inverse = true)</code> annotation 
 * to prevent infinite loops when persisting your data. This will prevent
 * the inverse field from being persisted when it's model is stored.</p>
 * 
 * <h3>Model lifecycle</h3>
 * 
 * <p>The typical lifecycle of a model is shown below:</p>
 * 
 * <p><pre><code>
 * MyModel m = new MyModel();
 *   // ... or ... 
 * MyModel m = Entity.query(MyModel).whereId().eq(1).execute();
 * 
 *   // ... do some work ...
 *   
 * MyModel.save();
 *   // ... or ...
 * MyModel.delete();
 * </pre></code></p>
 * 
 * <h3>{@link #equals} and {@link #hashCode}</h3>
 * 
 * <p>The default implementation of equals and hashCode provided
 * by this class define equality in terms of primary key, and 
 * utilise reflective field access. You may of course override 
 * these if you wish to change their behaviour, or for performance
 * reasons (e.g. to directly compare primary key fields rather than
 * using reflection).</p>
 */
@Slf4j
public abstract class Entity {
  static final class EntityMapping {
    private static final Pattern MATCH_DOTDOLLAR = Pattern.compile("[\\.\\$]");
    
    private Class<? extends Entity> mMappedClass;
    String mTableName;
    private Field mPrimaryKey;
    String mPrimaryKeyColumnName;
    private ArrayList<String> mColumnNames = new ArrayList<String>();
    private ArrayList<Field> mFields = new ArrayList<Field>();
    boolean mSchemaCreated = false;

    // Not concerned too much about reflective annotation access in this
    // method, since this only runs once per model class...
    static EntityMapping build(Class<? extends Entity> clz) {
      EntityMapping mapping = new EntityMapping();
      mapping.mMappedClass = clz;
      Table table = clz.getAnnotation(Table.class);
      if (table != null) {
        mapping.mTableName = table.name();
      } else {
        mapping.mTableName = MATCH_DOTDOLLAR.matcher(clz.getName()).replaceAll("");
      }

      ArrayList<String> seenFields = new ArrayList<String>();
      for (Field f : clz.getDeclaredFields()) {
        f.setAccessible(true);
      
        // Blithely ignore this field if we've already seen one with same name -
        // Java field hiding allows this to happen and if it does, without this
        // we'd be adding the same column name twice.
        //
        // We might as well also ignore it here if it's inverse, since we'll
        // never want to access it via the mapping.
        //
        // Also, ignore statics/finals (bug #4)
        //
        // We ignore private fields, *unless* they're annotated with
        // the force attribute.
        Column colAnn = f.getAnnotation(Column.class);
        boolean inverse = colAnn != null && colAnn.inverse();
        boolean force = colAnn != null && colAnn.forceMap();

        int modifiers = f.getModifiers();
        if (!Modifier.isStatic(modifiers) &&
            !Modifier.isFinal(modifiers) &&
            (!Modifier.isPrivate(modifiers) || force) &&
            !seenFields.contains(f.getName()) && 
            !inverse) {
          
          // Check we can map this type - if not, let's fail fast.
          // This will save us wierd exceptions somewhere down the line...
          if (TypeMapper.getMapping(f.getType()) == null) {
            throw new TypeMappingException("Model " + 
                                           clz.getName() + 
                                           " has unmappable field: " + f);
          }
          
          Column col = f.getAnnotation(Column.class);
          String name;

          if (col != null) {
            // empty is default, means we should use field name...
            if ("".equals(name = col.name())) {
              name = f.getName();
            }

            if (col.primaryKey()) {
              mapping.mPrimaryKey = f;
              mapping.mPrimaryKeyColumnName = name;
            }
          } else {
            name = f.getName();
          }

          // Try to default primary key if we don't have one yet...
          if (mapping.mPrimaryKey == null) {
            if ("_id".equals(name) || "id".equals(name)) {
              mapping.mPrimaryKey = f;
              mapping.mPrimaryKeyColumnName = name;
            }
          }

          mapping.mFields.add(f);
          mapping.mColumnNames.add(name);
          seenFields.add(f.getName());
        }
      }

      if (mapping.mPrimaryKey == null) {
        // Error at this point - we must have a primary key!
        log.error("No primary key specified or determined for " + clz);
        throw new ORMDroidException(
            "No primary key was specified, and a default could not be determined for " + clz);
      }

      return mapping;
    }

    synchronized void createSchema() {

            Cursor cursor = ORMDroidApplication.getInstance().query("PRAGMA table_info(" + mTableName + ")");

            // If table already exists, check it matches the model
            if (cursor.getCount() > 0) {
                int nameIdx = cursor.getColumnIndexOrThrow("name");
                int typeIdx = cursor.getColumnIndexOrThrow("type");

                // SQLite only supports adding columns (not deleting or
                // renaming them), so only look for
                // columns that exist in the model but not in the table:
                for (Field f : mFields) {
                    boolean fieldExists = false;
                    cursor.moveToFirst();
                    do {
                        String name = cursor.getString(nameIdx);
                        String type = cursor.getString(typeIdx);
                        if (f.getName().equals(name)
                                && TypeMapper.sqlType(f.getType()).equals(type)) {
                            fieldExists = true;
                            break;
                        }
                    } while (cursor.moveToNext());
                    
                    // if we didn't find a model field in the table, add it:
                    if (fieldExists == false) {
                        String constraint = "";
                        Column col = f.getAnnotation(Column.class);
                        if (col != null && col.unique())
                            constraint = " UNIQUE";
                        ORMDroidApplication.getInstance().execSQL("ALTER TABLE " + mTableName + " ADD COLUMN " + f.getName()
                                + " " + TypeMapper.sqlType(f.getType()) + constraint + ";");
                    }
                }
                cursor.close();
                mSchemaCreated = true;

            } else {

                // if the table didn't exist, create it:
                StringBuilder b = new StringBuilder();
                b.append("CREATE TABLE IF NOT EXISTS " + mTableName + " (");

                int len = mFields.size();
                for (int i = 0; i < len; i++) {
                    String colName = mColumnNames.get(i);

                    // Without this we'll add overridden fields twice...
                    b.append(colName);
                    b.append(" ");
                    b.append(TypeMapper.sqlType(mFields.get(i).getType()));
                    if (colName.equals(mPrimaryKeyColumnName)) {
                        b.append(" PRIMARY KEY");
                        if ("INTEGER".equals(TypeMapper.sqlType(mFields.get(i).getType()))) {
                            b.append(" AUTOINCREMENT");
                        }
                    } else {
                        Column col = mFields.get(i).getAnnotation(Column.class);
                        if (col != null && col.unique())
                            b.append(" UNIQUE");
                    }

                    if (i < len - 1) {
                        b.append(",");
                    }
                }

                b.append(");");

                String sql = b.toString();
                ORMDroidApplication.getInstance().execSQL(sql);
                mSchemaCreated = true;
            }

    }

    private boolean isAutoincrementedPrimaryKey(Field f) {
    	if (!isPrimaryKey(f)) return false;
    	if ("INTEGER".equals(TypeMapper.sqlType(f.getType()))) {
    		return true;
    	} else {
    		return false;
    	}
    }
    
    private boolean isPrimaryKey(Field f) {
      return mPrimaryKey.equals(f);
    }

    Object getPrimaryKeyValue(Entity o) {
      try {
        return mPrimaryKey.get(o);
      } catch (IllegalAccessException e) {
        log.error("IllegalAccessException accessing primary key " + mPrimaryKey
                + "; Update failed");
        throw new ORMDroidException(
            "IllegalAccessException accessing primary key " + mPrimaryKey
                + "; Update failed");
      }
    }

    private void setPrimaryKeyValue(Entity o, Object value) {
      try {
        mPrimaryKey.set(o, value);
      } catch (IllegalAccessException e) {
        log.error("IllegalAccessException accessing primary key " + mPrimaryKey
                + "; Update failed");
        throw new ORMDroidException(
            "IllegalAccessException accessing primary key " + mPrimaryKey
                + "; Update failed");
      }
    }

    private String processValue(Object value) {
      return TypeMapper.encodeValue(value);
    }

    private String getColNames(Entity receiver) {
      StringBuilder b = new StringBuilder();
      ArrayList<String> names = mColumnNames;
      ArrayList<Field> fields = mFields;
      int len = names.size();

      for (int i = 0; i < len; i++) {
        Field f = fields.get(i);
        if (receiver != null && isAutoincrementedPrimaryKey(f)) {
            Object val;
            try {
              val = f.get(receiver);
            } catch (IllegalAccessException e) {
              // Should never happen...
              log.error("IllegalAccessException accessing field "
                      + fields.get(i).getName() + "; Inserting NULL");
              val = null;
            }
        	// Don't list column if it's an auto-incremented primary key
        	// with a null/0 value.
            if (val == null || (val instanceof Integer && (Integer)val == 0)) continue;
        }

        b.append(names.get(i));
        
        if (i < len-1) {
          b.append(",");
        }
      }

      return b.toString();
    }

    private String getFieldValues(Entity receiver) {
      StringBuilder b = new StringBuilder();
      ArrayList<Field> fields = mFields;
      int len = fields.size();

      for (int i = 0; i < len; i++) {
        Field f = fields.get(i);
        Object val;
        try {
          val = f.get(receiver);
        } catch (IllegalAccessException e) {
          // Should never happen...
          log.error("IllegalAccessException accessing field "
                  + fields.get(i).getName() + "; Inserting NULL");
          val = null;
        }
          
        // Rebox undefined/0 int PK to null Integer so we can ignore and auto-increment it
        if (isAutoincrementedPrimaryKey(f) && val instanceof Integer && (Integer)val == 0) val = null;
        
        if (val != null || !isAutoincrementedPrimaryKey(f)) {
	        b.append(val == null ? "null" : processValue(val));
	
	        if (i < len-1) {
	          b.append(",");
	        }
        }
      }

      return b.toString();
    }

    private String getSetFields(Object receiver) {
      StringBuilder b = new StringBuilder();
      ArrayList<String> names = mColumnNames;
      ArrayList<Field> fields = mFields;
      int len = names.size();

      for (int i = 0; i < len; i++) {
        Field f = fields.get(i);
        String name = names.get(i);

        // We don't want to set the primary key...
        if (name != mPrimaryKeyColumnName) {
          b.append(name);
          b.append("=");
          Object val;
          try {
            val = f.get(receiver);
          } catch (IllegalAccessException e) {
            log.error("IllegalAccessException accessing field "
                    + fields.get(i).getName() + "; Inserting NULL");
            val = null;
          }
          b.append(val == null ? "null" : processValue(val));
          if (i < (len - 1)) {
            b.append(",");
          }
        }
      }

      return b.toString();
    }
    
    /* issue #6 */
    private String stripTrailingComma(String string) {
      // check for last comma
      if (string.endsWith(",")) {
        return string.substring(0, string.length() - 1);
      }
      return string;
    }

    int insert(Entity o) {
      String sql = "INSERT OR REPLACE INTO " + mTableName + " ("
          + stripTrailingComma(getColNames(o)) + ") VALUES ("
          + stripTrailingComma(getFieldValues(o)) + ")";


        ORMDroidApplication.getInstance().execSQL(sql);
      
        if (!isAutoincrementedPrimaryKey(mPrimaryKey)) return 0;
      
        Cursor c = ORMDroidApplication.getInstance().query("select last_insert_rowid();");
        if (c.moveToFirst()) {
          Integer i = c.getInt(0);
          setPrimaryKeyValue(o, i);
          c.close();
          return i;
        } else {
          c.close();
          throw new ORMDroidException(
              "Failed to get last inserted id after INSERT");
        }

    }

    void update(Entity o) {
      // stripTrailingComma: issue #9
      String sql = "UPDATE " + mTableName + " SET " + stripTrailingComma(getSetFields(o))
          + " WHERE " + mPrimaryKeyColumnName + "=" + processValue(getPrimaryKeyValue(o));

      ORMDroidApplication.getInstance().execSQL(sql);
    }

    /*
     * Doesn't move the cursor - expects it to be positioned appropriately.
     */
    <T extends Entity> T load(Cursor c) {
      try {
        // TODO we should be checking here that we've got data before
        // instantiating...
        @SuppressWarnings("unchecked")
        T model = (T) mMappedClass.newInstance();
        model.mTransient = false;

        ArrayList<String> colNames = mColumnNames;
        ArrayList<Field> fields = mFields;
        int len = colNames.size();

        for (int i = 0; i < len; i++) {
          Field f = fields.get(i);
          Class<?> ftype = f.getType();
          int colIndex = c.getColumnIndex(colNames.get(i));
          
          if (colIndex == -1) {
            log.error("Internal<ModelMapping>", "Got -1 column index for `"+colNames.get(i)+"' - Database schema may not match entity");
            throw new ORMDroidException("Got -1 column index for `"+colNames.get(i)+"' - Database schema may not match entity");
          } else {
            Object o = TypeMapper.getMapping(f.getType()).decodeValue(ftype,
                c, colIndex);
            f.set(model, o);
          }
        }

        return model;
      } catch (InstantiationException e) {
        throw new ORMDroidException(
            "Failed to instantiate model class - does it have a public null constructor?",
            e);
      } catch (IllegalAccessException e) {
        throw new ORMDroidException(
            "Access denied. Is your model's constructor non-public?",
            e);
      }
    }

    /*
     * Moves cursor to start, and runs through all records.
     */
    <T extends Entity> List<T> loadAll(Cursor c) {
      ArrayList<T> list = new ArrayList<T>();

      if (c.moveToFirst()) {
        do {
          list.add(this.<T> load(c));
        } while (c.moveToNext());
      }
      
      /* issue #6 */
      c.close();      

      return list;
    }
    
    void delete(Entity o) {
      String sql = "DELETE FROM " + mTableName + " WHERE " + 
                   mPrimaryKeyColumnName + "=" + processValue(getPrimaryKeyValue(o));

      ORMDroidApplication.getInstance().execSQL(sql);
      o.mTransient = true;
    }
    
    public String toString() {
      String classname = this.getClass().getSimpleName();
      if (classname == null || classname.length() == 0) {
        classname = "Anonymous entity";
      }
      return classname;
    }

  } // end of EntityMapping

  private static final HashMap<Class<? extends Entity>, EntityMapping> entityMappings = new HashMap<Class<? extends Entity>, EntityMapping>();

  /*
   * Package private - used by Query as well as locally...
   */
  static EntityMapping getEntityMapping(Class<? extends Entity> clz) {
    EntityMapping mapping = entityMappings.get(clz);

    if (mapping == null) {
      // build map
      entityMappings.put(clz, mapping = EntityMapping.build(clz));
    }

    return mapping;
  }

  static EntityMapping getEntityMappingEnsureSchema(Class<? extends Entity> clz) {
    EntityMapping map = getEntityMapping(clz);
    if (!map.mSchemaCreated) {
      map.createSchema();
    }
    return map;
  }
  
  static void resetEntityMappings() {
	  entityMappings.clear();
  }

  /**
   * <p>Create a new {@link Query} that will query against the
   * table mapped to the specified class.</p>
   * 
   * <p>See the {@link Query} documentation for examples of
   * usage.</p>
   * 
   * @param clz The class to query.
   * @return A new <code>Query</code>.
   */
  public static <T extends Entity> Query<T> query(Class<T> clz) {
    return new Query<T>(clz);
  }

  @JsonIgnore
  public boolean mTransient;
  private EntityMapping mMappingCache;

  protected Entity() {
    mTransient = true;
  }

  /**
   * <p>Determine whether this instance is backed by the database.</p>
   * 
   * <p><strong>Note</strong> that a <code>false</code> result
   * from this method does <strong>not</strong> indicate that
   * the data in the database is up to date with respect to the
   * object's fields.</p>
   * 
   * @return <code>false</code> if this object is stored in the database.
   */
  public boolean isTransient() {
    return mTransient;
  }

  private EntityMapping getEntityMapping() {
    // This may be called multiple times on a single instance,
    // (e.g. during a save, looking for primary keys and whatnot)
    // so we cache it per instance, to save the hash cache lookup...
    if (mMappingCache != null) {
      return mMappingCache;
    } else {
      return mMappingCache = getEntityMapping(getClass());
    }
  }

  private EntityMapping getEntityMappingEnsureSchema() {
    EntityMapping map = getEntityMapping();
    if (!map.mSchemaCreated) {
      map.createSchema();
    }
    return map;
  }

  /**
   * <p>Get the value of the primary key field for this object.</p>
   * 
   * <p>Note that this currently uses reflection.</p>
   * 
   * @return The primary key value.
   */
  public Object getPrimaryKeyValue() {
    return getEntityMapping().getPrimaryKeyValue(this);
  }

  /**
   * Insert or update this object using the specified database
   * connection.
   * 
   * @param db The database connection to use.
   * @return The primary key of the inserted item (if object was transient), or -1 if an update was performed.
   */
  public int save() {
    EntityMapping mapping = getEntityMappingEnsureSchema();

    int result = -1;

    if (mTransient) {
      result = mapping.insert(this);
      mTransient = false;
    } else {
      mapping.update(this);      
    }

    return result;
  }

  
  /**
   * Delete this object using the specified database connection.
   * 
   * @param db The database connection to use.
   */
  public void delete() {
    EntityMapping mapping = getEntityMappingEnsureSchema();
    
    if (!mTransient) {
      mapping.delete(this);
    }
  }
  
  /**
   * Defines equality in terms of primary key values. 
   */
  @Override
  public boolean equals(Object other) {
    // TODO indirectly using reflection here (via getPrimaryKeyValue).
    return other != null && 
           other.getClass().equals(getClass()) && 
           ((Entity) other).getPrimaryKeyValue().equals(getPrimaryKeyValue());    
  }

  /**
   * Defines the hash code in terms of the primary key value. 
   */
  @Override
  public int hashCode() {
    // TODO this uses reflection. Also, could act wierd if non-int primary keys... 
    return 31 * getClass().hashCode() + getPrimaryKeyValue().hashCode();
  }
  
  /**
   * Write all records of this entity type to a CSV file
   * @author GlassFit
   * @param filename to write data to
   * @throws IOException
   */
  public void allToCsv(File file) throws IOException {
      
      List<? extends Entity> rows = query(this.getClass()).executeMulti();
      
      FileWriter fstream = new FileWriter(file);
      BufferedWriter out = new BufferedWriter(fstream);
      
      // column headers
      out.write(getEntityMapping().getColNames(this));
      out.write("\n");

      // values
      for(Entity row : rows){
          out.write(row.getEntityMapping().getFieldValues(row));
          out.write("\n");
      }
      out.close();
  }
  
  public String headersToCsv() {
       return getEntityMapping().getColNames(this);
  }
  
  public String toCsv() {
      
      return this.getEntityMapping().getFieldValues(this);
  }
  
}
