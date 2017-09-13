#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		
		ofxPanel gui;
		ofParameter<int> radius; 
		ofParameter<float> speedX;
		ofParameter<float> speedY; 
		ofParameter<ofColor> color; 
		bool guiKey; 

		vector<Ball> ballList;

		Ball ball;
		
};
