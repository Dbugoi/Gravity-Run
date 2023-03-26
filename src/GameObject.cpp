#include "GameObject.h"

void GameObject::draw() {
	ofFill();
	ofSetColor(color);
	figure->draw();
}

int GameObject::checkCollision() {
	return 0;
}