#pragma once

#include"ArkanoidObject.h"
#include "Block.h"
#include "checkML.h"

using namespace std;

class BlocksMap : public ArkanoidObject {

private:

	Block*** mapa;
	int wmapa;
	int hmapa;
	int wcelda;
	int hcelda;
	int fils, cols;
	int numBloques;

	//Texture* texture;

public:

	BlocksMap() {}
	BlocksMap(int widthmap, int heightmap, int widthcell, int heightcell, Texture* textura);

	~BlocksMap();

	//void render () const;
	virtual void render();
	void load(string filename);
	void reescalado();
	int  getNumBloques();
	Block* collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt(const Vector2D& p);
	void destruyeBloque(Block* bloque);

	virtual void loadFromFile(ifstream & file);
	virtual void saveToFile(ofstream & file);

};