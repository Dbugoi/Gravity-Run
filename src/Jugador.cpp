#include "Jugador.h"

void Jugador::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	aux->setPhysics(3.0, 0, 0.1);
	aux->setup(mundo.getWorld(), 100, altura, 20, 20);
	figure = aux;
}