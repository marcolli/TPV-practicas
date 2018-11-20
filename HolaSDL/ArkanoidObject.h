
#include "GameObject.h"

class ArkanoidObject :	public GameObject
{
protected:
	Vector2D pos;
	double ancho, alto;
	Texture* texture;
	SDL_Rect rect;

public:
	ArkanoidObject();
	ArkanoidObject(Texture* textura, SDL_Rect rect);

	virtual void loadFromFile();
	virtual void saveFromFile();
	virtual SDL_Rect getRect();

	virtual ~ArkanoidObject();
};
