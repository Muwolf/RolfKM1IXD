#include "ofApp.h"

#define WIDTH 470
#define HEIGHT 350 


void ofApp::setup() {
	image.load("cat.jpg");

	plane.set(WIDTH, HEIGHT);
	plane.setResolution(50, 50);

	plane.mapTexCoordsFromTexture(image.getTexture());
}

void ofApp::update() {
	ofMesh& mesh = plane.getMesh();

	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 50; x++) {
			int index = x + 50*y;

			ofPoint vertex = mesh.getVertex(index); 
			vertex.z = ofNoise(x * 0.05, y*0.05, ofGetElapsedTimef()*0.5)*100;
			
			mesh.setVertex(index, vertex); 
		}
	}
}

void ofApp::draw() {
	ofBackground(0);
	cam.setVFlip(true);
	cam.begin();

	image.bind();
	plane.draw();
	image.unbind();

	cam.end();

}
