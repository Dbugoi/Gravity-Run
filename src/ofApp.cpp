#include "ofApp.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

//--------------------------------------------------------------
void ofApp::setup(){
	//ofBackground(214,218,188,88);
	
	ofBackground(139,228,232);		//Color del fondo del juego
	ofSetFrameRate(60);		 //Ponemos el framrate a 60 para que a todo el mundo le vaya el juego a la misma velocidad
	separador = ofRectangle(0, ofGetHeight() / 2 - 4, ofGetWidth(), 8);		//Linea que separa las dos pantallas de los jugadores	
	bloqueoEscenarioA = ofRectangle(0, 0, ofGetWidth(), ofGetHeight() / 2 - 4);		//Rectangulo que se pone para poner pantalla en negro al jugador 1
	bloqueoEscenarioB = ofRectangle(0, ofGetHeight() / 2 + 4, ofGetWidth(), ofGetHeight() / 2 - 4);  //Rectangulo que se pone para poner pantalla en negro al jugador 2
	bloqueoDoble = ofRectangle(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());   //Rectangulo que se pinta para poner la mitad de la pantalla en negro a ambos jugadores
	grav = 100;   //gravedad del mundo
	winner = 0; //Indica el estado del juego (0: jugando ,1:ganador jugador1; 2:ganador jugador2; 3:empate; 4: Meta alcanzada
	//Generacion aleatoria de obstaculos
	numObstaculos = 20;
	srand(time(NULL));
	//Mapa que indica para cada objeto el color que va a tener
	map<int, ofColor> coloresObstaculos = {
	{ 0, ofColor(232,75,58) }, //rectangulo 
	{ 1, ofColor(232,46,170) },  // triangulo rectangulo izquierda; 
	{ 2, ofColor(232,46,170)}, //triangulo rectangulo derecha; 
	{ 3, ofColor(92,217,76)},  //triangulo isosceles
	};

	int x = 1500, lon = 0, tipoObstaculo;  //X inicial donde empiezan los objetos a pintarse
	//generacion de obstaculos para que ambos escenarios tengan el mismo nivel
	for (int i = 0; i < numObstaculos; i++) {
		vector<int> vecAux;
		vecAux.push_back(x);	//Posicion horizotal del objeto
		lon = rand() % 150 + 50;		//Longitud es un random entre 50 y 200
		vecAux.push_back(lon);	//Longitud añadida al vector
		vecAux.push_back(rand() % 200 + 50);	//Altura random entre 50 y 250
		vecAux.push_back(rand() % 2);	//Arriba o abajo
		tipoObstaculo = rand() % 4;   //Se elige el tipo de obstaculo
		vecAux.push_back(tipoObstaculo);	//tipo obstaculo   0:rectangulo ; 1:triangulo rectangulo izquierda ; 2:triangulo rectangulo derecha ; 3: triangulo isosceles
		pair<vector<int>, ofColor> pairAux = make_pair(vecAux, coloresObstaculos[tipoObstaculo]);
		x += lon;    //Aumentamos la x inicial con la longitud del objeto 
		x += rand() % 150 + 150;  ////Aumentamos la x con una longitud entre 150 y 300 para pintar el siguiente objeto
		obstaculos.push_back(pairAux);
	}

	//Creamos los escenarios con sus respectivas medidas, colores y obstaculos
	escenarioA = Escenario(grav, 0, ofGetHeight() / 2 - 8, ofColor(232,134,70), obstaculos);
	escenarioB = Escenario(grav, ofGetHeight() / 2 + 4, ofGetHeight() -4, ofColor(232,134,70), obstaculos);
	escenarioA.setup();
	escenarioB.setup();

	//Fuente Verdana para pintar textos
	ofTrueTypeFont::setGlobalDpi(72);
	verdana30.load("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(18.0f);
	verdana30.setLetterSpacing(1.037);

}

//--------------------------------------------------------------
void ofApp::update(){
	//Comprobamos mediante funciones si ha colisionado algun jugador o han llegado a meta para deteminar ganador
	if (escenarioA.getHasCollided()) {
		if (escenarioB.getHasCollided()) {
			winner = 3;
		}
		else {
			winner = 2;
		}
	}
	else if (escenarioB.getHasCollided()) {
		if (escenarioA.getHasCollided()) {
			winner = 3;
		}
		else {
			winner = 1;
		}
	}
	//amos jugadores han llegado a meta
	else if (escenarioA.getHasFinished() && escenarioB.getHasFinished()) {
		winner = 4;
	}
	else {
	
		escenarioA.update();
		escenarioB.update();
	}
	//Actualizamos el tipo de powerup obtenido por cada jugador
	powerUpTypeEscA = escenarioA.getPowerUpType();
	powerUpTypeEscB = escenarioB.getPowerUpType();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Pintamos escenarios
	escenarioA.draw();
	escenarioB.draw();
	
	//Pintamos powerups y textos correspondientes
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

	//Pintamos separador
	ofSetColor(ofColor::mediumPurple);
	ofDrawRectangle(separador);

	//Pintamos resultado de la partida en funcion del ganador o si han llegado a meta
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

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//Segun que tecla se pulsa y si el powerup de controles invertidos esta activado se cambia la gravedad.
	if (key == 'w' || key =='W') {
		if(powerUpTypeEscB == 2)
			escenarioA.setGravity(grav);
		else
			escenarioA.setGravity(-grav);
	}
	else if (key == 's' || key =='S') {
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
