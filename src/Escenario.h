#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "GameObject.h"
#include "Jugador.h"
#include "Obstaculo.h"

class Escenario {
private:
	ofxBox2d *mundo;
	vector<GameObject> gameObjects;
	Jugador jugador;
	Obstaculo obs;



public:
	Escenario::Escenario(){}

	Escenario::Escenario(int y, int altura, ofColor colorJugador) {
		mundo = new ofxBox2d();
		mundo->init();
		mundo->setGravity(0, 10);
		mundo->createBounds(0, y, ofGetWidth(), ofGetHeight() / 2 - 4);
		//mundo.createGround();
		mundo->setFPS(60.0);
		jugador = Jugador(mundo, altura, colorJugador);
		obs = Obstaculo(mundo, (ofGetHeight() / 2 - 54) + y, ofColor::brown);
	}

	void setup();
	void update();
	void draw();
	void setGravity(int value);
};