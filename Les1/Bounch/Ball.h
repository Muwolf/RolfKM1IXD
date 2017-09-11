
//#ifndef _BALL
//#define _BALL
#include "ofMain.h"

class Ball
{
public:

	void setup(float _x, float _y, int _radius);
	void update();
	void draw();

	float x; 
	float y; 
	float speedX;
	float speedY;
	int radius;
	ofColor color; 
	 
	Ball();

private:

};
//#endif

