#include "Obstaculo.h"

void Obstaculo::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	aux->setup(mundo->getWorld(), x, y, longitud, altura);
	figure = aux;

	figure->body->GetFixtureList()->SetSensor(true);

	/*
	auto triangle = std::make_shared<ofxBox2dPolygon>();

	triangle->addTriangle(ofDefaultVertexType(x,0,0),
		ofDefaultVertexType(x+longitud, 0, 0),
		ofDefaultVertexType(x, altura, 0));

	//triangle->setPhysics(1.0, 0.3, 0.3);

	triangle->create(mundo->getWorld());
	figure = triangle;
	figure->body->GetFixtureList()->SetSensor(true);*/
	
}

void Obstaculo::update() {
	auto aux = figure->getPosition();
	aux.x -= 5; //TODO -10
	figure->setPosition(aux);
}

int Obstaculo::checkCollision() {
	if (!hasCollided) {
		for (b2ContactEdge* edge = figure->body->GetContactList(); edge; edge = edge->next) {
			hasCollided = true;
			return 1;
		}
	}
	return 0;
}