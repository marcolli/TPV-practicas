#include "Vector2D.h"
#include <math.h>n 

using namespace std;

Vector2D::Vector2D() : x(), y() {}
Vector2D::Vector2D(double xx, double yy) : x(xx), y(yy) {}

Vector2D Vector2D::operator+(const Vector2D a) {
	
	Vector2D aux;
	aux.x = this->x + a.x;
	aux.y = this->y + a.y;
	return aux;

}

Vector2D Vector2D::operator-(const Vector2D a) {
	
	Vector2D aux;
	aux.x = this->x - a.x;
	aux.y = this->y - a.x;
	return aux;

}

int Vector2D::operator*(Vector2D a) {

	int aux = a.x * x + a.y * y;
	return aux;

}

Vector2D Vector2D::operator*(int a) {
	
	Vector2D aux;
	aux.x = x * a;
	aux.y = y * a;
	return aux;

}

/*	Normaliza x e y
*/
void Vector2D::normaliza() {
	double mag = sqrt(pow(x, 2) + pow(y, 2));
	if (mag > 0.0) {
		x = x / mag;
		y = y / mag;
	}
}