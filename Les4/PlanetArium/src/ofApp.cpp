#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0); 
	ofSetFrameRate(60); 

	gui.setup();
	gui.add(drawGrid.set("GRID", false));
	gui.add(useLight.set("LIGHT", true)); 

	light.setDirectional();
	light.setPosition(-1000, -1000, -1000); 
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.enable(); 

	x = 0;
	y = 0; 
	z = 0; 
	speed = 1;
	radius = 100; 
	
	spawnPlanets(x, y, z, speed, radius); 
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < planets.size(); i++) {
		planets[i].update(); 
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	ofEnableDepthTest(); 
	cam.begin(); 


	for (int i = 0; i < planets.size(); i++) {
		planets[i].draw();
	}
	

	if (drawGrid) ofDrawGrid(200);

	if (useLight) {
		ofEnableLighting();
	}
	else {
		ofDisableLighting();
	}

	cam.end();

	
}


void ofApp::spawnPlanets(float _x,float _y,float _z, float _speed, float _radius) {

	planet.newBody(_x, _y, _z, _speed, _radius);
	planets.push_back(planet);
	
	if (_radius > 25) {
		spawnPlanets(_x - _radius * 2, _y - _radius * 2, _z - _radius * 2, _speed*-0.9, _radius / 2);
		spawnPlanets(_x - _radius * 2, _y + _radius * 2, _z - _radius * 2, _speed*1.1, _radius / 2);
		spawnPlanets(_x - _radius * 2, _y + _radius * 2, _z + _radius * 2, _speed*-0.8, _radius / 2);
		spawnPlanets(_x + _radius * 2, _y + _radius * 2, _z + _radius * 2, _speed*1.2, _radius / 2);
		spawnPlanets(_x + _radius * 2, _y - _radius * 2, _z + _radius * 2, _speed*-0.7, _radius / 2);
		spawnPlanets(_x + _radius * 2, _y - _radius * 2, _z - _radius * 2, _speed*1.3, _radius / 2);
		ofLog() << planets.size() << endl; 
	};
	}
	

