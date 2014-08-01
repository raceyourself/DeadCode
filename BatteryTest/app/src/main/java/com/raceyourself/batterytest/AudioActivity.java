package com.raceyourself.batterytest;

import android.os.Bundle;
import android.widget.TextView;

import java.io.IOException;
import java.util.Hashtable;

import edu.gvsu.masl.echoprint.AudioFingerprinter;

public class AudioActivity extends BaseTestActivity implements AudioFingerprinter.AudioFingerprinterListener {

    TextView audioResults;
    AudioFingerprinter af;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTagAndName("AudioActivity", "Audio");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio);

        audioResults = (TextView)findViewById(R.id.audioResults);

        af = new AudioFingerprinter(this);

        try {
            af.insertFingerprint("Robert Marley", "dsf35sdf3432asd3tHTs3wdx==");
        } catch (IOException e) {
            e.printStackTrace();
        }

        af.fingerprint(10, true);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

    @Override
    public void didFinishListening() {
        audioResults.setText("didFinishListening");
    }

    @Override
    public void didFinishListeningPass() {
        audioResults.setText("didFinishListeningPass");
    }

    @Override
    public void willStartListening() {
        audioResults.setText("willStartListening");
    }

    @Override
    public void willStartListeningPass() {
        audioResults.setText("willStartListeningPass");
    }

    @Override
    public void didGenerateFingerprintCode(String code) {
        audioResults.setText("didGenerateFingerprintCode");
    }

    @Override
    public void didFindMatchForCode(Hashtable<String, String> table, String code) {
        audioResults.setText("didGenerateFingerprintCode " + table.get(AudioFingerprinter.TRACK_ID_KEY) + " " + table.get(AudioFingerprinter.SCORE_KEY));
    }

    @Override
    public void didNotFindMatchForCode(String code) {
        audioResults.setText("didNotFindMatchForCode");
    }

    @Override
    public void didFailWithException(Exception e) {
        audioResults.setText("didFailWithException " + e.getClass().getSimpleName() + "/" + e.getLocalizedMessage());
    }
}
