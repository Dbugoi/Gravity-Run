#pragma once
#include "GameObject.h"


class Jugador : public GameObject{
private:
	ofxBox2d *mundo;
	int altura;
	float mitadTamJugador; 
	int desfaseY;
	public:

	Jugador::Jugador() {}

	Jugador::Jugador(ofxBox2d * world, int alt, ofColor col,int pY) {
		mundo = world;
		altura = alt;
		color = col;
		desfaseY = pY;
	}
	void setup() override;
	void update() override;
	int checkCollision() override;
	void setColor(ofColor col);
	void changeSize(bool toSmall);

};