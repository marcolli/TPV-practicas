#include "MovingObject.h"


MovingObject::MovingObject(int posx, int posy, double w, double h, Texture* textura) : 
	ArkanoidObject(posx, posy, w, h, textura)
{
	velocidad = Vector2D(0,0);
}

void MovingObject::saveToFile(ofstream & file) {

	file << pos.getX() << " " << pos.getY() << " " << width << " " << height << " " << velocidad.getX() << " " << velocidad.getY();

}

void MovingObject::loadFromFile(ifstream & file) {

	double loadx, loady, velox, veloy;
	file >> loadx >> loady >> width >> height >> velox >> veloy;
	pos.setX(loadx);	pos.setY(loady);
	velocidad.setX(velox);	velocidad.setY(veloy);

}

void MovingObject::update() {
	pos = pos + velocidad;
}

MovingObject::~MovingObject()
{
}
