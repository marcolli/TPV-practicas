#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "checkML.h"

using namespace std;

class Paddle {

private:
	Vector2D pos;
	int ancho;
	int alto;
	Vector2D velocidad;
	Texture* texture;

public:

	Paddle() {}
	Paddle(int posx, int posy, int width, int height, Texture* textura) :
		pos(posx, posy), ancho(width), alto(height), texture(textura), velocidad(0,0) {}

	void render() const;

	void update();
	void handleEvents(SDL_Event event);
	double getX() const { return pos.getX(); };
	double getY() const { return pos.getY(); };
	int getW() const { return ancho; };
	int getH() const { return alto; };
};


