#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();


		//All the variables needed for the balls
		vector<Ball> ballList;
		Ball ball;
		float speedX; 
		float speedY; 
		float radius; 
		ofColor color;
		float minSpeed;
		float maxSpeed;
		float minSize;
		float maxSize; 


		//Variables for the arduino pins. This way they're not hardcoded, and can be easly changed in the future. 
		int pinAddButton;
		int pinPopButton;
		int pinRadiusPot;
		int pinSpeedXPot;
		int pinSpeedYPot;
		int pinLightSensor; 


		//Arduino functions
	private:
		ofArduino arduino; 
		void setupArduino(const int& version);
		void analogPinChanged(const int& pin);
		void digitalPinChanged(const int& pin);
		
};
