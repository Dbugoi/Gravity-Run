#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"


class GameObject {
protected:
	int x, y;
	shared_ptr<ofxBox2dBaseShape> figure;

public:
	virtual void setup();
	void update();
	void draw();
};
