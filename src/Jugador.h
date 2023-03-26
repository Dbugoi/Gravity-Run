#pragma once
#include "GameObject.h"


class Jugador : public GameObject{
private:
	ofxBox2d *mundo;
	int altura;
	public:

	Jugador::Jugador() {}

	Jugador::Jugador(ofxBox2d * world, int alt, ofColor col) {
		mundo = world;
		altura = alt;
		color = col;
	}
	void setup() override;
	void update() override;
};