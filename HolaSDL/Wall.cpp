#include "Texture.h"
#include "Wall.h"

using namespace std;

void Wall::render() const {
	SDL_Rect rect;

	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = ancho;
	rect.h = alto;

	texture->render(rect);
}