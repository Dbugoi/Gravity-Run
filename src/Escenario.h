#pragma once


#include "ofMain.h"
#include "ofxBox2d.h"
#include "GameObject.h"
#include "Jugador.h"
#include "Obstaculo.h"
#include "PowerUp.h"
#include "Meta.h"

class Escenario {
private:
	ofxBox2d *mundo;   //mundo ofbox2d 
	vector<GameObject*> gameObjects;  //vector de objetos 
	Jugador jugador;  //jugador
	int y;    //posicion y 
	vector<pair<vector<int>, ofColor>> listaObstaculos;
	bool hasCollided;
	bool hasFinished;
	int powerUpTime;
	int powerUpType;
	ofColor colorInicialJugador;



public:
	Escenario::Escenario(){}

	Escenario::Escenario(int gravity,  int pY, int altura, ofColor colorJugador, vector<pair<vector<int>, ofColor>> obst) {
		y = pY;
		listaObstaculos = obst;
		hasCollided = false;
		hasFinished = false;  // Si se ha llegado a la meta
		mundo = new ofxBox2d();
		mundo->init();
		mundo->enableEvents();
		mundo->setGravity(0, 20);
		mundo->createBounds(0, y, ofGetWidth(), ofGetHeight() / 2 - 4);
		//mundo->createGround();
		mundo->registerGrabbing();
		mundo->setFPS(60.0);
		jugador = Jugador(mundo, altura, colorJugador,pY);
		powerUpTime = 0;
		powerUpType = 0;
		colorInicialJugador = colorJugador;
		
	}

	void setup();
	void update();
	void draw();
	void setGravity(int value);
	bool getHasCollided();
	bool getHasFinished();
	int getPowerUpType();

};
