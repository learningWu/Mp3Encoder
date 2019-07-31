//
// Created by dzj on 2019-07-30.
//

#ifndef MP3ENCODER_MP3ENCODER_H
#define MP3ENCODER_MP3ENCODER_H

#include "lame/lame.h"

class Mp3Encoder {
private:
	FILE* pcmFile;
	FILE* mp3File;
	lame_t lameClient;

public:
	Mp3Encoder();
	~Mp3Encoder();

	int Init(const char* pcmFilePath, const char *mp3FilePath, int sampleRate, int channels, int bitRate);
	void Encode();
	void Destory();
};

#endif //MP3ENCODER_MP3ENCODER_H
