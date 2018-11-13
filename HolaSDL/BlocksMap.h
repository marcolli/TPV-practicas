#pragma once

#include "Block.h"
#include "checkML.h"

using namespace std;

class BlocksMap {

private:

	Block*** mapa;
	int wmapa;
	int hmapa;
	int wcelda;
	int hcelda;
	int fils, cols;
	int numBloques;

	Texture* texture;

public:

	BlocksMap() {}
	BlocksMap(int widthmap, int heightmap, int widthcell, int heightcell, Texture* textura) {

		wmapa = widthmap;
		hmapa = heightmap;
		wcelda = widthcell;
		hcelda = heightcell;
		texture = textura;
		numBloques = 0;
	}

	~BlocksMap()
	{
		for (int i = 0; i < fils; i++) {
			for (int j = 0; j < cols; j++)
				delete mapa[i][j];
			delete[]mapa[i];
		}
		delete mapa;
		mapa = nullptr;
	}

	void render () const;
	void load(string filename);
	void reescalado();
	int  getNumBloques();
	Block* collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt(const Vector2D& p);
	void destruyeBloque(Block* bloque);

};