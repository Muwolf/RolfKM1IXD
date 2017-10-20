#include "ofApp.h"

void ofApp::setup() {
	for (int i = 0; i < 6; i++) {
		voicePlayer[i].load(ofToDataPath("vox" + ofToString(i + 1) + ".wav"));
		voicePlayer[i].setLoop(true);

		voicePlayer[i].play();
		playing[i] = true;
		voicePlayer[i].setPaused(playing[i]);
	}

	ofSoundSetVolume(0.2);
}

void ofApp::update() {
	ofSoundUpdate();
	float time = ofGetElapsedTimef();
	float x = time * 0.1f + 30;
	for (int i = 0; i < 6; i++) {
		float y = i*0.02f;
		float volume = ofNoise(x, y);
		voicePlayer[i].setVolume(volume);
	}
}

void ofApp::draw() {
	for (int i = 0; i < 6; i++) {
		ofSetColor(i * 20 + 128, i * 80, i * 10 + 60);
		ofDrawRectangle(200, i * 60 + 200, voicePlayer[i].getVolume() * 600, 10);
	}
}

void ofApp::keyPressed(int key) {
	if (key == '1' || key == 'z') {
		playing[0] = !playing[0];
		cout << "Voice 0 " << playing[0] << endl;
		voicePlayer[0].setPaused(playing[0]);
	}

	if (key == '2' || key == 'x') {
		playing[1] = !playing[1];
		cout << "Voice 0 " << playing[1] << endl;
		voicePlayer[1].setPaused(playing[1]);
	}

	if (key == '3' || key == 'c') {
		playing[2] = !playing[2];
		cout << "Voice 0 " << playing[2] << endl;
		voicePlayer[2].setPaused(playing[2]);
	}

	if (key == '4' || key == 'v') {
		playing[3] = !playing[3];
		cout << "Voice 0 " << playing[3] << endl;
		voicePlayer[3].setPaused(playing[3]);
	}

	if (key == '5' || key == 'b') {
		playing[4] = !playing[4];
		cout << "Voice 0 " << playing[4] << endl;
		voicePlayer[4].setPaused(playing[4]);
	}

	if (key == '6' || key == 'n') {
		playing[5] = !playing[5];
		cout << "Voice 0 " << playing[5] << endl;
		voicePlayer[5].setPaused(playing[5]);
	}
}