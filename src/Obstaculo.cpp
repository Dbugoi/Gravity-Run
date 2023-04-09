#include "Obstaculo.h"

void Obstaculo::setup() {
	/*auto aux = make_shared<ofxBox2dRect>();
	aux->setup(mundo->getWorld(), x, y, longitud, altura);
	figure = aux;

	figure->body->GetFixtureList()->SetSensor(true);
	*/

	if (tipo == 0) { //Rectangulo
		auto aux = make_shared<ofxBox2dRect>();
		aux->setup(mundo->getWorld(), x, y, longitud, altura);
		figure = aux;
	}
	else {
		auto triangle = std::make_shared<ofxBox2dPolygon>();
		if (tipo == 1) { //Triangulo rectangulo izquierda
			triangle->addTriangle(ofDefaultVertexType(x, yBaseTriangulo, 0),
				ofDefaultVertexType(x + longitud, yBaseTriangulo, 0),
				ofDefaultVertexType(x, y, 0));
		}

		else if (tipo == 2) { //Triangulo rectangulo izquierda
			triangle->addTriangle(ofDefaultVertexType(x, yBaseTriangulo, 0),
				ofDefaultVertexType(x + longitud, yBaseTriangulo, 0),
				ofDefaultVertexType(x + longitud, y, 0));
		}
		else {
			triangle->addTriangle(ofDefaultVertexType(x, yBaseTriangulo, 0),
				ofDefaultVertexType(x + longitud, yBaseTriangulo, 0),
				ofDefaultVertexType(x + longitud / 2, y, 0));
		}

		triangle->create(mundo->getWorld());
		figure = triangle;
	}

	figure->body->GetFixtureList()->SetSensor(true);
	
}

void Obstaculo::update() {
	auto aux = figure->getPosition();
	aux.x -= 5; //TODO -10
	figure->setPosition(aux);
}

int Obstaculo::checkCollision() {
	if (!hasCollided) {
		/*for (b2ContactEdge* edge = figure->body->GetContactList(); edge; edge = edge->next) {
			hasCollided = true;
			return 1;
		}*/
		for (b2ContactEdge* edge = figure->body->GetContactList(); edge; edge = edge->next) {
			if (edge->contact->IsTouching()) {
				hasCollided = true;
				return 1;
			}
		}
		
	}
	return 0;
}

