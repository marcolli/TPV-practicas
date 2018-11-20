#include "ArkanoidObject.h"

ArkanoidObject::ArkanoidObject(Texture* textura, SDL_Rect rectan)
{
	texture = textura;
	rect = rectan;
	pos = Vector2D(0,0);
	w = h = 0;
}

SDL_Rect ArkanoidObject::getRect() {

	SDL_Rect rect;
	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = w;
	rect.h = h;
	return rect;
}

double ArkanoidObject::getX() {	return pos.getX(); }
double ArkanoidObject::getY() { return pos.getY(); }
double ArkanoidObject::getW() { return w; }
double ArkanoidObject::getH() { return h; }


ArkanoidObject::~ArkanoidObject()
{
}
