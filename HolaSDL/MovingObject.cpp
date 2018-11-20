#include "MovingObject.h"


MovingObject::MovingObject(Texture* textura, SDL_Rect rect) : ArkanoidObject(textura, rect)
{
	velocidad = Vector2D(0,0);
}


MovingObject::~MovingObject()
{
}
