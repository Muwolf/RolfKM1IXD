#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	float phase; 
	float step = 0.005;
	void audioOut(float*input, int bufferSize, int nChannels);
	ofSoundStream soundStream; 
};