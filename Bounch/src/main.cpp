/*
=======
READ ME
=======

Goed, first things first.
Mn code doet niet wat ik wil dat hij doet.
Als het goed is zou je X ballen moeten zien (NBALLS)
Die verschillende grote en snelheid hebben,
en die allemaal langzaam van kleur zouden moeten veranderen.
Dat laatste doen ze niet, en ik krijg niet uit gevogeld waarom niet.

Ten tweede is er een stukje in de ofApp.cpp file wat er voor moet zorgen
dat 2 ballen die tegen elkaar botsen om zouden moeten draaien, ook dit gebeurt niet.

Daarnaast ben ik nog even bezig geweest met std::Vectoren om 
meerdere ballen toe te kunnen voegen of weg te kunnen halen, maar dit is ook niet gelukt.*/

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1980, 1080 ,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
