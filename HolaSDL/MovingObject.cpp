#include "MovingObject.h"


MovingObject::MovingObject(int posx, int posy, double w, double h, Texture* textura) : 
	ArkanoidObject(posx, posy, w, h, textura)
{
	velocidad = Vector2D(0,0);
}


MovingObject::~MovingObject()
{
}
