/*Lees de READ ME in main.ccp*/


#include "ofApp.h"
#include "Ball.h"


void ofApp::setup(){
	for (int i = 0; i < NBALLS; i++) {
		int size = ofRandom(60, 80);
		float randomX = ofRandom(size, ofGetWidth() - size);
		float randomY = ofRandom(size, ofGetHeight() - size);
		myBall[i].setup(randomX, randomY, size); 
	}
}

void ofApp::update(){

	/* hier onder volgt een code die bedoelt is om ronde ballen van elkaar te laten stuiteren, 
	ik weet niet of ik hier de mist in ga met mn eigen logica, of dat ik het verkeert gecodeerd heb.*/
		
	//Voor elke ball in mijn array
	for (int i = 0; i < NBALLS; i++) {	
		
	//volg het volgende script uit voor elke ball die eerder in het array staat. 
	//Ik doe dit met zo'n dubbele forloop zodat hij niet 2 keer dezelfde controlle uitvoerd. 		
		for (int j = 0; j < i; j++) {		

	//Pak de X, Y en radius waarde van de huidige ball (de I forloop), en van de ball eerder uit de lijst (de J forloop)
			int myX = myBall[i].x;
			int myY = myBall[i].y;
			int otherX = (myBall[j].x);
			int otherY = myBall[j].y;
			int myR = myBall[i].radius;
			int otherR = myBall[j].radius; 

	/*
	Ik teken een denkbeeldige driehoek tussen de centers van mijn ballen, met 3 zeides, A, B en C.
	A = mijn X postitie, minus de andere X positie = de lengte van de liggende zijde van de driehoek
	B = mijn Y postitie, minus de andere Y positie = de lengte van de staande zijde van de driehoek
	C = De afstand die ik wil checken. 
	Dus A^2 + B^2 = C^2 
	*/
			float distance = (myX-otherX)^2+(myY-otherY)^2;
			distance = sqrt(distance); 

	// Als distance korter is dan de som van de radius van bijde bollen dan zijn de bollen dus tegen of overelkaar.

			if (myR + otherR < distance) {

	// En verander ik de richting van bijde bollen. 
				myBall[i].speedX *= -1;
				myBall[i].speedY *= -1; 
				myBall[j].speedX *= -1;
				myBall[j].speedY *= -1;
			}
		}
	}


	for (int i = 0; i < NBALLS; i++) {
		myBall[i].update();
	}
}

void ofApp::draw(){
	for (int i = 0; i < NBALLS; i++) {
		myBall[i].draw();
	}
}

