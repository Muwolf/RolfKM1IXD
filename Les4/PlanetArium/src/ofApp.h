#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "CelestialBody.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void spawnPlanets(float _x, float _y, float _z, float _speed, float _radius);

		float x; 
		float y; 
		float z;
		float speed; 
		float radius; 

		CelestialBody planet;
		vector<CelestialBody> planets;
		
		ofxPanel gui; 

		ofParameter<bool> drawGrid;
		ofParameter<bool> useLight; 

		ofLight light; 
		ofEasyCam cam; 
		
};
