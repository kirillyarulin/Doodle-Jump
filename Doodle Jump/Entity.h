#pragma once
#include "stdafx.h"

using namespace sf;

class Entity {
	Image image;
	Texture texture;
protected:
	float width, height;
	Vector2f coord;
	Sprite sprite;

	Entity(String file, Vector2f coord);
	Entity() {}
public:
	float getHeight() const { return height; }
	float getWidth() const { return width; }

	Vector2f getCoord() const { return coord; }

	void draw(RenderWindow& window) const { window.draw(sprite); }
};
