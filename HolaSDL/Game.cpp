#include "Game.h"
#include <windows.h>
#include <iostream>
#include "checkML.h"
#include <list>

using namespace std;

Game::Game() {
	// We first initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";

	for (int i = 0; i < NUM_TEXTURES; i++) {
		textures[i] = new Texture(renderer, TEXT_ATTRIBS[i].texturename, TEXT_ATTRIBS[i].fil, TEXT_ATTRIBS[i].col);
	}

	numVidas = 3;
	numNivel = 1;
	score = 0;

	paddle		= new Paddle((WIN_WIDTH/2) - (PADDLE_WIDTH / 2), ((WIN_HEIGHT*3)/4), PADDLE_WIDTH, 24, textures[PaddleText]);
	ball		= new Ball((WIN_WIDTH / 2) - (BALL_WIDTH/2), ((WIN_HEIGHT * 3) / 4) -10, BALL_WIDTH, 25, textures[BallText], this);
	topwall		= new Wall(0, 0, WIN_WIDTH, 10, textures[TopText]);
	rightwall	= new Wall(WIN_WIDTH - 10, 0, 10, 800, textures[SideText]);
	leftwall	= new Wall(0, 0, 10, 800, textures[SideText]);
	map			= new BlocksMap(MAP_WIDTH, MAP_HEIGHT, 0, 0, textures[BlocksText]);

	objects.push_back(map);
	objects.push_back(paddle); 
	objects.push_back(ball); 
	objects.push_back(topwall); 
	objects.push_back(rightwall); 
	objects.push_back(leftwall); 
	
	map->load("../mapas/level01.ark");
}
 
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() {
	cout << "Tienes 3 vidas" << endl;
	while (!exit && !win && !gameOver) { // Falta el control de tiempo
		handleEvents();
		update();
		render(); 
	 	Sleep(FRAME_RATE);
	}
}

void Game::update() {
	for (ArkanoidObject* o: objects) {
		o->update();
	}	
}

void Game::render() const {
	SDL_RenderClear(renderer);
	for (ArkanoidObject* o : objects) {
		o->render();
	}
	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		paddle->handleEvents(event);
	}
}



/*	Este método se llama en el update de ball y detecta las colisiones del Rect de Ball
	con varios casos: blocksMap, paredes, paddle.
	Devuelve true si colisiona con algo, falso en caso contrario
	y ademas devuelve el vector de colision

	**En el caso de que colisione con paddle hemos puesto un bool paddleCD 
	  que nos ayuda a que si la pelota ya ha colisionado con ella no lo vuelva a 
	  hacer con otra de sus 3 partes. 
	  Esto pasaba amenudo si golpeabamos la pelota con la pala mientras moviamos la pala
*/
bool Game::collides(const SDL_Rect rect, const Vector2D& vel, Vector2D& coll) {

	//casos blocksMap
	if (rect.x > leftwall->getW() && rect.x+rect.w < WIN_WIDTH - rightwall->getW() && rect.y > topwall->getH() && rect.y < MAP_HEIGHT + topwall->getH()) {
		Vector2D collVect;
		Block* b = nullptr;
		if (b = map->collides(ball->getRect(), ball->getVel(), coll)) {//si hay colisión con bloques
			//cambio la velocidad de ball
			map->destruyeBloque(b);//destruyo el bloque con el que ha colisionado la pelota
			score += 10;
			cout << score << endl;
			if (map->getNumBloques() == 0)
				win = true;
			paddleCD = false;
			return true;
		}
	}

	//casos muros
	else if (rect.x+rect.w > rightwall->getX()) {
		coll = { -1,0 };
		paddleCD = false;
		return true;
	}
	else if (rect.x < leftwall->getX() + leftwall->getW()) {
		coll = { 1,0 };
		paddleCD = false;
		return true;
	}
	else if (rect.y < topwall->getY() + topwall->getH()) {
		coll = { 0,1 };
		paddleCD = false;
		return true;
	}

	//casos Paddle
	else if (rect.x < (paddle->getX() + paddle->getW()) && (rect.x + rect.w) > paddle->getX() && (rect.y + rect.h) > paddle->getY() && rect.y < (paddle->getY() + paddle->getH())) {
		if (!paddleCD) {
			if (rect.x + (rect.w/2) < (paddle->getX() + (paddle->getW() / 3))) coll = { -1, -1 };
			else if (rect.x + (rect.w / 2) < (paddle->getX() + (paddle->getW() * 2 / 3))) coll = {0, -1 };
			else if (rect.x + (rect.w / 2) > (paddle->getX() + (paddle->getW() * 2 / 3))) coll = { 1, -1 };
			paddleCD = true;
			return true;
		}
	}

	//caso salir de pantalla
	if (rect.y > WIN_HEIGHT) {
		if (numVidas > 1) {
			numVidas--;
			//metodo recoloca pelota
			ball->setVel(1, -1);
			recolocaBall();
			cout << "Te quedan " << numVidas << " vidas" << endl;
		}
		else {
			cout << "Has perdido";
			gameOver = true;
		}
	}
	return false;
}


/*	Recoloca la bola en su posicion original cuando pierdes una vida
*/
void Game::recolocaBall() {
	ball->setX((WIN_WIDTH / 2) - (BALL_WIDTH / 2));
	ball->setY(((WIN_HEIGHT * 3) / 4) - 10);
}

void Game::save(string file) {
	ofstream f;
	f.open(file);

	f << numVidas << numNivel << score << endl;

	for (auto o : objects) {
		o->saveToFile(f);
		f << endl;
	}

	f.close();
}