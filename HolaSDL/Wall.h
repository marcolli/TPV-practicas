#pragma once
#include"ArkanoidObject.h"
#include "checkML.h"

using namespace std;

class Wall : public ArkanoidObject {
public:

	Wall() {}
	Wall(double posx, double posy,double wi, double he, Texture* textura);

	/*virtual void update();
	virtual void handleEvents();*/

	virtual ~Wall();
};

