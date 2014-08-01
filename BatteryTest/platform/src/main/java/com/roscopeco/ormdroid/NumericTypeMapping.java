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

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

/*
 * TODO: this could be folded into StringTypeMapping, by having a flag that
 * determines whether or not we sqlescape the resulting string...?
 * 
 *     Obviously would make things more difficult when load()ing...
 */
public class NumericTypeMapping implements TypeMapping {
  private Class<?> mJavaType; 
  private String mSqlType;
  
  public NumericTypeMapping(Class<?> type, String sqlType) {
    mJavaType = type;
    mSqlType = sqlType;      
  }

  public Class<?> javaType() {
    return mJavaType;
  }

  public String sqlType(Class<?> concreteType) {
    return mSqlType;
  }

  public String encodeValue(Object value) {
    if (value instanceof Boolean) {
      return (Boolean)value ? "1" : "0";
    } else if (value instanceof Float && ((Float)value).isNaN()) {
      // SQLite doesn't really support NaN, store them as null for now..
      return null;
    } else if (value instanceof Double && ((Double)value).isNaN()) {
      // SQLite doesn't really support NaN, store them as null for now..
      return null;
    } else {      
      return value.toString();
    }
  }

  // TODO this will cause exceptions when trying to unbox into smaller types...
  //        or worse, silently lose data... Look into this!
  public Object decodeValue(Class<?> expectedType, Cursor c, int columnIndex) {
    if (expectedType.equals(Boolean.class) || expectedType.equals(boolean.class)) {
      int i = c.getInt(columnIndex);
      return (i == 0) ? false : true;
    } else if(expectedType.equals(Double.class) || expectedType.equals(double.class)) {
    	return c.getDouble(columnIndex);
    } else if(expectedType.equals(Float.class) || expectedType.equals(float.class)) {
    	return c.getFloat(columnIndex);
    } else if(expectedType.equals(Long.class) || expectedType.equals(long.class)) {
    	return c.getLong(columnIndex);
    } else if(expectedType.equals(Short.class) || expectedType.equals(short.class)) {
    	return c.getShort(columnIndex);
    } else {
      return c.getInt(columnIndex);
    }
  }
}