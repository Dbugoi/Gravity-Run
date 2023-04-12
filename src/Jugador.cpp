#include "Jugador.h"

//Metodo que crea un cuadrado jugador en funcion de atributos  y lo introduce al mundo
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

//Metodo que comprueba si algo colisiona con el.// Siempre 0 ya que lo comprobamos en los que chocamos
int Jugador::checkCollision() {
	return 0;
}

//Metodo que nos permite cambiar el color del jugador
void Jugador::setColor(ofColor col) {
	color = col;
}

//Metodo que nos permite cambiar el tamaño del jugador
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

//Metodo que nos permite cambiar el bool que nos indica si la gravedad esta down o no
void Jugador::setIsGravityDown(bool value) {
	isGravityDown = value;
}