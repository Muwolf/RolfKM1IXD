#include "ofApp.h"

void ofApp::setup() {

	grabber.listDevices();
	grabber.setDeviceID(1);
	grabber.initGrabber(videoWidth, videoHeight);
	grabber.setDesiredFrameRate(30);

	workspace.allocate(videoWidth, videoHeight, ofImageType::OF_IMAGE_COLOR);
}

void ofApp::update() {

	grabber.update();


	if (grabber.isFrameNew()) {
		ofPixels& pixels = grabber.getPixels();
		for (int y = 0; y < pixels.getHeight(); y+scale) {
			for (int x = 0; x < pixels.getWidth(); x+scale) {
				ofColor c = pixels.getColor(x, (y*pixels.getWidth));
				float grey = (c.r + c.g + c.b) / 3;
				square.newSquare(x, y, grey, scale);
				squareList.push_back(square);

				//workspace.setColor(x, y, grey);
			}
		}
		//image.setFromPixels(workspace);
	}
}

void ofApp::draw() {
	ofBackground(0);
	for (int i = 0; i < squareList.size(); i++) {
		squareList[i].draw();
	}
	//image.draw(0, 0, videoWidth * scale, videoHeight * scale);
}

void ofApp::keyPressed(int key) {
	if (key == 'g') {
		drawGrabbedImage = !drawGrabbedImage;
	}
}