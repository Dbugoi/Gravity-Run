#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(214,218,188,88);
	separador = ofRectangle(0, ofGetHeight() / 2 - 4, ofGetWidth(), 8);
	grav = 20;
	//Mundo jugador 1
	escenarioA = Escenario(0, 100, ofColor::orange);
	escenarioB = Escenario(ofGetHeight() / 2 + 4, 600, ofColor::blue);
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
