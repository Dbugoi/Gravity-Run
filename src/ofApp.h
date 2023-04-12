#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "Escenario.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Escenario escenarioA;           // the box2d world Escenario para jugador1
		Escenario escenarioB;           // the box2d world Escenario para jugador1
		vector<shared_ptr<ofxBox2dRect>> jugadores;           // default box2d rects  Jugadores son rectangulos de ofbox2d
		ofRectangle separador, bloqueoEscenarioA, bloqueoEscenarioB, bloqueoDoble;  //Rectangulos para pintar en el draw
		int grav, numObstaculos;   //Gravedad y numObstaculos del juego
		vector<pair<vector<int>, ofColor>> obstaculos;  //Vector de pareja con vector de enteros y color para onstaculos
		int winner;		// 0:jugando ; 1:gana jugador1 ; 2:gana jugador2 ; 3:empate
		int powerUpTypeEscA, powerUpTypeEscB;   //Tipo de powerup para cada jugador

		ofTrueTypeFont verdana30;  //Fuente Texto


};
