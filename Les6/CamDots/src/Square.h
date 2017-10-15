#pragma once
#include "ofMain.h"
#define _SQUARE

class Square
{
public:
	void newSquare(int _x, int _y, int _scale);

	void update();
	void draw();
	void update(int _color); 

	int x;
	int y;
	float color;
	int scale; 

	Square();
};

