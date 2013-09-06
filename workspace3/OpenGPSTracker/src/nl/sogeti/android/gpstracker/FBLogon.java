package nl.sogeti.android.gpstracker;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.annotation.TargetApi;
import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;

import com.facebook.LoggingBehavior;
import com.facebook.Request;
import com.facebook.Response;
import com.facebook.Session;
import com.facebook.Session.StatusCallback;
import com.facebook.SessionState;
import com.facebook.Settings;
import com.facebook.model.GraphUser;

/**
 * Activity which displays a login screen to the user, offering registration as well.
 */
public class FBLogon extends Activity
{
   /**
    * A dummy authentication store containing known user names and passwords. TODO: remove after connecting to a real authentication system.
    */
   private static final String[] DUMMY_CREDENTIALS = new String[] { "foo@example.com:hello", "bar@example.com:world" };

   /**
    * The default email to populate the email field with.
    */
   public static final String EXTRA_EMAIL = "com.example.android.authenticatordemo.extra.EMAIL";

   private LoginStatusCallback loginCallback = new LoginStatusCallback();
   
   // Values for email and password at the time of the login attempt.
   private String mEmail;
   private String mPassword;

   // UI references.
   private EditText mEmailView;
   private EditText mPasswordView;
   private View mLoginFormView;
   private View mLoginStatusView;
   private TextView mLoginStatusMessageView;

   @Override
   protected void onCreate(Bundle savedInstanceState)
   {
      super.onCreate(savedInstanceState);

      setContentView(R.layout.activity_fblogon);
      
      Log.i("Facebook", "Initialized");

      // Set up the login form.
      mEmail = getIntent().getStringExtra(EXTRA_EMAIL);
      mEmailView = (EditText) findViewById(R.id.email);
      mEmailView.setText(mEmail);

      mPasswordView = (EditText) findViewById(R.id.password);
      mPasswordView.setOnEditorActionListener(new TextView.OnEditorActionListener()
         {
            @Override
            public boolean onEditorAction(TextView textView, int id, KeyEvent keyEvent)
            {
               if (id == R.id.login || id == EditorInfo.IME_NULL)
               {
                  attemptLogin();
                  return true;
               }
               return false;
            }
         });
      
      Settings.addLoggingBehavior(LoggingBehavior.REQUESTS);
      Settings.addLoggingBehavior(LoggingBehavior.APP_EVENTS);
      Settings.addLoggingBehavior(LoggingBehavior.INCLUDE_RAW_RESPONSES);
      
      mLoginFormView = findViewById(R.id.login_form);
      mLoginStatusView = findViewById(R.id.login_status);
      mLoginStatusMessageView = (TextView) findViewById(R.id.login_status_message);

      findViewById(R.id.sign_in_button).setOnClickListener(new View.OnClickListener()
         {
            @Override
            public void onClick(View view)
            {
               attemptLogin();
            }
         });
   }

   @Override
   public boolean onCreateOptionsMenu(Menu menu)
   {
      super.onCreateOptionsMenu(menu);
      getMenuInflater().inflate(R.menu.fblogon, menu);
      return true;
   }

   /**
    * Attempts to sign in or register the account specified by the login form. If there are form errors (invalid email, missing fields, etc.), the errors are presented and no actual login attempt is
    * made.
    */
   public void attemptLogin()
   {
/*            
      if (mAuthTask != null)
      {
         return;
      }
*/
      // Reset errors.
      mEmailView.setError(null);
      mPasswordView.setError(null);

      // Store values at the time of the login attempt.
      mEmail = mEmailView.getText().toString();
      mPassword = mPasswordView.getText().toString();

      boolean cancel = false;
      View focusView = null;

/*      // Check for a valid password.
      if (TextUtils.isEmpty(mPassword))
      {
         mPasswordView.setError(getString(R.string.error_field_required));
         focusView = mPasswordView;
         cancel = true;
      }
      else if (mPassword.length() < 4)
      {
         mPasswordView.setError(getString(R.string.error_invalid_password));
         focusView = mPasswordView;
         cancel = true;
      }

      // Check for a valid email address.
      if (TextUtils.isEmpty(mEmail))
      {
         mEmailView.setError(getString(R.string.error_field_required));
         focusView = mEmailView;
         cancel = true;
      }
      else if (!mEmail.contains("@"))
      {
         mEmailView.setError(getString(R.string.error_invalid_email));
         focusView = mEmailView;
         cancel = true;
      }
*/
      if (cancel)
      {
         // There was an error; don't attempt login and focus the first
         // form field with an error.
         focusView.requestFocus();
      }
      else
      {
         // Show a progress spinner, and kick off a background task to
         // perform the user login attempt.
         mLoginStatusMessageView.setText(R.string.login_progress_signing_in);
         showProgress(true);

         Log.i("Facebook", "Opening session - pre");
         Session.openActiveSession(this, true, loginCallback);         
         Log.i("Facebook", "Opening session - post");
         
      }
   }

   /**
    * Shows the progress UI and hides the login form.
    */
   @TargetApi(Build.VERSION_CODES.HONEYCOMB_MR2)
   private void showProgress(final boolean show)
   {
      // On Honeycomb MR2 we have the ViewPropertyAnimator APIs, which allow
      // for very easy animations. If available, use these APIs to fade-in
      // the progress spinner.
      if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2)
      {
         int shortAnimTime = getResources().getInteger(android.R.integer.config_shortAnimTime);

         mLoginStatusView.setVisibility(View.VISIBLE);
         mLoginStatusView.animate().setDuration(shortAnimTime).alpha(show ? 1 : 0).setListener(new AnimatorListenerAdapter()
            {
               @Override
               public void onAnimationEnd(Animator animation)
               {
                  mLoginStatusView.setVisibility(show ? View.VISIBLE : View.GONE);
               }
            });

         mLoginFormView.setVisibility(View.VISIBLE);
         mLoginFormView.animate().setDuration(shortAnimTime).alpha(show ? 0 : 1).setListener(new AnimatorListenerAdapter()
            {
               @Override
               public void onAnimationEnd(Animator animation)
               {
                  mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
               }
            });
      }
      else
      {
         // The ViewPropertyAnimator APIs are not available, so simply show
         // and hide the relevant UI components.
         mLoginStatusView.setVisibility(show ? View.VISIBLE : View.GONE);
         mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
      }
   }

   public class LoginStatusCallback implements StatusCallback {

      // callback when session changes state
      @Override
      public void call(Session session, SessionState state, Exception exception) {
        if (session.isOpened()) {
           Log.e("Facebook", "Session opened");           

          // make request to the /me API
          Request.newMeRequest(session, new Request.GraphUserCallback() {

            // callback after Graph API response with user object
            @Override
            public void onCompleted(GraphUser user, Response response) {
              if (user != null) {
                 Log.e("Facebook", "User available");
//                TextView welcome = (TextView) findViewById(R.id.welcome);
//                welcome.setText("Hello " + user.getName() + "!");
                 finish();
              }
              else
              {
                 Log.e("Facebook", "Error in newMeRequest");
//                 mPasswordView.setError(getString(R.string.error_incorrect_password));
//                 mPasswordView.requestFocus();
                 setContentView(R.layout.activity_fblogon);
//                 Session.getActiveSession().addCallback(loginCallback);
              }
              
            }
          }).executeAsync();
        }/*
        else
        {
           String x = "Error in StatusCallback.call " + state.toString() + " ";
           if (exception != null) x = x + exception.getMessage();
           Log.i("Facebook", x);
//           mPasswordView.setError(getString(R.string.error_incorrect_password));
//           mPasswordView.requestFocus();
           setContentView(R.layout.activity_fblogon);
           Session.getActiveSession().addCallback(loginCallback);
        }*/
      }
    }   
}