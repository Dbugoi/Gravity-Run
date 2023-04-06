#include "GameObject.h"

void GameObject::draw() {
	if (isAlive) {
		int posXdraw = figure->getPosition().x;
		if (posXdraw <= ofGetWidth() + 100 && posXdraw > -100) {
			ofFill();
			ofSetColor(color);
			figure->draw();
		}
	}

}

int GameObject::checkCollision() {
	return 0;
}

