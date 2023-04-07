#include "Jugador.h"

void Jugador::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	aux->setPhysics(3.0, 0, 0.1);
	aux->setup(mundo->getWorld(), 100, altura, 50, 50);
	figure = aux;
	mitadTamJugador = 25;
}

void Jugador::update() {
	//Formula para que evite colisionar con el suelo y reconozca colision con objetos
	if (figure->getPosition().y + mitadTamJugador >= altura +3 ) {
		//figure->setVelocity(0,0);
		mundo->setGravityY(0);
	}
	if (figure->getPosition().y - mitadTamJugador <=  desfaseY+1) {
		mundo->setGravityY(0);
	}
}

int Jugador::checkCollision() {
	return 0;
}

void Jugador::setColor(ofColor col) {
	color = col;
}

void Jugador::changeSize(bool toSmall) {
	int yChangeSize = figure->getPosition().y;
	auto aux = make_shared<ofxBox2dRect>();
	aux->setPhysics(3.0, 0, 0.1);
	if (toSmall) {
		aux->setup(mundo->getWorld(), 100, yChangeSize, 25, 25);
		mitadTamJugador = 12.5;
	}
	else {
		aux->setup(mundo->getWorld(), 100, yChangeSize, 50, 50);
		mitadTamJugador = 25;
	}
	figure = aux;
}