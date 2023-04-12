#include "Meta.h"

//Metodo que crea un rectangulo de ofbox2d y lo introduce al mundo en la posicion deseada
void Meta::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	aux->setup(mundo->getWorld(), x, y, longitud, altura);
	figure = aux;

	figure->body->GetFixtureList()->SetSensor(true);

}
//Metodo que actualiza la posicion del objeto restando la x para crear movimiento de derecha a izquierda
void Meta::update() {
	auto aux = figure->getPosition();
	aux.x -= 5; //TODO -10
	figure->setPosition(aux);
}

//Metodo que comprueba si hay alguna colision con el para devolver un 7 que indica fin de partida.
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

