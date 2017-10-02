#pragma once

#include "ofMain.h"
#define _CELESTIALBODY

class CelestialBody
{
public: 
	void newBody(float _x, float _y, float _z, float _speed, float _radius);

	void update(); 
	void draw(); 

	float radius;
	float x;
	float y;
	float z; 
	float xSpeed; 
	float ySpeed; 
	float zSpeed; 
	float rotateX;
	float rotateY; 
	float rotateZ; 


	CelestialBody();

};

