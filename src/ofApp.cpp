#include "ofApp.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

//--------------------------------------------------------------
void ofApp::setup(){
	//ofBackground(214,218,188,88);
	ofBackground(139,228,232);
	ofSetFrameRate(60);
	separador = ofRectangle(0, ofGetHeight() / 2 - 4, ofGetWidth(), 8);
	bloqueoEscenarioA = ofRectangle(0, 0, ofGetWidth(), ofGetHeight() / 2 - 4);
	bloqueoEscenarioB = ofRectangle(0, ofGetHeight() / 2 + 4, ofGetWidth(), ofGetHeight() / 2 - 4);
	bloqueoDoble = ofRectangle(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());
	grav = 100;
	winner = 0; //0: jugando 
	//Generacion aleatoria de obstaculos
	numObstaculos = 20;
	srand(time(NULL));
	map<int, ofColor> coloresObstaculos = {
	{ 0, ofColor(232,75,58) }, //rectangulo 
	{ 1, ofColor(232,46,170) },  // triangulo rectangulo izquierda; 
	{ 2, ofColor(232,46,170)}, //triangulo rectangulo derecha; 
	{ 3, ofColor(92,217,76)},  //triangulo isosceles
	};

	int x = 1500, lon = 0, tipoObstaculo;
	//generacion de obstaculos
	for (int i = 0; i < numObstaculos; i++) {
		vector<int> vecAux;
		vecAux.push_back(x); //Posicion horizotal
		lon = rand() % 150 + 50;
		vecAux.push_back(lon); //Longitud
		vecAux.push_back(rand() % 200 + 50); //Altura
		vecAux.push_back(rand() % 2); //Arriba o abajo
		tipoObstaculo = rand() % 4;
		vecAux.push_back(tipoObstaculo);//tipo obstaculo   0:rectangulo ; 1:triangulo rectangulo izquierda ; 2:triangulo rectangulo derecha ; 3: triangulo isosceles
		pair<vector<int>, ofColor> pairAux = make_pair(vecAux, coloresObstaculos[tipoObstaculo]);
		x += lon;
		x += rand() % 150 + 150;
		obstaculos.push_back(pairAux);
	}
	escenarioA = Escenario(grav, 0, ofGetHeight() / 2 - 8, ofColor(232,134,70), obstaculos);
	escenarioB = Escenario(grav, ofGetHeight() / 2 + 4, ofGetHeight() -4, ofColor(232,134,70), obstaculos);
	escenarioA.setup();
	escenarioB.setup();

	ofTrueTypeFont::setGlobalDpi(72);

	verdana30.load("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(18.0f);
	verdana30.setLetterSpacing(1.037);



}

//--------------------------------------------------------------
void ofApp::update(){
	if (escenarioA.getHasCollided()) {
		if (escenarioB.getHasCollided()) {
			winner = 3;
		}
		else {
			winner = 2;
		}
		//winner = 2; //TODO eliminar
	}
	else if (escenarioB.getHasCollided()) {
		if (escenarioA.getHasCollided()) {
			winner = 3;
		}
		else {
			winner = 1;
		}
	}
	else if (escenarioA.getHasFinished() && escenarioB.getHasFinished()) {
		winner = 4;
	}
	else {
	
		escenarioA.update();
		escenarioB.update();
	}
	powerUpTypeEscA = escenarioA.getPowerUpType();
	powerUpTypeEscB = escenarioB.getPowerUpType();
}

//--------------------------------------------------------------
void ofApp::draw(){
	escenarioA.draw();
	escenarioB.draw();

	ofSetColor(ofColor::black);
	if (winner == 0) {
		if (powerUpTypeEscA == 3) {
			ofDrawRectangle(bloqueoEscenarioB);
		}
		if (powerUpTypeEscB == 3) {
			ofDrawRectangle(bloqueoEscenarioA);
		}
		if (powerUpTypeEscA == 4 || powerUpTypeEscB == 4) {
			ofDrawRectangle(bloqueoDoble);
		}
		if (powerUpTypeEscA == 2) {
			verdana30.drawString("CONTROLES INVERTIDOS", ofGetWidth() / 2 - 150, ofGetHeight() / 4 * 3 );
		}
		if (powerUpTypeEscB == 2) {
			verdana30.drawString("CONTROLES INVERTIDOS", ofGetWidth() / 2 - 150, ofGetHeight() / 4);
		}
	}

	ofSetColor(ofColor::mediumPurple);
	ofDrawRectangle(separador);

	ofSetColor(ofColor::black); 
	
	if (winner == 1) {
		verdana30.drawString("HAS GANADO", ofGetWidth() / 2 -100, ofGetHeight() / 4 );
		verdana30.drawString("HAS PERDIDO", ofGetWidth() / 2 - 100, ofGetHeight() / 4 * 3);
	}
	else if (winner == 2) {
		verdana30.drawString("HAS PERDIDO", ofGetWidth() / 2 - 100, ofGetHeight() / 4);
		verdana30.drawString("HAS GANADO", ofGetWidth() / 2 - 100, ofGetHeight() / 4 * 3);
	}
	else if (winner == 3) {
		verdana30.drawString("EMPATE", ofGetWidth() / 2 - 70, ofGetHeight() / 4);
		verdana30.drawString("EMPATE", ofGetWidth() / 2 - 70, ofGetHeight() / 4 * 3);
	}
	else if (winner == 4) {
		verdana30.drawString("META ALCANZADA", ofGetWidth() / 2 - 100, ofGetHeight() / 4);
		verdana30.drawString("META ALCANZADA", ofGetWidth() / 2 - 100, ofGetHeight() / 4 * 3);
	}

	//cout << ofGetFrameRate() << endl;

	//Para que no se mueva un objeto le ponemos densidad 0 
	/*auto rect = make_shared<ofxBox2dRect>();
	rect->setPhysics(0.0, 0, 0.0);
	rect->setup(mundoA.getWorld(), 200, 200, 50, 200);
	rect->draw();
	*/
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') {
		if(powerUpTypeEscB == 2)
			escenarioA.setGravity(grav);
		else
			escenarioA.setGravity(-grav);
	}
	else if (key == 's') {
		if (powerUpTypeEscB == 2)
			escenarioA.setGravity(-grav);
		else
			escenarioA.setGravity(grav);
	}
	if (key == OF_KEY_UP) {
		if (powerUpTypeEscA == 2)
			escenarioB.setGravity(grav);
		else
			escenarioB.setGravity(-grav);
	}
	else if (key == OF_KEY_DOWN) {
		if (powerUpTypeEscA == 2)
			escenarioB.setGravity(-grav);
		else
			escenarioB.setGravity(grav);
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
