#include "ofApp.h"

#define WIDTH 1000
#define HEIGHT 1000 
#define RESOLUTION 20
#define BOXSIZE 100
#define BALLSIZE 100

void ofApp::setup(){

	plane.set(WIDTH, HEIGHT);
	plane.setResolution(RESOLUTION, RESOLUTION);
	plane.setPosition(0, 0, 0);

	box.set(BOXSIZE); 
	box.setResolution(RESOLUTION, RESOLUTION, RESOLUTION); 
	box.setPosition(0, 0, 0); 

	ball.set(BALLSIZE, RESOLUTION);
	ball.setPosition(0, 0, 0); 
}

void ofApp::update(){
	ofMesh& planeMesh = plane.getMesh();

	for (int y = 0; y < RESOLUTION; y++) {
		for (int x = 0; x < RESOLUTION; x++) {
			int index = x + RESOLUTION * y;

			ofPoint vertex = planeMesh.getVertex(index);
			vertex.z = ofNoise(x * 0.05, y*0.05, ofGetElapsedTimef()*0.5) * 100;

			planeMesh.setVertex(index, vertex);
		}
	}

	box.rotate(1, 1, 0, 0);
	
	vector<ofMeshFace> triangles = box.getMesh().getUniqueFaces();

	float displacement = sin(ofGetElapsedTimef() * 4) * 10;
	for (size_t i = 0; i < triangles.size(); i += 2) {
		ofVec3f faceNormal = triangles[i].getFaceNormal();
		for (int j = 0; j < 3; j++) {
			triangles[i].setVertex(j, triangles[i].getVertex(j) + faceNormal * displacement);
		}
	}
	box.getMesh().setFromTriangles(triangles);

	ball.rotate(1, 0, 1, 0); 

}

void ofApp::draw(){

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	cam.setVFlip(true);
	ofBackground(0);
	cam.begin();
	//ofDrawGrid(200); 
	plane.drawWireframe(); 
	box.drawWireframe(); 
	ball.drawWireframe(); 
	cam.end(); 
}