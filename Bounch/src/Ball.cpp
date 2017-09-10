#include "Ball.h"


void Ball::setup() {
	radius = ofRandom(5, 40);

	x = ofRandom(radius, ofGetWidth() - radius);
	y = ofRandom(radius, ofGetHeight() - radius); 

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



Ball::Ball()
{
}


