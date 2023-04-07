#pragma once

#include "GameObject.h"


class Obstaculo : public GameObject {
private:
	ofxBox2d *mundo;
	int longitud;
	int altura;
	bool hasCollided = false;
	int tipo;
	
public:

	Obstaculo::Obstaculo() {}

	Obstaculo::Obstaculo(ofxBox2d * world, int pX, int pY, int longi, int alt, bool isUp, int tipoObs, ofColor col) {
		
		mundo = world;
		x = pX;
		if(isUp)
			y = 0 + pY + alt/2;
		else
			y = ofGetHeight() / 2 - 4 + pY - alt / 2;
		longitud = longi;
		altura = alt;
		tipo = tipoObs;
		color = col;
	}
	void setup() override;
	void update() override;
	int checkCollision() override;
	
};