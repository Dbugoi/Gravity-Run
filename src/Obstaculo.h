#pragma once

#include "GameObject.h"
#include <utility>


class Obstaculo : public GameObject {
private:
	ofxBox2d *mundo;
	int longitud;
	int altura;
	int yBaseTriangulo;
	bool hasCollided = false;
	int tipo;
	bool isUp;
	
public:

	Obstaculo::Obstaculo() {}

	Obstaculo::Obstaculo(ofxBox2d * world, int pX, int pY, int longi, int alt, bool isUpObs, int tipoObs, ofColor col) {
		
		mundo = world;
		x = pX;
		tipo = tipoObs;
		isUp = isUpObs;
		if (tipo == 0) { //Rectangulo
			if (isUp)
				y = 0 + pY + alt / 2;
			else
				y = ofGetHeight() / 2 - 4 + pY - alt / 2;
		}
		else { //Triangulo
			if (isUp) {
				yBaseTriangulo = pY;
				y = 0 + pY + alt;
			}
				
			else {
				yBaseTriangulo = ofGetHeight() / 2 - 4 + pY;
				y = ofGetHeight() / 2 - 4 + pY - alt;
			}
				
		}
		
		longitud = longi;
		altura = alt;
		
		color = col;
		
	}
	void setup() override;
	void update() override;
	int checkCollision() override;
	
};