#include "Texture.h"
#include "Wall.h"

using namespace std;

Wall::Wall(int posx, int posy, int w, int h, Texture* textura) : ArkanoidObject(textura) {
	pos = Vector2D(posx, posy);

}

void Wall::render() const {
	SDL_Rect rect;

	rect.x = pos.getX();
	rect.y = pos.getY();
	rect.w = ancho;
	rect.h = alto;

	texture->render(rect);
}