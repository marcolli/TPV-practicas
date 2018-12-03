#include "Block.h"
#include "BlocksMap.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

BlocksMap::BlocksMap(int widthmap, int heightmap, int widthcell, int heightcell, Texture* textura) : 
	ArkanoidObject(10, 10, widthmap, heightmap, textura) {
	wcelda = widthcell;
	hcelda = heightcell;
	numBloques = 0;
}

void BlocksMap::render() {
	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			if (mapa[i][j] != nullptr)
				mapa[i][j]->render();
		}
	}
}

/*	Carga el mapa de bloques apartir de un filename(string)
*/

void BlocksMap::load(string filename) {

	ifstream file;
	file.open(filename);
	if (!file.is_open()) {
		file.close();
		throw "Error al cargar el mapa" + filename; //Esta excepcion funciona incorrectamente
													//no se propaga hasta el main, ni la recoge el try catch del main
													//no tengo ni idea de porque.
	}
	else {
		file >> fils >> cols;
		reescalado();
		mapa = new Block**[fils];
		for (int i = 0; i < fils; i++) mapa[i] = new Block*[cols];
		for (int i = 0; i < fils; i++) {
			for (int j = 0; j < cols; j++) {
				int color;
				file >> color;
				if (color != 0) {
					mapa[i][j] = new Block((j*wcelda)+10, (i*hcelda)+10, wcelda, hcelda, i, j, color, texture);
					numBloques++;
				}
				else mapa[i][j] = nullptr;
			}
		}
		file.close();
	}
	
}
//Rescala el tamaño de los bloques para ajustarlos al espacio del los muros, dependiedo del nº de filas y cols que tenga el mapa.
void BlocksMap::reescalado() {
	wmapa = WIN_WIDTH - 20;
	hmapa = WIN_HEIGHT - 10 - WIN_HEIGHT / 2;
	wcelda = (WIN_WIDTH - 20) / cols;
	hcelda = (WIN_HEIGHT - 10 - WIN_HEIGHT/2) / fils;
}
//Devuelve el numeros de bloques que quedan
int  BlocksMap::getNumBloques() {
	return numBloques;
}

/* Dados el rectángulo y vector de dirección de la pelota, devuelve un puntero al
   bloque con el que ésta colisiona (nullptr si no colisiona con nadie) y el
   vector normal perpendicular a la superficie de colisión.
*/
Block* BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector) {
	Vector2D p0 = { (double)ballRect.x, (double)ballRect.y }; // top-left
	Vector2D p1 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y }; // top-right
	Vector2D p2 = { (double)ballRect.x, (double)ballRect.y + (double)ballRect.h }; // bottom-left
	Vector2D p3 = { (double)ballRect.x + (double)ballRect.w,(double)ballRect.y + (double)ballRect.h }; // bottom-right
	Block* b = nullptr;
	if (ballVel.getX() < 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p0))) {
			if ((b->getY() + b->getH() - p0.getY()) <= (b->getX() + b->getW() - p0.getX()))
				collVector = { 0,1 }; // Borde inferior mas cerca de p0
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p1))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p2))) collVector = { 1,0 };
	}
	else if (ballVel.getX() >= 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p1))) {
			if (((b->getY() + b->getH() - p1.getY()) <= (p1.getX() - b->getX())) || ballVel.getX() == 0)
				collVector = { 0,1 }; // Borde inferior mas cerca de p1
			else
				collVector = { -1,0 }; // Borde izqdo mas cerca de p1
		}
		else if ((b = blockAt(p0))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p3))) 
			collVector = { -1,0 };
	}
	else if (ballVel.getX() > 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p3))) {
			if (((p3.getY() - b->getY()) <= (p3.getX() - b->getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p3
			else
				collVector = { -1,0 }; // Borde dcho mas cerca de p3
		}
		else if ((b = blockAt(p2))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p1))) collVector = { -1,0 };
	}
	else if (ballVel.getX() < 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p2))) {
			if (((p2.getY() - b->getY()) <= (b->getX() + b->getW() - p2.getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p2
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p3))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p0))) collVector = { 1,0 };
	}
	return b;
}


/*  Devuelve el puntero al bloque del mapa de bloques al que pertenece el punto p.
	En caso de no haber bloque en ese punto (incluido el caso de que p esté fuera
	del espacio del mapa) devuelve nullptr.
*/
Block* BlocksMap::blockAt(const Vector2D& coll) {
	int col = coll.getX();
	int fila = coll.getY();
	if (col < 10 || col > wmapa + 20 || fila < 10 || fila >(WIN_HEIGHT / 2) - 10)
		return nullptr;
	else {
		col = trunc((col - 10) / wcelda);
		fila = trunc((fila - 10) / hcelda);
		if (fila <= cols && col <= fils) {
			return mapa[fila][col];
		}
		else return nullptr;
	}
}

/*	Destruye el bloque que le pasamos como parametro y numBloques--;
*/

void BlocksMap::destruyeBloque(Block* bloque) {
	mapa[bloque->getFila()][bloque->getCol()] = nullptr;
	numBloques--;
}

void BlocksMap::saveToFile(ofstream & file) {

	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			if (mapa[i][j] == nullptr) file << "0 ";
			else file << mapa[i][j]->getColor() << " ";
		}
		file << endl;
	}

}

void BlocksMap::loadFromFile(ifstream & file) {

	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++) {
			int color;
			file >> color;
			if (color != 0) {
				if (mapa[i][j] == nullptr) {
					mapa[i][j] = new Block((j*wcelda) + 10, (i*hcelda) + 10, wcelda, hcelda, i, j, color, texture);
					numBloques++;
				}
			}
			else mapa[i][j] = nullptr;
		}
	}

}

BlocksMap::~BlocksMap() {
	for (int i = 0; i < fils; i++) {
		for (int j = 0; j < cols; j++)
			delete mapa[i][j];
		delete[]mapa[i];
	}
	delete mapa;
	mapa = nullptr;
}
