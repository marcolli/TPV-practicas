#pragma once
#include "ArkanoidObject.h"

class MovingObject : public ArkanoidObject {
protected:
	Vector2D velocidad;

public:

	MovingObject() {}
	MovingObject(int posx, int posy, double w, double h, Texture* textura);
	
	//virtual void render() { ArkanoidObject::render(); }

	virtual ~MovingObject();
};

