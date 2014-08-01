package com.raceyourself.batterytest;

import android.os.Bundle;
import android.util.Log;
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
            af.insertFingerprint("Pot noodle", "eJy1mFuOHDsORLekFyVxOZJI7n8Jc9QDuO5toOSPwcBGwM6qzlSSwYhgp5Sypwe0_YKuLzjtBX4ekHN5wWgPKKW-QNIL5nxBxAPqOS_w8oDW9AG89QtKe0G1F7w7OPYLdL7g3v07-HhA5s8DZn3Bzi849QU-H1B6f8F8QvgD6q3Xd4j6gFSeUP0Fvbzg3f3dXnBJ_RXyfa_vIOsFZg8oOV4g-oJ-XnBF6ztc2n6HOA-oy19wb_AV_qYM4wWyX3C_8R1UX7DnC46-IMoDch4vePNq2AuuLH2FUsoLlr7g3f3WH5DyeMG7v11esOoLruB9hb_U-V1JOy8Ie0DtT9D2gl1e4PKA1MYLhr9gP-FHwr_B_8T2dxd2vMDaC958nvsFb627D_8Ozx7VWA9o67zg5AfczPGANzf2eoH5A_Lt1Hd4d7_7C_7CjfMCqy-4xf4K9QrPdxj9BVNf4P0FT26koi_4keGvcOnzHSy_4Ofh3-D_2N8WLzjygnd__6Kxrx61O03f4RLkC2g5VSVUC7vS6kdyMjaQ2f3MM0fKXPUWxbqamaa8VCii_MxR7NWtS5mhRRdh_aDa8_hafc7d5XCb1YwclyVWXiPa1BY9ovV68rLwMqTl09zOPm21tY8rozBUu-XIdTcZa9iuZ4z7hbPcIws_HLtuGWLuo8hyXdamrDb36N58hc3D88oWlXFQZt1q5VjhpyO39rOyctTubAIiPtSNRYYvl-YNP5W-LJ9QolPZ3FrLGgUd1hlD0nROEJr17tTH-V7tqfOmwYlPK7kOrU35pJaqZxrbtbZ2theXnnZx_v0HtC-fv659IGsr9704adbZNFt1K6uGbSoxqdX0KpR6lVZCe2RP0hDnReNqHjQYyxtNpsxc-xLvemsROWhplrSNSuoKpwxBKbN23DevfCb7CA22DRVWL26BEWn0PI6PraMk78XmrEVC8l4ceOg5vUR1fnT1Fr5SbnB4cyJ4s-NUtvaDn7lysM494_hs9KwXtKy3LbAnzdNVLnVG2HCal6fuQTvmnG3U4cO9lnPusj22j94S5zKBdseyCyfqq_ns2x3uOryYp7VJrxrxP9Ph4EQ1QSyB5OUwZmiWWR3JWhVLvCr1VNFDM9mCIGF34gOnKRP9m1B7rZZzhmKX1OEKlWGj73JyGUvq9EjdhHOUNMe2soeUEBPts25aqaGcDYbEAY6snNreH1iV-v-69oG0tKdpytcYIKnbuRsLmTOxe1sbyteOGuVcu9c9yOs75rmmUQotHqWHRLUyupUM1RhQO1looe9a-UkpXfPmWYdcxSGrHYjQq_UptVm0Ybqk51qnecsU8k5CSGfkGLHqjKU6NOqOqkRPtvKGzkzIYbOU0lqMalB1Tl2ceLIG5QHb0iqokHGPe8I9OUPloX3QdlSqqq_RYKzOe8SZyVdhLffMqwxfvkO85uNM69yWaF2GR3x8ehSRxjjpoWvG9LDibnqlUKhSVZNGV3SuM2dRJljyOcLJWnFKQMyvmSVjjB7prGjWkaXJBHabG5EyG3nD9XAkaggsHX5VdnnUQa2Z0bkRKVQDPvRe8uQdtSGyc8cHuIfOX9c-MDbzVBiutbQYhejWNu-jAvGor5W56lVHmpCunHckwi53mG0am5WJDQiaIM8cXYyMWpN2WMD7OSoSspFIHy1qhVVXTzGGhuRLKWs6akJtJw-k77rG4VbTbfIxhRGrbVKv3CZiBM2j5jlR1MAiODzinKgvc0EMPdtkXokcU0fmHjaanVXGwOT8_o7CYBb-UHkrdikP4whXa3aOiLFilTnF26ADw_GYEQgoxlQYjPXzW8hadq6LLpTNIHL-trMrrPY6LuvnuqKSPW_jULNVZob_REKTvEyK3ITRhfzthK2NwrPFZj1xrRDP-SEbB_UCha9sMuwF7UUyag3BByf-9wcyQrh-XfvHp46SwyR6ss8oC1nfW3PfXFX--n-buRe1kRxFox6hrQk_kPv73A5NDkqvtweLso2FHUVx3S65oUSKMJvlTudWK4iPwHZ4UumIYgyl4bu2z24e-H2eUScWftCU2ch4pMDqDrvJCrQaIdoEBiUjdI5MVzazf2gKMi2ECIKCzIVxpzsAGefIZ8BkbiJJjtalbaWjrWdfWn1l5I-QUJnWfcgD17EWNs7DS204BuJvfpPEQQJKarmUmbv2a5g0Bn0d8A-3V-jQ6mUntD9I9x-IPuL8uvYBgU7Y7kEfhFJUTkbaqdikxEGbV1IEHn2AJjXgc022sbvUD0LXrihi_7AO2YThyP4kL6VjECQxFQglUQGaHAqL-6I8q2aPwwvakpUYt4pjY1n3l4dHyqLPPebNGmQAQlprcAwGD-iesaqxcH8Oc2YeRBdG1VrHAzHBmExf02pcTI5VI2UMZdzs68Jpzs0_PCvzEpm8h2MMPqljyxaxSE1x4M5TkUGkr6TdizBAjRPsAtuJZ4gpQQPmRjBE3J-pJA5MGDwIkEVyYRQTBEUEAjc5hwARN7Mo0dG0wPvSek9YDC6UfZhYjyVyWGk6eteNETmEPWygLPYrFGvzXly5zp77z6cEA1iTD7qHQ_arMDRFMLcP2En--9ofwAYylYOB9GwX6myQAIXCwjMxR1D1IyQyzHjTNj9l8j-BLUgrdm6IW75vftUy7ZuQUuWJKLMZcjMJOGF3GnMwy40rUIDURdpABtUw60Z4a5WwGoO3Uht2WqWWJnhyplteda1tvCtadycB34ZYhM8tN157SfgoD3XoQR5W5fBzMdiVxMAUtr2YHmrW8IglKA6Kfid94ZAH4c39uv0VJWKwYM_CCJOIGKlGOIdhCgVPJ5azUzDp6HhFoomcwzvhn1mk23MghoKH9yG9EmfF2h1tI31NAi57I3MP5cvkYdQjcXi744zN4kvcBS0lXcxCaCAoMAbWe4-b8TkCN9lEyNo_sLDt_uvaB2BuOoMp7mwq0pIuMs_aVEq6HcwOdjtrC2w_aFkt6SpOu2t1r8QMzobvqAdvxoOY11b1Lgw3TS1SLOvFgJlIalEUknc8pcbVQ7QQza6QFC1ghrPiVwgq3jxkl06XAsZSXTKWtbtKVEHJYhH-5S4v19SoDMtI3nezgSJ3-DP7C5uIsstxp4UnLGrfM3q2Fvn41hdxINXOeut139nnwBMpFqnpMoNgiOqkG1kZ5qLoG1pT2Lf42YllMtOkli6Q-hDJKEBFtxeJdAbTkllpYBRBZPab3Z1JhhboOj6eUCDi-ib4kHt9LNa3UhFQ4j5FIpGTsD8wIt349a9rH_gP2rxrFw==");
        } catch (IOException e) {
            e.printStackTrace();
        }

        af.fingerprint(30, true);
    }

    @Override
    public void onDestroy() {
        af.stop();
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
        Log.i(tag, code);
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
