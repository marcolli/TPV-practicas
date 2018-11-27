#include "Ball.h"
#include "Game.h"

using namespace std;

Ball::Ball(double posx, double posy, double w, double h, Texture* textura, Game* juego) : 
	MovingObject(posx, posy, w, h, textura) {
	velocidad = Vector2D(1,-1);
	game = juego;
}
//
//void Ball::render() {
//	MovingObject::render();
//}

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


