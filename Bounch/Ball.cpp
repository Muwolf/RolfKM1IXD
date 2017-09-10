#include "Ball.h"

Ball::Ball() {
};

void Ball::setup(float _x, float _y, int _radius) {
	x = _x;
	y = _y;
	radius = _radius;

	speedX = ofRandom(-1, 1);
	speedY = ofRandom(-1, 1);

	color.set(ofRandom(255), ofRandom(255), ofRandom(255));
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


