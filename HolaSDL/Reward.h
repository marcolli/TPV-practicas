#pragma once
#include "MovingObject.h"
class Reward :
	public MovingObject
{
public:
	Reward();
	Reward(double posx, double posy, double width, double height, Texture* textura);
	
	virtual void render();
	virtual void update();

	virtual ~Reward();
};

