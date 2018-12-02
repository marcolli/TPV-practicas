#pragma once

#include "checkML.h"
#include "MovingObject.h"
class Game;
using namespace std;

class Paddle : public MovingObject {

private:
	Game* juego;


public:

	Paddle() {}
	Paddle(double posx, double posy, double width, double height, Texture* textura, Game* game);

	virtual void update();
	virtual void handleEvents(SDL_Event event);

	Vector2D getVel() {
		Vector2D aux(velocidad.getX(), velocidad.getY());
		return aux;
	}

	void acorta();
	void alarga();

};


