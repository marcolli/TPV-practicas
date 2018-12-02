#pragma once
#include "Reward.h"
#include <list>

class RewardR : public Reward {

public:
	RewardR() {}
	RewardR(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
		Reward(posx, posy, width, height, textura, g, it) {}

	virtual void action();
	
};