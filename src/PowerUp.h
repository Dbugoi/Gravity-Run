#pragma once

#include "GameObject.h"

class PowerUp : public GameObject {
private:
	ofxBox2d *mundo;   //mundo de ofbox2d para poder introducir el objeto
	int tipo;  // 2:invertir controles ; 3: bloquear pantalla rival ; 4:mitad pantalla negro; 5: escudo protector; 6 :cambio tamaño 
public:

	PowerUp::PowerUp() {}

	PowerUp::PowerUp(ofxBox2d * world, int pX, int pY, ofColor col, int tipoObstaculo) {
		mundo = world;   //mundo a introducir el objeto
		x = pX;		//posicion x 
		y = pY;		//posicion y
		color = col;   //color 
		tipo = tipoObstaculo;   //tipo powerup
	}
	void setup() override;
	void update() override;
	int checkCollision() override;
	//void draw();
	
};