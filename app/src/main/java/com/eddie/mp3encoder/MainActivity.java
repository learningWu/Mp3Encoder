package com.eddie.mp3encoder;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    private final String TAG = "wzx";

    static {
        System.loadLibrary("audioencoder");
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        findViewById(R.id.tv_encode).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Mp3Encoder encoder = new Mp3Encoder();
                String pcmPath = Environment.getExternalStorageDirectory().getPath() + "/musicvideo/background1.pcm";
                int audioChannels = 2;
                int bitRate = 128 * 1024;
                int sampleRate = 44100;
                String mp3Path = Environment.getExternalStorageDirectory().getPath() + "/musicvideo/background1.mp3";
                int ret = encoder.init(pcmPath, audioChannels, bitRate, sampleRate, mp3Path);
                if (ret >= 0) {
                    encoder.encode();
                    encoder.destroy();
                    Log.i(TAG, "Encode Mp3 Success");
                } else {
                    Log.i(TAG, "Encoder Initialized Failed...");
                }
            }
        });
    }
}
