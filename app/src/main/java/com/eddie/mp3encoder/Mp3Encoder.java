package com.eddie.mp3encoder;

public class Mp3Encoder {
    public native int init(String pcmPath, int audioChannels, int bitRate, int sampleRate, String mp3Path);
    public native void encode();
    public native void destroy();
}
