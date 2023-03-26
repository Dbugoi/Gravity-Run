#pragma once

#include "GameObject.h"


class Obstaculo : public GameObject {
private:
	ofxBox2d *mundo;
	int altura;
public:

	Obstaculo::Obstaculo() {}

	Obstaculo::Obstaculo(ofxBox2d * world, int alt, ofColor col) {
		mundo = world;
		altura = alt;
		color = col;
	}
	void setup() override;
	void update() override;
};