#pragma once

#include "GameObject.h"

class PowerUp : public GameObject {
private:
	ofxBox2d *mundo;
	int tipo;  // 2:blladaa ; 3: ads
public:

	PowerUp::PowerUp() {}

	PowerUp::PowerUp(ofxBox2d * world, int pX, int pY, ofColor col, int tipoObstaculo) {
		mundo = world;
		x = pX;
		y = pY;
		color = col;
		tipo = tipoObstaculo;
	}
	void setup() override;
	void update() override;
	int checkCollision() override;
	//void draw();
	
};