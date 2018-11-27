#include "Wall.h"

using namespace std;

Wall::Wall(double posx, double posy, double wi, double he, Texture* textura) :
	ArkanoidObject(posx, posy, wi, he, textura) {}

Wall::~Wall() {
}