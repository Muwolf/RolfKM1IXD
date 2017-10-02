#include "ofApp.h"

void ofApp::setup(){
	ofSetFrameRate(30); 
	ofBackground(51); 
}

void ofApp::update(){
	rotateX += 1; 
	rotateY += 2;
	rotateZ += 3; 
}

void ofApp::draw(){
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	if (rotate) {
		ofRotateX(rotateX);
		ofRotateY(rotateY);
		ofRotateZ(rotateZ);
	}

	if (drawGrid) {		
		ofDrawGrid(200);
	}

	ofNoFill(); 
	ofSetColor(ofColor::mediumVioletRed); 
	ofDrawSphere(100, 100, 100, 200);

}

void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGrid = !drawGrid;
	}

	if (key == ' ') {
		rotate = !rotate; 
	}
}