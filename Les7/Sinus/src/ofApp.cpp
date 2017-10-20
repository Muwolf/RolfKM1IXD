#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(20);

	soundStream.printDeviceList();
	soundStream.setDeviceID(0);
	soundStream.setup(this, 2, 0, 22500, 512, 4);

}

void ofApp::audioOut(float*output, int bufferSize, int nChannels) {
	for (int i = 0; i < bufferSize*nChannels; i += 2) {
		float sample = sin(phase *1.0008f); 
		sample = sin(phase); 
		output[i + 1] = sample; 
		step += 0.0001; 
		phase += step; 
	}
}