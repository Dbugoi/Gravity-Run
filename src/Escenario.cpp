#include "Escenario.h"
#include <map>

void Escenario :: setup() {
	jugador.setup();
	int xPowerUp = 1000, xAux = 1000, powerType;
	ofColor obstColor;
	map<int, ofColor> powerUpColors = {
	{ 2, ofColor::green }, //Invertir controles
	{ 3, ofColor::chocolate }, //Bloquear pantalla rival
	{ 4, ofColor::purple}, //Bloquear ambas pantallas
	{ 5, ofColor::pink}, //Escudo
	{ 6, ofColor::black} //Hacerte pequeño
	};
	for (vector<int> listaObs : listaObstaculos) {
		xPowerUp = (listaObs[0]-(listaObs[1] / 2) - xAux)/2 + xAux;    
		//obstColor = powerUpColors[rand() % 5 + 2];
		gameObjects.push_back(new Obstaculo(mundo, listaObs[0], y, listaObs[1], listaObs[2], listaObs[3], listaObs[4],ofColor::brown));
		xAux = (listaObs[0] + listaObs[1]/2);		//x del objeto + longitud 
		if (rand() % 8 == 0) {
			powerType = rand() % 5 + 2;
			gameObjects.push_back(new PowerUp(mundo, xPowerUp,(rand() % (ofGetHeight()/2 - 50)) + 25 + y, powerUpColors[powerType], powerType));
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
		switch (gameObjects[i]->checkCollision()) {
			case 1:
				if (powerUpType != 5) {
					hasCollided = true; //TODO activar
				}
				else {
					powerUpType = 0;
					powerUpTime = 0;
					jugador.setColor(colorInicialJugador);
				}
				
				break;
			case 2:
				powerUpType = 2;
				powerUpTime = 180;
				break;
			case 3:
				powerUpType = 3;
				powerUpTime = 120;
				break;
			case 4:
				powerUpType = 4;
				powerUpTime = 250;
				break;
			case 5:
				powerUpType = 5;
				powerUpTime = 300;
				jugador.setColor(ofColor::lightGoldenRodYellow);
				break;
			case 6:
				if (powerUpType != 6) {
					jugador.changeSize(true);
					powerUpType = 6;
				}
				powerUpTime = 300;
				break;
			default:
				break;
		}
	}
	if (powerUpTime > 0)
		powerUpTime--;
	else if (powerUpTime == 0) {
		if (powerUpType == 5)
			jugador.setColor(colorInicialJugador);
		if (powerUpType == 6)
			jugador.changeSize(false);
		powerUpType = 0;
	}
		
}

void Escenario::draw() {
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->draw();
	jugador.draw();
}

void Escenario::setGravity(int value) {
		mundo->setGravityY(value);
}

bool Escenario::getHasCollided() {
	return hasCollided;
}

int Escenario::getPowerUpType() {
	return powerUpType;
}

