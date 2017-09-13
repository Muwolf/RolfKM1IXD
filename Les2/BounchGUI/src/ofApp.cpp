#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup("instellingen", "settings.xml");

	gui.add(radius.set("Radius", 50 , 0, 150));
	gui.add(speedX.set("SpeedX", 0, -5, 5));
	gui.add(speedY.set("SpeedY", 0, -5, 5));
	gui.add(color.set("Color", ofColor::white, 0, 255));

}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < ballList.size(); i++) {
		ballList[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (guiKey) {
		gui.draw(); 
	}
	for (int i = 0; i < ballList.size(); i++) {
		ballList[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'g' && guiKey) {
		guiKey = false; 
	}
	else if (key == 'g' && !guiKey) {
		guiKey = true; 
	}

	if (key == ' ') {
		ball.newBall(speedX, speedY, radius, color);
		ballList.push_back(ball);
	}
}