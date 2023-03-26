#include "Obstaculo.h"

void Obstaculo::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	//aux->setPhysics(0, 0, 0);
	aux->setup(mundo->getWorld(), 500, altura, 50, 100);
	figure = aux;
}

void Obstaculo::update() {
	auto aux = figure->getPosition();
	aux.x--;
	figure->setPosition(aux);
}