#include "ofApp.h"

void ofApp::setup(){
	numberOfBalls = 5; 
	for (int i = 0; i < numberOfBalls; i++) {

		radius = ofRandom(20, 50);

		x = ofRandom(0 + radius, ofGetWidth() - radius);
		y = ofRandom(0 + radius, ofGetHeight() - radius);

		speedX = ofRandom(-1, 1);
		speedY = ofRandom(-1, 1);

		colorR = ofRandom(50, 200);
		colorG = ofRandom(50, 200);
		colorB = ofRandom(50, 200);

		modR = ofRandom(-1, 1);
		modG = ofRandom(-1, 1);
		modB = ofRandom(-1, 1);


		//HIER LOOP IK VAST! Wat ik eigelijk wil is alle waardes die ik nu heb in een array zetten, 
		//zodat ik met een For loop door die array heen kan in zowel mn Update als mn Draw functie.
		//Maar ik kom er niet uit hoe ik een array maak in C++. 
	}
}

void ofApp::update() {



	//Move Ball
	x = x + speedX;
	y = y + speedY;

	if (x <= radius || x >= ofGetWidth() - radius) {
		speedX = -speedX;
		speedX *= 1, 1;
	}

	if (y <= radius || y >= ofGetHeight() - radius) {
		speedY = -speedY;
		speedY *= 1, 1;
	}

	//Color Change

	colorR += modR;
	colorG += modG;
	colorB += modB;

	if (colorR <= 50 || colorR >= 200) {
		modR *= -1;
	}
	if (colorG <= 50 || colorG >= 200) {
		modG *= -1;
	}
	if (colorB <= 50 || colorB >= 200) {
		modB *= -1;
	}
}



void ofApp::draw(){
	ofSetColor(colorR, colorG, colorB);
	ofDrawCircle(x, y, radius); 
}

void ofApp::keyPressed(int key){

}