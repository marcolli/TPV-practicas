#pragma once
#include "Reward.h"

class RewardE : public Reward {

public:
	RewardE() {}
	RewardE(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
		Reward(posx, posy, width, height, textura, g, it) {}

	virtual void action() {
		game->acortaPaddle();
	}

};

class RewardS : public Reward {

public:
	RewardS() {}
	RewardS(double posx, double posy, double width, double height, Texture* textura, Game* g, list<ArkanoidObject*>::iterator it) :
		Reward(posx, posy, width, height, textura, g, it) {}

	virtual void action() {
		game->alargaPaddle();
	}

};