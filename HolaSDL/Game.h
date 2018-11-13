#pragma once

#include "Ball.h"
#include "Block.h"
#include "BlocksMap.h"
#include "Paddle.h"
#include "Texture.h"
#include "Wall.h"
#include "Vector2D.h"
#include "checkML.h"

using namespace std;

struct TextureAttributes
{
	string texturename;
	int fil;
	int col;
};

const int WIN_WIDTH		= 1020;
const int WIN_HEIGHT	= 700;
const int NUM_TEXTURES	= 5;
const int FRAME_RATE	= 3;
const int MAP_WIDTH		= WIN_WIDTH - 20;
const int MAP_HEIGHT	= (WIN_HEIGHT / 2) - 10;
const int PADDLE_WIDTH = 120;
const int BALL_WIDTH = 25;

const TextureAttributes TEXT_ATTRIBS[NUM_TEXTURES] = { {"../images/ball.png",1,1}, {"../images/bricks.png", 2, 3}, {"../images/paddle.png",1,1}, {"../images/side.png",1,1}, {"../images/topside.png",1,1} };
enum TextureName {BallText, BlocksText, PaddleText, SideText, TopText};


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

	bool exit, gameOver, win = false;//gameOver-> perder vidas, win-> acabar con todos los bloques, exit-> salir por menu de pausa
	bool paddleCD = false;
	int numVidas, numNivel;
	Texture* textures[];
public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
	bool collides(const SDL_Rect rect, const Vector2D& vel, Vector2D& coll);
	void recolocaBall();
};