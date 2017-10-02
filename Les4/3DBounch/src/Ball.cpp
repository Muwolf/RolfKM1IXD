#include "Ball.h"



Ball::Ball()
{
}

void Ball::newBall(float _xSpeed, float _ySpeed, float _zSpeed, float _radius, ofColor _color) {
	radius = _radius;
	
	x = 0;
	y = 0;
	z = 0;

	maxRange = 750-radius; 
	minRange = maxRange*-1; 

	xSpeed = _xSpeed; 
	ySpeed = _ySpeed; 
	zSpeed = _zSpeed;

	ofLog() << "New ball created with; Xspeed: " << xSpeed << " Yspeed: " << ySpeed << " Zspeed: " << zSpeed << endl; 

	color.set(_color);
}

void Ball::update() {
	x += xSpeed;
	y += ySpeed;
	z += zSpeed;

	if (x >= maxRange) {
		xSpeed *= -1; 
		x = maxRange;
	}
	else if (x <= minRange) {
		xSpeed *= -1; 
		x = minRange; 
	}

	if (y >= maxRange) {
		ySpeed *= -1;
		y = maxRange;
	}
	else if (y <= minRange) {
		ySpeed *= -1;
		y = minRange;
	}

	if (z >= maxRange) {
		zSpeed *= -1;
		z = maxRange;
	}
	else if (z <= minRange) {
		zSpeed *= -1;
		z = minRange;
	}

}

void Ball::draw() {
	ofSetColor(color);
	ofDrawSphere(x, y, z, radius);
}
