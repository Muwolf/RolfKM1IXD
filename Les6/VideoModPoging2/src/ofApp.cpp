#include "ofApp.h"
#define VIDEOWIDTH 640
#define VIDEOHEIGHT 480

//--------------------------------------------------------------
void ofApp::setup() {
	grabber.listDevices();
	grabber.setDeviceID(1);
	grabber.initGrabber(VIDEOWIDTH, VIDEOHEIGHT);
	grabber.setDesiredFrameRate(30);

	workspace.allocate(VIDEOWIDTH, VIDEOHEIGHT, ofImageType::OF_IMAGE_COLOR);

	plane.set(VIDEOWIDTH * 2.5, VIDEOHEIGHT * 2.5);
	plane.setResolution(50, 50);

	plane.mapTexCoordsFromTexture(grabber.getTexture());

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();
}

//--------------------------------------------------------------
void ofApp::update() {

	arduino.update();

	grabber.update();

	if (grabber.isFrameNew()) {
		ofPixels& pixels = grabber.getPixels();
		for (int y = 0; y < pixels.getHeight(); y++) {
			for (int x = 0; x < pixels.getWidth(); x++) {

				ofColor c = pixels.getColor(x, y);

				int otherX = x * numberSquares;
				int otherY = y * numberSquares;

				numberSquares += numberSpeed;

				if (numberSquares >= maxNumberSquares) {
					numberSquares = maxNumberSquares;
					numberSpeed += -1;
				}
				else if (numberSquares <= 1)
				{
					numberSquares = 1;
					numberSpeed *= -1;
				}

				if (otherX > pixels.getWidth()) otherX %= pixels.getWidth();

				if (otherY > pixels.getHeight()) otherY %= pixels.getHeight();

				ofColor otherColor = pixels.getColor(otherX, otherY);


				workspace.setColor(x, y, otherColor);
			}
		}
		image.setFromPixels(workspace);
		image.mirror(false, true);
	}

	ofMesh& mesh = plane.getMesh();

	for (int meshY = 0; meshY < 50; meshY++) {
		for (int meshX = 0; meshX < 50; meshX++) {
			int index = meshX + 50 * meshY;

			ofPoint vertex = mesh.getVertex(index);
			vertex.z = ofNoise(meshX * noise, meshY * noise, ofGetElapsedTimef()*0.5) * 100;

			mesh.setVertex(index, vertex);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofBackground(0);

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	image.bind();
	plane.draw();
	image.unbind();
	ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);

	if (drawGrabbedImage) {
		grabber.draw(VIDEOWIDTH, VIDEOHEIGHT);
	}
}

void ofApp::keyPressed(int key) {
	if (key == 'g') {
		drawGrabbedImage = !drawGrabbedImage;
	}
}

void ofApp::setupArduino(const int& version) {
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName()
		<< arduino.getMajorFirmwareVersion()
		<< arduino.getMinorFirmwareVersion() << endl;

	//Setup pins
	arduino.sendDigitalPinMode(pinButtonAdd, ARD_INPUT);
	arduino.sendDigitalPinMode(pinButtonPop, ARD_INPUT);
	arduino.sendAnalogPinReporting(pinAnalogNoise, ARD_ANALOG);
	arduino.sendAnalogPinReporting(pinAnalogSpeed, ARD_ANALOG);

	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}

void ofApp::analogPinChanged(const int& pin) {
	noise = ofMap(arduino.getAnalog(pinAnalogNoise), 50, 1000, 0, 0.1);
	numberSpeed = ofMap(arduino.getAnalog(pinAnalogSpeed), 100, 1000, 0, 0.001);
	if (numberSpeed < 0) numberSpeed = 0;
	if (noise < 0) noise = 0;
}

void ofApp::digitalPinChanged(const int& pin) {

	if (arduino.getDigital(pinButtonAdd) == 1) maxNumberSquares++;
	if (arduino.getDigital(pinButtonPop) == 1) maxNumberSquares--;
	if (maxNumberSquares > 10) maxNumberSquares = 10;
	if (maxNumberSquares < 1) maxNumberSquares = 1;
}
