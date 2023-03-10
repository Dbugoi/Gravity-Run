#include "Escenario.h"

void Escenario :: setup() {
	jugador.setup();
}
void Escenario::update() {
	mundo.update();
}

void Escenario::draw() {
	jugador.draw();
}

