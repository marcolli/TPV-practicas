#pragma once
#include "Texture.h"
#include "Vector2D.h"

class GameObject {
public:
	GameObject() {};

	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleEvents() = 0;

	virtual ~GameObject();
};

