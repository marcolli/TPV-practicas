#pragma once
#include "Texture.h"
#include "Vector2D.h"

class GameObject
{
public:
	GameObject();

	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handlleEvents() = 0;

	virtual ~GameObject();
};

