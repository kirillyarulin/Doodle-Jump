#include "Entity.h"

Entity::Entity(String file, Vector2f coord) {
	image.loadFromFile("images/" + file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	this->coord = coord;
	width = image.getSize().x;
	height = image.getSize().y;
	sprite.setPosition(coord);
}