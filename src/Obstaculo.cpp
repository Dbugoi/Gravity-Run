#include "Obstaculo.h"

void Obstaculo::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	//aux->setPhysics(0, 0, 0);
	aux->setup(mundo->getWorld(), x, y, longitud, altura);
	figure = aux;

	figure->body->GetFixtureList()->SetSensor(true);

}

void Obstaculo::update() {
	auto aux = figure->getPosition();
	aux.x--;
	figure->setPosition(aux);
}

int Obstaculo::checkCollision() {
	for (b2ContactEdge* edge = figure->body->GetContactList(); edge; edge = edge->next) {
		return 1;
	}
	return 0;
}