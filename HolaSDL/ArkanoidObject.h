
#include "GameObject.h"

class ArkanoidObject :	public GameObject {
protected:
	Vector2D pos;
	double w, h;
	Texture* texture;
	SDL_Rect rect;

public:
	ArkanoidObject();
	ArkanoidObject(Texture* textura, SDL_Rect rectan);

	virtual void loadFromFile();
	virtual void saveToFile();
	virtual SDL_Rect getRect();

	double getX();
	double getY();
	double getW();
	double getH();

	virtual ~ArkanoidObject();
};
