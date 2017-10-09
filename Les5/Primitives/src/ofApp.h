#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofPlanePrimitive plane;
		ofBoxPrimitive box; 
		ofSpherePrimitive ball; 

		ofEasyCam cam; 
};
