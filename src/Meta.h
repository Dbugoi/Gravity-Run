#pragma once

#include "GameObject.h"
#include <utility>


class Meta : public GameObject {
private:
	ofxBox2d *mundo;
	bool hasCollided = false;
	int longitud;
	int altura;
	
public:

	Meta::Meta() {}

	Meta::Meta(ofxBox2d * world, int pX, int pY) {
		mundo = world;
		longitud = 50;
		altura = ofGetHeight()/2-4;
		x = pX;
		y = pY+ altura/2;
		color = ofColor::gold;
	}
	void setup() override;
	void update() override;
	int checkCollision() override;

};