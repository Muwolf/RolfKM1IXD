#include "Ball.h"

Ball::Ball() {
};

void Ball::newBall(float _speedX, float _speedY, float _radius, ofColor _color) {
	radius = _radius;
	
	x = ofRandom(radius, ofGetWidth() - radius); 
	y = ofRandom(radius, ofGetHeight() - radius);
	
	speedX = _speedX + ofRandom(-0.5, 0.5);
	speedY = _speedY + ofRandom(-0.5, 0.5);

	color.set(_color);
}

void Ball::update() {
	if (x < radius || x > ofGetWidth() - radius) {
		speedX *= -1; 

	}

	if (y < radius || y > ofGetHeight() - radius) {
		speedY *= -1;
	}
	
	x += speedX;
	y += speedY; 
}

void Ball::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, radius); 
}


