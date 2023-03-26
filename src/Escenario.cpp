#include "Escenario.h"

void Escenario :: setup() {
	jugador.setup();
	obs.setup();
}
void Escenario::update() {
	mundo->update();
	obs.update();
}

void Escenario::draw() {
	jugador.draw();
	obs.draw();
}

void Escenario::setGravity(int value) {
		mundo->setGravityY(value);
}

