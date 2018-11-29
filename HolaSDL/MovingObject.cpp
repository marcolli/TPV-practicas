#include "MovingObject.h"


MovingObject::MovingObject(int posx, int posy, double w, double h, Texture* textura) : 
	ArkanoidObject(posx, posy, w, h, textura)
{
	velocidad = Vector2D(0,0);
}

void MovingObject::saveToFile(ofstream & file) {

	file << pos.getX() << pos.getY() << width << height << velocidad.getX() << velocidad.getY();

}

void MovingObject::loadFromFile(ifstream & file) {

}

MovingObject::~MovingObject()
{
}
