#include "Escenario.h"
#include <map>

void Escenario :: setup() {
	jugador.setup();
	int xPowerUp = 1000, xAux = 1000, powerType;
	ofColor obstColor;
	vector<int> listaObs;
	map<int, ofColor> powerUpColors = {
	{ 2, ofColor(164, 222, 2) }, //Invertir controles Verde 
	{ 3, ofColor(0,216,255) }, //Bloquear pantalla rival Azul Medio Bien
	{ 4, ofColor(255,111,105)}, //Bloquear ambas pantallas Rojo Bien
	{ 5, ofColor(255, 218, 0)}, //Escudo Amarillo Bien 
	{ 6, ofColor(187,68,240)} //Hacerte pequeño Amarillo
	};

	/* A partir de la lista obstaculos cogemos y generamos los obstaculos en cada escenario. 
		Tambien se generan los powerups sin embargo estos son randoms para cada escenario */
	for (pair<vector<int>, ofColor> pairObs : listaObstaculos) {
		listaObs = pairObs.first;
		obstColor = pairObs.second;
		xPowerUp = (listaObs[0]-(listaObs[1] / 2) - xAux)/2 + xAux;    
		gameObjects.push_back(new Obstaculo(mundo, listaObs[0], y, listaObs[1], listaObs[2], listaObs[3], listaObs[4], obstColor));
		xAux = (listaObs[0] + listaObs[1]/2);		//x del objeto + longitud 
		if (rand() % 8 == 0) {
			powerType = rand() % 5 + 2;
			gameObjects.push_back(new PowerUp(mundo, xPowerUp,(rand() % (ofGetHeight()/2 - 50)) + 25 + y, powerUpColors[powerType], powerType));
		}
	}
	//Añadimos el objeto meta al final del vector de gameobjects
	gameObjects.push_back(new Meta(mundo, xAux + 800,y));
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->setup();

}
//Actualizamos todos los mundos, jugadores y gameobjects del escenario
void Escenario::update() {
	mundo->update();
	jugador.update();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
		//Ha colisionado con un obstaculo
		switch (gameObjects[i]->checkCollision()) {
			case 1: //Choque con obstaculo
				if (powerUpType != 5) {  //Si no tiene escudo
					hasCollided = true; 
				}
				else {   //Desactivar escudo
					powerUpType = 0;
					powerUpTime = 0;
					jugador.setColor(colorInicialJugador);
				}
				
				break;
			case 2: // choque powerup invertir controles
				powerUpType = 2;
				powerUpTime = 180;
				break;
			case 3: //choque powerup bloquear pantalla rival
				powerUpType = 3;
				powerUpTime = 120;
				break;
			case 4: //choque powerup mitad pantalla negro
				powerUpType = 4;
				powerUpTime = 250;
				break;
			case 5:  //choque powerup Escudo
				powerUpType = 5;
				powerUpTime = 300;
				jugador.setColor(ofColor(250, 250, 210));
				break;
			case 6:  //choque powerup Cambiar tamaño
				if (powerUpType != 6) {
					jugador.changeSize(true);
					powerUpType = 6;
				}
				powerUpTime = 300;
				break;
			case 7: //choque meta
				hasFinished = true;
			default:
				break;
		}
	}
	//Decrementar tiempo de powerup
	if (powerUpTime > 0)
		powerUpTime--;
	else if (powerUpTime == 0) {
		if (powerUpType == 5)   //si no hay escudo volver a pintar color original
			jugador.setColor(colorInicialJugador);
		if (powerUpType == 6)  //volver a tamaño original
			jugador.changeSize(false);
		powerUpType = 0;
	}
		
}

//Pintar los diversos gameobjects 
void Escenario::draw() {
	for (int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->draw();
	jugador.draw();
}

//Metodo que nos permite cambiar la gravedad y actualizar varaible booleana que nos permite saber tipo gravedad jugador
void Escenario::setGravity(int value) {
		mundo->setGravityY(value);
		if (value > 0)
			jugador.setIsGravityDown(true);
		else
			jugador.setIsGravityDown(false);	
}

//Metodo que devuelve si ha colisionado el jugador
bool Escenario::getHasCollided() {
	return hasCollided;
}
//Metodo que devuelve si la partida ha finalizado 
bool Escenario::getHasFinished() {
	return hasFinished;
}
//metodo que devuelve tipo de powerup obtenido
int Escenario::getPowerUpType() {
	return powerUpType;
}

