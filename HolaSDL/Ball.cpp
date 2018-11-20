#include "Ball.h"
#include "Game.h"

using namespace std;

Ball::Ball(double posx, double posy, double width, double height, Texture* textura, Game* juego) : MovingObject(textura, getRect()) {

	pos = Vector2D(posx, posy);
	w = width;
	h = height;
	velocidad = Vector2D(1,-1);
	game = juego;
}


void Ball::render() {

	SDL_Rect rect = getRect();

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

/*	Devuelve el Velocidad de la ball
*/

Vector2D Ball::getVel() {
	return velocidad;
}


