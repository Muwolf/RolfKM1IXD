#pragma once

#include "ofMain.h"
#include "Square.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	ofVideoGrabber grabber;
	ofImage image;
	ofPixels workspace;

	bool drawGrabbedImage;

	int const videoWidth = 150;
	int const videoHeight = 100;
	int const scale = 10;

	vector<Square> squareList;

	Square square; 

};
