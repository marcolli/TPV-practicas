#include "Wall.h"

using namespace std;



Wall::Wall(double posx, double posy, double wi, double he, Texture* textura) : ArkanoidObject(textura, getRect()) {

	pos = Vector2D(posx, posy);
	w = wi;
	h = he;
}

void Wall::render() {
	SDL_Rect rect = getRect();
	texture->render(rect);
}

//void Wall::render() const {
//	SDL_Rect rect;
//
//	rect.x = pos.getX();
//	rect.y = pos.getY();
//	rect.w = w;
//	rect.h = h;
//
//	texture->render(rect);
//}