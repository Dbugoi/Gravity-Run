#include "Jugador.h"

void Jugador::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	aux->setPhysics(3.0, 0, 0.1);
	aux->setup(mundo->getWorld(), 100, altura, 50, 50);
	figure = aux;
}

void Jugador::update() {
	
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
	if (toSmall) 
		aux->setup(mundo->getWorld(), 100, yChangeSize, 25, 25);
	else
		aux->setup(mundo->getWorld(), 100, yChangeSize, 50, 50);
	figure = aux;
}