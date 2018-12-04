#pragma once

#include "Ball.h"
#include "Block.h"
#include "BlocksMap.h"
#include "Paddle.h"
#include "Texture.h"
#include "Wall.h"
#include "Vector2D.h"
#include "Reward.h"
#include "RewardES.h"
#include "RewardL.h"
#include "RewardR.h"
#include "checkML.h"

#include <list>

using namespace std;

struct TextureAttributes
{
	string texturename;
	int fil;
	int col;
};

const int WIN_WIDTH		= 1020;
const int WIN_HEIGHT	= 700;
const int NUM_TEXTURES	= 6;
const int FRAME_RATE	= 3;
const int MAP_WIDTH		= WIN_WIDTH - 20;
const int MAP_HEIGHT	= (WIN_HEIGHT / 2) - 10;
const int PADDLE_WIDTH = 120;
const int BALL_WIDTH = 25;

const TextureAttributes TEXT_ATTRIBS[NUM_TEXTURES] = 
{ {"../images/ball.png",1,1}, {"../images/bricks.png", 2, 3}, {"../images/paddle.png",1,1}, {"../images/side.png",1,1}, {"../images/topside.png",1,1}, {"../images/rewards.png",10,8} };
enum TextureName {BallText, BlocksText, PaddleText, SideText, TopText, RewardText};


class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	
	Paddle* paddle = nullptr;
	BlocksMap* map = nullptr;
	Wall* topwall = nullptr;
	Wall* rightwall = nullptr;
	Wall* leftwall = nullptr;
	Ball* ball = nullptr;

	list<ArkanoidObject*> objects;
	list<ArkanoidObject*>::iterator firstReward;

	bool exit, gameOver, win = false;//gameOver-> perder vidas, win-> acabar con todos los bloques, exit-> salir por menu de pausa
	bool paddleCD = false;
	int numVidas, numNivel, score;
	int numRewards = 0;
	string level;
	Texture* textures[];

public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
	void save(string file);
	void load(string file);

	bool collides(const SDL_Rect rect, const Vector2D& vel, Vector2D& coll);
	bool rewardcollides(const SDL_Rect rect);

	void recolocaBall();
	void restartGame();

	void pasaNivel();
	void vidaExtra();
	void alargaPaddle();
	void acortaPaddle();

	void killObject(list<ArkanoidObject*>::iterator it);

	int getHeight() {
		return WIN_HEIGHT;
	}

	int getRandom(int ini, int cantidad) {
		return rand() % cantidad + ini;
	}
};