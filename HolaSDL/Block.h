#pragma once

#include"ArkanoidObject.h"
#include "checkML.h"

using namespace std;

class Block : public ArkanoidObject {

private:

	int color;
	int fil;
	int col;

public:

	Block() {}
	Block(double posx, double posy, double wi, double he, int fila, int columna, int colour, Texture* textura);

	virtual void render();

	int getFila() const { return fil; };
	int getCol() const { return col; };

};