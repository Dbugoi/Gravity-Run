#include "Escenario.h"

void Escenario :: setup() {
	jugador.setup();
	int xPowerUp = 1000, xAux = 1000;
	for (vector<int> listaObs : listaObstaculos) {
		xPowerUp = (listaObs[0]-(listaObs[1] / 2) - xAux)/2 + xAux;    
		gameObjects.push_back(new Obstaculo(mundo, listaObs[0], y, listaObs[1], listaObs[2], listaObs[3], ofColor::brown));
		xAux = (listaObs[0] + listaObs[1]/2);		//x del objeto + longitud 
		if (rand() % 2 == 0) {
			gameObjects.push_back(new PowerUp(mundo, xPowerUp,(rand() % (ofGetHeight()/2 - 50)) + 25 + y, ofColor::green, 2));
		}
		
	}
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->setup();
}
void Escenario::update() {
	mundo->update();
	jugador.update();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
		//Ha colisionado con un obstaculo
		if (gameObjects[i]->checkCollision() == 1) {
			hasCollided = true;
		}
	}	
}

void Escenario::draw() {
	jugador.draw();
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->draw();
}

void Escenario::setGravity(int value) {
		mundo->setGravityY(value);
}

bool Escenario::getHasCollided() {
	return hasCollided;
}

