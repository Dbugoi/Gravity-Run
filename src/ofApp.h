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

		Escenario escenarioA;           // the box2d world
		Escenario escenarioB;           // the box2d world
		vector<shared_ptr<ofxBox2dRect>> jugadores;           // default box2d rects
		ofRectangle separador, bloqueoEscenarioA, bloqueoEscenarioB, bloqueoDoble;
		int grav, numObstaculos;
		vector<vector<int>> obstaculos;
		int winner;  // 0:jugando ; 1:gana jugador1 ; 2:gana jugador2 ; 3:empate
		int powerUpTypeEscA, powerUpTypeEscB;



};
