#pragma once
#include "ArkanoidObject.h"
#include <fstream>

class MovingObject : public ArkanoidObject {
protected:
	Vector2D velocidad;

public:

	MovingObject() {}
	MovingObject(int posx, int posy, double w, double h, Texture* textura);

	virtual void update();
	
	virtual void saveToFile(ofstream & file);
	virtual void loadFromFile(ifstream & file);

	virtual ~MovingObject();
};

