#include "Square.h"

Square::Square() {
}

void Square::newSquare(int _x, int _y, int _scale) {
	x = _x;
	y = _y;
	color = 51;
	scale = _scale;
}

void Square::update(int _color) {
	color = _color; 
}

void Square::draw() {
	ofSetColor(color); 
	ofRect(x, y, scale, scale); 
}