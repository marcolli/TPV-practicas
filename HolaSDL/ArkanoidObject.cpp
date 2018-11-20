#include "ArkanoidObject.h"

ArkanoidObject::ArkanoidObject(Texture* textura, SDL_Rect rect)
{
	texture = textura;
	rect = rect;
	pos = Vector2D(0,0);
	ancho = alto = 0;
}

SDL_Rect ArkanoidObject::getRect() {

	SDL_Rect rect;
	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = ancho;
	rect.h = alto;
	return rect;
}

ArkanoidObject::~ArkanoidObject()
{
}
