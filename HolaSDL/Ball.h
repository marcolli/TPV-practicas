#pragma once

#include "Vector2D.h"
#include "Texture.h"
#include "checkML.h"
class Game;

using namespace std;

class Ball {

private:

	Vector2D pos;
	int ancho;
	int alto;
	Vector2D velocidad;
	Texture* texture;
	Game* game;

public:

	Ball() {}
	Ball(int posx, int posy, int width, int height, Texture* textura, Game* juego) :
		pos(posx, posy), ancho(width), alto(height), texture(textura), velocidad(1, -1), game(juego) {}

	void render() const;
	void update();
	SDL_Rect getRect();
	Vector2D getVel();
	void setX(double x) { pos.setX(x); };
	void setY(double y) { pos.setY(y); };
	void setVel(double x, double y) { velocidad = {x, y}; };
};