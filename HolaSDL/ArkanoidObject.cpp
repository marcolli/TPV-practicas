#include "ArkanoidObject.h"

ArkanoidObject::ArkanoidObject(int posx, int posy, double w, double h, Texture* textura) :
	GameObject(), texture(textura), pos(posx, posy), width(w), height(h) {}


SDL_Rect ArkanoidObject::getRect() {
	SDL_Rect rect;
	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = width;
	rect.h = height;
	return rect;
}

void  ArkanoidObject::render() {
	texture->render(getRect());
}

void ArkanoidObject::loadFromFile(ifstream & file) {

	double loadx, loady;
	file >> loadx >> loady >> width >> height;
	pos.setX(loadx);	pos.setY(loady);

}

void ArkanoidObject::saveToFile(ofstream & file) {

	file << pos.getX() << " " << pos.getY() << " " << width << " " << height;

}

double ArkanoidObject::getX() { return pos.getX(); }
double ArkanoidObject::getY() { return pos.getY(); }
double ArkanoidObject::getW() { return width; }
double ArkanoidObject::getH() { return height; }

