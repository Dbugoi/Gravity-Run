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
	
	Escenario::Escenario(int y) {
		mundo.init();
		mundo.setGravity(0, 10);
		mundo.createBounds(0, y, ofGetWidth(), ofGetHeight() / 2);
		mundo.setFPS(60.0);
	}

	void setup();
	void update();
	void draw();
