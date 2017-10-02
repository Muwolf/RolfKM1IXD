#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		vector<Ball> ballList;
		Ball ball;
		float speedX;
		float speedY;
		float speedZ; 
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
		int pinSpeedZPot; 
		int pinLightSensor;


		ofLight light;
		ofEasyCam cam;


		//Arduino functions
	private:
		ofArduino arduino;
		void setupArduino(const int& version);
		void analogPinChanged(const int& pin);
		void digitalPinChanged(const int& pin);

		
};
