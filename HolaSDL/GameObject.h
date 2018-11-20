#pragma once
#include "Texture.h"
#include "Vector2D.h"

class GameObject
{
public:
	GameObject();

	virtual void render() = 0;
	virtual void update();
	virtual void handlleEvents();

	virtual ~GameObject();
};

