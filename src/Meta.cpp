#include "Meta.h"

void Meta::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	aux->setup(mundo->getWorld(), x, y, longitud, altura);
	figure = aux;

	figure->body->GetFixtureList()->SetSensor(true);

}

void Meta::update() {
	auto aux = figure->getPosition();
	aux.x -= 5; //TODO -10
	figure->setPosition(aux);
}

int Meta::checkCollision() {
	if (!hasCollided) {
		for (b2ContactEdge* edge = figure->body->GetContactList(); edge; edge = edge->next) {
			if (edge->contact->IsTouching()) {
				hasCollided = true;
				return 7;
			}
		}

	}
	return 0;
}

