#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	grabber.setDeviceID(0);
	grabber.initGrabber(640, 480);
	grabber.setDesiredFrameRate(30); 

	sphere1.setRadius(200);
	sphere1.setPosition(100, -50, 100);
	sphere1.mapTexCoordsFromTexture(grabber.getTexture());

	sphere2.setRadius(250);
	sphere2.setPosition(-50, 100, 100);
	sphere2.mapTexCoordsFromTexture(grabber.getTexture());

	sphere3.setRadius(300);
	sphere3.setPosition(100, 100, -50);
	sphere3.mapTexCoordsFromTexture(grabber.getTexture());

	sphere4.setRadius(200);
	sphere4.setPosition(0, 0, 0);
	sphere4.mapTexCoordsFromTexture(grabber.getTexture());

	light.setDirectional();
	light.enable();
}

//--------------------------------------------------------------
void ofApp::update() {
	grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(ofColor::black);

	ofEnableDepthTest();
	cam.setVFlip(true);
	cam.begin();

	grabber.getTexture().bind();
	sphere1.draw();
	sphere2.draw();
	sphere3.draw();
	sphere4.draw();
	grabber.getTexture().unbind();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}