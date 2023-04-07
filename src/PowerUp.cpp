#include "PowerUp.h"

void PowerUp::setup() {
	auto aux = make_shared<ofxBox2dCircle>();
	aux->setup(mundo->getWorld(), x, y, 20);  //world, x, y, radio
	figure = aux;
	figure->body->GetFixtureList()->SetSensor(true);

}

void PowerUp::update() {
	auto aux = figure->getPosition();
	aux.x -= 5; //TODO -10
	figure->setPosition(aux);
}

int PowerUp::checkCollision() {
	if (isAlive) {
		for (b2ContactEdge* edge = figure->body->GetContactList(); edge; edge = edge->next) {
			if (edge->contact->IsTouching()) {
				isAlive = false;
				return tipo;
			}
		}
	}
	return 0;
}

/*
void PowerUp::draw() {
	cout << "Dibujo" << endl;
	//GameObject::draw();
}
*/