#include "Reward.h"

Reward::Reward(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
	MovingObject(posx, posy, width, height, textura) {
	game = g;
	itList = it;
	velocidad = Vector2D(0, 1);
}

void Reward::update() {
	MovingObject::update();
	if(!(getY() > game->getHeight())){
		if(game->rewardcollides(getRect())) action();
	}
}


Reward::~Reward()
{
}
