#include "RewardES.h"
#include "Game.h"

void RewardE::action() {
	game->acortaPaddle();
}

void RewardS::action() {
	game->alargaPaddle();
}