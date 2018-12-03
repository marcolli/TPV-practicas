#include "Reward.h"
#include "Game.h"
#include "Texture.h"

Reward::Reward(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
	MovingObject(posx, posy, width, height, textura) {
	game = g;
	itList = it;
	velocidad.setX(0);
	velocidad.setY(1);
}

void Reward::update() {
	MovingObject::update();

	if(!(getY() > game->getHeight())){
		if (game->rewardcollides(getRect())) {
			action();
			game->killObject(itList);
		}
	}
	else game->killObject(itList);

}

void Reward::render() {
	SDL_Rect rect = getRect();
	texture->renderFrame(rect, 10, 8, 0);
	MovingObject::render();
}

Reward::~Reward()
{
}
