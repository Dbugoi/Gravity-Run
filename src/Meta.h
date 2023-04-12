#pragma once

#include "GameObject.h"
#include <utility>


class Meta : public GameObject {
private:
	ofxBox2d *mundo;    //mundo ofbox2d 
	bool hasCollided = false;    //ha colisionado o no el jugador en contra suya
	int longitud;   //longitud figura
	int altura;		//altura figura
	
public:

	Meta::Meta() {}

	Meta::Meta(ofxBox2d * world, int pX, int pY) {
		mundo = world;
		longitud = 50;
		altura = ofGetHeight()/2-4;   //mitad de pantalla menos separador
		x = pX;
		y = pY+ altura/2;   //Posicionar la y en la mitad de la pantalla ya que se pinta desde el centro
		color = ofColor::gold;
	}
	void setup() override;
	void update() override;
	int checkCollision() override;

};