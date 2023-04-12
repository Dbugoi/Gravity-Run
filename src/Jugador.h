#pragma once
#include "GameObject.h"


class Jugador : public GameObject{
private:
	ofxBox2d *mundo;   //mundo ofbox2d 
	int altura;		//altura figura
	float mitadTamJugador; 
	int desfaseY;   
	int isGravityDown;  
	public:

	Jugador::Jugador() {}

	Jugador::Jugador(ofxBox2d * world, int alt, ofColor col,int pY) {
		mundo = world;
		altura = alt;
		color = col;
		desfaseY = pY;
		isGravityDown = true;
	}
	void setup() override;
	void update() override;
	int checkCollision() override;
	void setColor(ofColor col);
	void changeSize(bool toSmall);
	void setIsGravityDown(bool value);

};