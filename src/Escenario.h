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
	vector<vector<int>> listaObstaculos;
	bool hasCollided;



public:
	Escenario::Escenario(){}

	Escenario::Escenario(int gravity,  int pY, int altura, ofColor colorJugador, vector<vector<int>> obst) {
		y = pY;
		listaObstaculos = obst;
		hasCollided = false;
		mundo = new ofxBox2d();
		mundo->init();
		mundo->setGravity(0, 20);
		mundo->createBounds(0, y, ofGetWidth(), ofGetHeight() / 2 - 4);
		//mundo.createGround();
		mundo->setFPS(60.0);
		jugador = Jugador(mundo, altura, colorJugador);

	}

	void setup();
	void update();
	void draw();
	void setGravity(int value);
	bool getHasCollided();
};
