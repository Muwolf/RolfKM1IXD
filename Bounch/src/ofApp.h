#pragma once

#include <iostream>
using namespace std; 

#include "ofMain.h"
#include "Ball.h"
#define NBALLS 5

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
		Ball myBall[NBALLS]; 
};
