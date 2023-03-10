#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "GameObject.h"
#include "Jugador.h"

class Escenario {
private:
	ofxBox2d mundo;
	vector<GameObject> gameObjects;
	Jugador jugador;


public:
	Escenario::Escenario(){}

	Escenario::Escenario(int y, int altura, ofColor colorJugador) {
		mundo.init();
		mundo.setGravity(0, 10);
		mundo.createBounds(0, y, ofGetWidth(), ofGetHeight() / 2);
		//mundo.createGround();
		mundo.setFPS(60.0);
		jugador = Jugador(mundo, altura, colorJugador);
	}

	void setup();
	void update();
	void draw();
};