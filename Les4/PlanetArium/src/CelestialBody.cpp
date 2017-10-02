#include "CelestialBody.h"
#include "ofApp.h"

CelestialBody::CelestialBody() {
	
};


void CelestialBody::newBody(float _x, float _y, float _z, float _speed, float _radius) {
	x = _x;
	y = _y; 
	z = _z; 
	xSpeed = _speed*-1;
	ySpeed = _speed;
	zSpeed = _speed*0.5;
	radius = _radius; 
	rotateX = 0; 
	rotateY = 0; 
	rotateZ = 0; 
}

void CelestialBody::update() {

	rotateX += xSpeed; 
	rotateY += ySpeed; 
	rotateZ += zSpeed; 

}

void CelestialBody::draw() {
	ofPushMatrix(); 
	ofRotateX(rotateX); 
	ofRotateZ(rotateZ);
	ofRotateY(rotateY); 
	ofSetColor(ofColor::white); 
	ofNoFill(); 
	ofDrawSphere(x, y, z, radius);  
	ofPopMatrix(); 
}