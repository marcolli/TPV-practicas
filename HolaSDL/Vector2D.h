#pragma once

#include "checkML.h"
using namespace std;

class Vector2D {

private:

	double x;
	double y;

public:

	Vector2D();
	Vector2D(double xx, double yy);

	double getX() const { return x; };
	double getY() const { return y; };

	void setX(double newx) { x = newx; };
	void setY(double newy) { y = newy; };

	Vector2D operator+(Vector2D a);
	Vector2D operator-(Vector2D a);

	int operator*(Vector2D a);
	Vector2D operator*(int a);

	void normaliza();

};