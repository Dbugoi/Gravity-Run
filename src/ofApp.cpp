#include "ofApp.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(214,218,188,88);
	separador = ofRectangle(0, ofGetHeight() / 2 - 4, ofGetWidth(), 8);
	grav = 50;
	//Generacion aleatoria de obstaculos
	numObstaculos = 100;
	srand(time(NULL));
	int x = 500, lon = 0;
	for (int i = 0; i < numObstaculos; i++) {
		vector<int> aux;
		aux.push_back(x); //Posicion horizotal
		lon = rand() % 150 + 50;
		aux.push_back(lon); //Longitud
		aux.push_back(rand() % 200 + 50); //Altura
		aux.push_back(rand() % 2); //Arriba o abajo
		x += lon;
		x += rand() % 150 + 150;
		obstaculos.push_back(aux);
	}
	escenarioA = Escenario(grav, 0, 100, ofColor::orange, obstaculos);
	escenarioB = Escenario(grav, ofGetHeight() / 2 + 4, 600, ofColor::blue, obstaculos);
	escenarioA.setup();
	escenarioB.setup();


	

}

//--------------------------------------------------------------
void ofApp::update(){
	escenarioA.update();
	escenarioB.update();
	if (escenarioA.getHasCollided()) {
		if (escenarioB.getHasCollided()) {

		}
		else {

		}
	}
	else if (escenarioB.getHasCollided()) {
		if (escenarioA.getHasCollided()) {

		}
		else {

		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::mediumPurple);
	ofDrawRectangle(separador);
	escenarioA.draw();
	escenarioB.draw();
	
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
		escenarioA.setGravity(-grav);
	}
	else if (key == 's') {
		escenarioA.setGravity(grav);
	}
	if (key == OF_KEY_UP) {
		escenarioB.setGravity(-grav);
	}
	else if (key == OF_KEY_DOWN) {
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
