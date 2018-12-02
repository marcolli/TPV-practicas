#pragma once
#include "Reward.h"
#include <list>

class RewardL : public Reward {
	
public:
	RewardL() {}
	RewardL(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it):
		Reward(posx, posy, width, height, textura, g, it) {}
	
	virtual void action();

};