/*Lees de READ ME in main.ccp*/

#include "Ball.h"

Ball::Ball() {
};

void Ball::setup(float _x, float _y, int _radius) {
	x = _x;
	y = _y;
	radius = _radius;

	speedX = ofRandom(-5, 5);
	speedY = ofRandom(-5, 5);

	colorR = ofRandom(255); 
	colorG = ofRandom(255); 
	colorB = ofRandom(255); 

	modColorR = 1;
	modColorG = 1;
	modColorB = 1;

	color.set(colorR, colorG, colorB);
}

void Ball::update() {
	//Deze manier van speed om draaien zorgt er voor dat het in een ifstatment past. 
	if (x < radius || x > ofGetWidth() - radius) {
		speedX *= -1; 
	}
	if (y < radius || y > ofGetHeight() - radius) {
		speedY *= -1;
	}


	//Hier zouden de kleuren langzaam van moeten veranderen. Werkt nu niet. 
	if (colorR > 255 || colorR < 0) {
		modColorR *= -1; 
	}
	if (colorG > 255 || colorG < 0) {
		modColorG *= -1;
	}
	if (colorB > 255 || colorB < 0) {
		modColorB *= -1;
	}

	colorR += modColorR;
	colorG += modColorG;
	colorB += modColorB; 

	color.set(colorR, colorG, colorB);


	//Aanpassing positie
	x += speedX;
	y += speedY; 

}

void Ball::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, radius); 
}


