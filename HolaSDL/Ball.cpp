#include "Ball.h"
#include "Game.h"

using namespace std;

void Ball::render() const {

	SDL_Rect rect;

	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = ancho;
	rect.h = alto;

	texture->render(rect);
}

void Ball::update() {

	Vector2D prevpos(pos.getX(), pos.getY());

	//Actualizamos pos
	pos.setX(pos.getX() + velocidad.getX());
	pos.setY(pos.getY() + velocidad.getY());
	Vector2D coll;
	if (game->collides(getRect(), getVel(), coll)) {
		coll.normaliza();
		velocidad = velocidad + (coll * 2);
		velocidad.normaliza();
		pos = prevpos + velocidad;
	}
}

/*	Devuelve el rectangulo de la ball
*/

SDL_Rect Ball::getRect() {

	SDL_Rect rect;
	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = ancho;
	rect.h = alto;
	return rect;
}
Vector2D Ball::getVel() {
	return velocidad;
}


