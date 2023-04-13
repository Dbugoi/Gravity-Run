#include "GameObject.h"

//Metodo que pinta el gameobject si esta vivo segun los atributos guardados
void GameObject::draw() {
	if (isAlive) {
		int posXdraw = figure->getPosition().x;
		if (posXdraw <= ofGetWidth() + 100 && posXdraw > -100) { //Para que solo se dibujen los objetos de dentro de la pantalla y no consuman recursos los de fuera
			ofFill();
			ofSetColor(color);
			figure->draw();
		}
	}

}

//Metodo que devuelve que la colison obtenida es de tipo 0
int GameObject::checkCollision() {
	return 0;
}

