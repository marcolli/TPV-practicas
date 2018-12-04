#pragma once
#include "MovingObject.h"
#include <list>

class Game;
class Reward :
	public MovingObject
{
protected:
	Game* game;
	list<ArkanoidObject*>::iterator itList;

public:
	Reward() {}
	Reward(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it);

	virtual void update();
	virtual void render();

	virtual void action() {}

	virtual void setIt(list<ArkanoidObject*>::iterator it);

	virtual ~Reward();
};

