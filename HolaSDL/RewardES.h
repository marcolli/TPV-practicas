#pragma once
#include "Reward.h"
#include <list>


class RewardE : public Reward {

public:
	RewardE() {}
	RewardE(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
		Reward(posx, posy, width, height, textura, g, it) {}

	virtual void action();

};

class RewardS : public Reward {

public:
	RewardS() {}
	RewardS(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
		Reward(posx, posy, width, height, textura, g, it) {}

	virtual void action();

};