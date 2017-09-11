/*Lees de READ ME in main.ccp*/


#pragma once

#include <iostream>
using namespace std; 

#include "ofMain.h"
#include "Ball.h"
#define NBALLS 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		Ball myBall[NBALLS]; 

		
};
