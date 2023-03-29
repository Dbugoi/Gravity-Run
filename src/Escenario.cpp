#include "Escenario.h"

void Escenario :: setup() {
	jugador.setup();
	for (vector<int> listaObs : listaObstaculos) {
		gameObjects.push_back(new Obstaculo(mundo, listaObs[0], y, listaObs[1], listaObs[2], listaObs[3], ofColor::brown));
	}
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->setup();
}
void Escenario::update() {
	mundo->update();
	jugador.update();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
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
	return getHasCollided;
}

