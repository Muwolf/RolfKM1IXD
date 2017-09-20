#pragma once

#define _BALL
#include "ofMain.h"

class Ball
{
public:

	void newBall(float _speedX, float _speedY, float _radius, ofColor _color);
	void update();
	void draw();

	float x;
	float y;
	float speedX;
	float speedY;
	float radius;
	ofColor color;

	Ball();

private:

};

