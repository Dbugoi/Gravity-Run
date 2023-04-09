#include "Jugador.h"

void Jugador::setup() {
	auto aux = make_shared<ofxBox2dRect>();
	aux->setPhysics(3.0, 0, 0.1);
	aux->setup(mundo->getWorld(), 100, altura, 50, 50);
	figure = aux;
	mitadTamJugador = 25;
}

void Jugador::update() {
	//Formula para que evite colisionar con el suelo y reconozca colision con objetos
	if ((figure->getPosition().y + mitadTamJugador >= altura +3) && isGravityDown) { //Hace que la gravedad del mundo sea 0 si el jugador esta tocando el suelo. Esto se debe a que si toca al tocar el suelo la gravedad es positiva (o negativa al tocar el techo), el jugador 
		//figure->setVelocity(0,0);													 //atraviesa los obstaculos porque hemos desactivado las colisiones con ellos, aunque si detectamos solapamiento.
		mundo->setGravityY(0);														 // isGravityDown indica si la gravedad del mundo era positiva o negativa. Esto sirve para no poner a 0 la gravedad cuando un jugador toca el suelo con gravedad negativa (o el techo con gravedad positiva). 
	}																				 // Si no tenemos en cuenta esto ultimo, el jugador se quedara pegado al suelo o techo aunque la gravedad fuese al contrario.
	if ((figure->getPosition().y - mitadTamJugador <=  desfaseY+1) && !isGravityDown) {
		mundo->setGravityY(0);
	}
}

int Jugador::checkCollision() {
	return 0;
}

void Jugador::setColor(ofColor col) {
	color = col;
}

void Jugador::changeSize(bool toSmall) {
	int yChangeSize = figure->getPosition().y;
	auto aux = make_shared<ofxBox2dRect>();
	aux->setPhysics(3.0, 0, 0.1);
	if (toSmall) {
		aux->setup(mundo->getWorld(), 100, yChangeSize, 25, 25);
		mitadTamJugador = 12.5;
	}
	else {
		aux->setup(mundo->getWorld(), 100, yChangeSize, 50, 50);
		mitadTamJugador = 25;
	}
	figure = aux;
}

void Jugador::setIsGravityDown(bool value) {
	isGravityDown = value;
}