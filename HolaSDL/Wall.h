#pragma once
#include"ArkanoidObject.h"
#include "checkML.h"

using namespace std;

class Wall : public ArkanoidObject {
public:

	Wall() {}
	Wall(int posx, int posy, int w, int h, Texture* textura);

	void render() const;

	double getX() const { return pos.getX(); };
	double getY() const { return pos.getY(); };
	int getW() const { return ancho; };
	int getH() const { return alto; };
};

