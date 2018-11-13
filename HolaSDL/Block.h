#pragma once

#include"Vector2D.h"
#include"Texture.h"
#include "checkML.h"

using namespace std;

class Block {

private:

	Vector2D pos;
	int ancho;
	int alto;
	int color;
	int fil;
	int col;
	Texture* texture;

public:

	Block() {}
	Block(int posx, int posy, int w, int h, int fila, int columna, int colour, Texture* textura) :
		pos(posx, posy), color(colour), fil(fila), col(columna),
		ancho(w), alto(h), texture(textura) {}

	double getX() const { return pos.getX(); };
	double getY() const { return pos.getY(); };
	int getW() const { return ancho; };
	int getH() const { return alto; };
	void render() const;

	int getFila() const { return fil; };
	int getCol() const { return col; };

};