#include "Paddle.h"
#include <iostream>

using namespace std;

SDL_Event event;

void Paddle::render() const {
	SDL_Rect rect;

	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = ancho;
	rect.h = alto;

	texture->render(rect);
}

void Paddle::update() {

	pos.setX(pos.getX() + velocidad.getX());

}

/*	Mueve la paddle con los cursores izq y derecho y se detiene al soltar las teclas
	no esta implementado que se detenga al colisionar con las paredes
*/
void Paddle::handleEvents(SDL_Event event) {
	
	switch (event.type) {
		/* Look for a keypress */
	case SDL_KEYDOWN:
		/* Check the SDLKey values and move change the coords */
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			velocidad.setX(-3);
			break;
		case SDLK_RIGHT:
			velocidad.setX(3);
			break;
		default:
			break;
		}
		break;

	case SDL_KEYUP:		
		case (SDLK_RIGHT || SDLK_LEFT)://dejar de mover
			velocidad.setX(0);
			break;
		break;
	}

}
