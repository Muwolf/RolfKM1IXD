#include "ofApp.h"
#include "Ball.h"

void ofApp::setup(){
	for (int i = 0; i<NBALLS; i++) {
		int size = (i + 1) * 10; 
		float randomX = ofRandom(size, ofGetWidth() - size);
		float randomY = ofRandom(size, ofGetHeight() - size);
		myBall[i].setup(randomX, randomY, size); 
	}
}

void ofApp::update(){
	for (int i = 0; i<NBALLS; i++) {
		myBall[i].update();
	}
}

void ofApp::draw(){
	for (int i = 0; i<NBALLS; i++) {
		myBall[i].draw();
	}
}

void ofApp::keyPressed(int key){

}