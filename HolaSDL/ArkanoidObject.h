#pragma once
#include "GameObject.h"
#include <fstream>

class ArkanoidObject : public GameObject {
protected:
	Vector2D pos;
	double width, height;
	Texture* texture;

public:
	ArkanoidObject() {};
	ArkanoidObject(int posx, int posy, double w, double h, Texture* textura);

	virtual void render();
	virtual void update() {};
	virtual void handleEvents() {};

	virtual void loadFromFile(ifstream & file);
	virtual void saveToFile(ofstream & file);
	SDL_Rect getRect();

	double getX();
	double getY();
	double getW();
	double getH();

	virtual  ~ArkanoidObject() {};

};
