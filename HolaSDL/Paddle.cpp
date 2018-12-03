#include "Paddle.h"
#include "Game.h"
#include <iostream>

using namespace std;

SDL_Event event;

Paddle::Paddle(double posx, double posy, double width, double height, Texture* textura, Game* game) : 
	MovingObject(posx, posy, width, height, textura) {
	velocidad = Vector2D(0,0);
	juego = game;
}

void Paddle::update() {

	MovingObject::update();
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
		case SDLK_s:
			juego->save("archivo.txt");
			break;
		case SDLK_c:
			juego->load("archivo.txt");
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

void Paddle::acorta() {
	width -= 50;
}

void Paddle::alarga() {
	width += 50;
}