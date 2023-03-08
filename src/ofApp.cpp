#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(214,218,188,88);

	//Mundo jugador 1
	escenarioA = Escenario(0);
	escenarioB = Escenario(ofGetHeight() / 2);
	

	//Mundo jugador 2
	

	auto jugador1 = make_shared<ofxBox2dRect>();
	jugador1->setPhysics(3.0, 0, 0.1);
	jugador1->setup(mundoA.getWorld(), 100, 100, 20, 20);
	jugadores.push_back(jugador1);

	auto jugador2 = make_shared<ofxBox2dRect>();
	jugador2->setPhysics(3.0, 0, 0.1);
	jugador2->setup(mundoB.getWorld(), 100, 600, 20, 20);

	jugadores.push_back(jugador2);
}

//--------------------------------------------------------------
void ofApp::update(){
	mundoA.update();
	mundoB.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::orange);
	jugadores[0]->draw();
	ofSetColor(ofColor::blue);
	jugadores[1]->draw();
	//Para que no se mueva un objeto le ponemos densidad 0 
	auto rect = make_shared<ofxBox2dRect>();
	rect->setPhysics(0.0, 0, 0.0);
	rect->setup(mundoA.getWorld(), 200, 200, 50, 200);
	rect->draw();
	/*
	
	for (auto &jugador : jugadores) {
		ofFill();
		ofSetColor(200);
		jugador->draw();
	}*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w') {
		mundoA.setGravity(0, -10);
	}
	else if (key == 's') {
		mundoA.setGravity(0, 10);
	}
	if (key == OF_KEY_UP) {
		mundoB.setGravity(0, -10);
	}
	else if (key == OF_KEY_DOWN) {
		mundoB.setGravity(0,10);
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
