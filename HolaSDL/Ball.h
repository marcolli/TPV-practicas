#pragma once

#include "checkML.h"
#include "MovingObject.h"
class Game;

using namespace std;

class Ball : public MovingObject {

private:
	Game* game;

public:

	Ball() {};
	Ball(double posx, double posy, double width, double height, Texture* textura, Game* juego);

	virtual void update();

	Vector2D getVel();
	void setX(double x) { pos.setX(x); };
	void setY(double y) { pos.setY(y); };
	void setVel(double x, double y) { velocidad = {x, y}; };
};