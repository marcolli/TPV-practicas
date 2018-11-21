#pragma once

#include "checkML.h"
#include "MovingObject.h"

using namespace std;

class Paddle : public MovingObject {

public:

	Paddle() {}
	Paddle(double posx, double posy, double width, double height, Texture* textura);

	virtual void update();
	virtual void handleEvents(SDL_Event event);

};


