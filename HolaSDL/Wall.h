#pragma once

#include"Vector2D.h"
#include"Texture.h"
#include "checkML.h"

using namespace std;

class Wall {

private:

	Vector2D pos;
	int ancho;
	int alto;
	Texture* texture;

public:

	Wall() {}
	Wall(int posx, int posy, int w, int h, Texture* textura) :
		pos(posx, posy),
		ancho(w), alto(h), texture(textura) {}

	void render() const;

	double getX() const { return pos.getX(); };
	double getY() const { return pos.getY(); };
	int getW() const { return ancho; };
	int getH() const { return alto; };
};

