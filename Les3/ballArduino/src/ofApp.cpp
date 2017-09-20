#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Arduino Setup
	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM3");
	arduino.sendFirmwareVersionRequest(); 


	//Start value variables
	minSpeed = 0;
	maxSpeed = 10; 
	minSize = 10;
	maxSize = 200; 

	speedX = minSpeed; 
	speedY = minSpeed; 
	radius = minSize; 

	//Variables for difrent pins on the arduino board. This way you don't have to hardcode the pinnumbers. 
	pinAddButton = 7;
	pinPopButton = 8; 
	pinRadiusPot = 0; 
	pinSpeedXPot = 1; 
	pinSpeedYPot = 2;
	pinLightSensor = 3; 
}

//--------------------------------------------------------------
void ofApp::update() {

	arduino.update();

	//Update all balls in the vector
	for (int i = 0; i < ballList.size(); i++) {
		ballList[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//Draw all balls in the vector
	for (int i = 0; i < ballList.size(); i++) {
		ballList[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int& version) {

	//Look for arduino, and show firmware
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName() 
		<< arduino.getMajorFirmwareVersion() 
		<< arduino.getMinorFirmwareVersion() << endl;

	//Setup pins
	arduino.sendDigitalPinMode(pinAddButton, ARD_INPUT);
	arduino.sendDigitalPinMode(pinPopButton, ARD_INPUT);
	arduino.sendAnalogPinReporting(pinSpeedXPot, ARD_ANALOG);
	arduino.sendAnalogPinReporting(pinSpeedYPot, ARD_ANALOG);
	arduino.sendAnalogPinReporting(pinRadiusPot, ARD_ANALOG);
	arduino.sendAnalogPinReporting(pinLightSensor, ARD_ANALOG);

	//Setup listeners for the input on the arduinoboard
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged); 
}

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int& pin) {

	//Map the imput form the X podmeter to the SpeedX
	speedX = ofMap(arduino.getAnalog(pinSpeedXPot), 0, 1023, minSpeed, maxSpeed); 

	//Map the imput form the Y podmeter to the SpeedY
	speedY = ofMap(arduino.getAnalog(pinSpeedYPot), 0, 1023, minSpeed, maxSpeed);

	//Map the imput form the Radius podmeter to the Radius
	radius = ofMap(arduino.getAnalog(pinRadiusPot), 0, 1023, minSize, maxSize);

	//Map the color to the light sensor, more light means more red, and less blue. 
	color = ofColor(ofMap(arduino.getAnalog(pinLightSensor), 0, 1023, 0, 255),  //RED
					0,															//GREEN
					ofMap(arduino.getAnalog(pinLightSensor), 0, 1023, 255, 0));	//BLUE
}

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int& pin) {
	
	//if addbutton is pressed, add a ball to the vector
	if (arduino.getDigital(pinAddButton) == 1) {
		ball.newBall(speedX, speedY, radius, color);
		ballList.push_back(ball);
	}

	//if popbutton is pressed, remove the last ball from the vector
	if (arduino.getDigital(pinPopButton) == 1) {
		if (ballList.size() > 0) {
			ballList.pop_back();
		}
	}
}