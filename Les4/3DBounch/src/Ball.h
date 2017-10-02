#pragma once

#include "ofMain.h"
#define _BALL

class Ball
{
public:
	void newBall(float _xSpeed, float _ySpeed, float _zSpeed, float _radius, ofColor _color); 
	void update(); 
	void draw(); 


	float x;
	float y;
	float z; 
	float xSpeed; 
	float ySpeed;
	float zSpeed; 
	float radius;
	float maxRange; 
	float minRange; 
	ofColor color; 


	Ball();
	
};

