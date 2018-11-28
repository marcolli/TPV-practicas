#include "Reward.h"

Reward::Reward(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
	MovingObject(posx, posy, width, height, textura) {
	game = g;
	itList = it;
}

void Reward::update() {
	MovingObject::update();
	//if(esta abajo){
	//	if(choca con paddle) action();
	//	game->killObject(itList);
	//}
}


Reward::~Reward()
{
}
