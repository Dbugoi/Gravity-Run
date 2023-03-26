#include "Escenario.h"

void Escenario :: setup() {
	jugador.setup();
	gameObjects.push_back(new Obstaculo(mundo, 500, y, 50, 100, true, ofColor::brown));
	gameObjects.push_back(new Obstaculo(mundo, 800, y, 200, 100, false, ofColor::forestGreen));
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->setup();
}
void Escenario::update() {
	mundo->update();
	jugador.update();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
		if (gameObjects[i]->checkCollision() == 1) {
			mundo->setGravityY(-500);
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

