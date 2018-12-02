
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"

using namespace std;

void run() {
	try
	{
		Game game;
		game.run();
		game.~Game();
	}
	catch (string e)
	{
		cout << e;
	}
}

int main(int argc, char* argv[]){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	run();
	
	return 0;
}