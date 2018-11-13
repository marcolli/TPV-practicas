#include "Texture.h"
#include "Block.h"

using namespace std;

void Block::render() const {

	SDL_Rect rect;

	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = ancho;
	rect.h = alto;

	texture->renderFrame(rect, (color-1)/texture->getNumCols(), (color-1)%texture->getNumCols(), 0);
}