#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"


class GameObject {
protected:
	int x, y;  //posicion objeto
	ofColor color;  //color objeto
	bool isAlive = true;  //esta vivo o no 
	shared_ptr<ofxBox2dBaseShape> figure;  //figura de ofbox2d 

public:

	virtual void setup() = 0;
	virtual void update() = 0;
	virtual int checkCollision() = 0;
	void draw();
};
