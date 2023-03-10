#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(214,218,188,88);

	//Mundo jugador 1
	escenarioA = Escenario(0, 100, ofColor::orange);
	escenarioB = Escenario(ofGetHeight() / 2, 600, ofColor::blue);
	escenarioA.setup();
	escenarioB.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
	escenarioA.update();
	escenarioB.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
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
	/*if (key == 'w') {
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
	*/
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
