#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"


class GameObject {
protected:
	int x, y;
	ofColor color;
	bool isAlive = true;
	shared_ptr<ofxBox2dBaseShape> figure;

public:

	virtual void setup() = 0;
	virtual void update() = 0;
	virtual int checkCollision() = 0;
	void draw();
};
