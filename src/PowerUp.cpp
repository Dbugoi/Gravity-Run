#include "PowerUp.h"

//Metodo que crea un circulo de ofbox2d y lo introduce al mundo en la posicion deseada
void PowerUp::setup() {
	auto aux = make_shared<ofxBox2dCircle>();
	aux->setup(mundo->getWorld(), x, y, 23);  //(world, x, y, radio)
	figure = aux;
	figure->body->GetFixtureList()->SetSensor(true);

}
 //Metodo que actualiza la posicion del objeto restando la x para crear movimiento de derecha a izquierda
void PowerUp::update() {
	auto aux = figure->getPosition();
	aux.x -= speed; //TODO -10
	figure->setPosition(aux);
}

//Metodo que comprueba si hay colision con algun objeto para pintarlo o no y devolver el tipo de powerup que era
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
