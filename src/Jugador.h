#pragma once
#include "GameObject.h"


class Jugador : public GameObject{
private:
	ofxBox2d mundo;
	public:

	Jugador::Jugador(ofxBox2d world) {
		mundo = world;
	}
	void setup() override;
};