#pragma once


#include "ofMain.h"
#include "ofxBox2d.h"
#include "GameObject.h"
#include "Jugador.h"
#include "Obstaculo.h"


class Escenario {
private:
	ofxBox2d *mundo;
	vector<GameObject*> gameObjects;
	Jugador jugador;
	int y;
	//Obstaculo obs;



public:
	Escenario::Escenario(){}

	Escenario::Escenario(int pY, int altura, ofColor colorJugador) {
		y = pY;
		mundo = new ofxBox2d();
		mundo->init();
		mundo->setGravity(0, 10);
		mundo->createBounds(0, y, ofGetWidth(), ofGetHeight() / 2 - 4);
		//mundo.createGround();
		mundo->setFPS(60.0);
		jugador = Jugador(mundo, altura, colorJugador);

	}

	void setup();
	void update();
	void draw();
	void setGravity(int value);
};
