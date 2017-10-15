#pragma once

#include "ofMain.h"

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

	float numberSquares = 1;
	float numberSpeed = 0;

	ofPlanePrimitive plane;
	float noise = 0.05;
	float maxNumberSquares = 1;

private:
	ofArduino arduino;
	void setupArduino(const int& version);
	void analogPinChanged(const int& pin);
	void digitalPinChanged(const int& pin);

	int const pinButtonAdd = 3;
	int const pinButtonPop = 4;
	int const pinAnalogNoise = 0;
	int const pinAnalogSpeed = 1;
};
