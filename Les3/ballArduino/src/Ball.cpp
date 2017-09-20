#include "Ball.h"

Ball::Ball() {
};


//Function for new ball
void Ball::newBall(float _speedX, float _speedY, float _radius, ofColor _color) {
	radius = _radius;

	x = ofRandom(radius, ofGetWidth() - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	speedX = _speedX;
	speedY = _speedY;

	color.set(_color);
}


void Ball::update() {

	//Controller for the ball so it doesn't go outside the window;
	if (x < radius || x > ofGetWidth() - radius) {
		speedX *= -1;
	}
	if (y < radius || y > ofGetHeight() - radius) {
		speedY *= -1;
	}

	//Move the balls
	x += speedX;
	y += speedY;
}

void Ball::draw() {
	//draw ball in the set color.
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}


