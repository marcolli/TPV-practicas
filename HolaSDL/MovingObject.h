#pragma once
#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject {
protected:
	Vector2D velocidad;

public:
	MovingObject();
	MovingObject(Texture* textura, SDL_Rect rect);
	//MovingObject(Texture* textura, SDL_Rect rect) : ArkanoidObject(textura, rect){};
	virtual ~MovingObject();
};

