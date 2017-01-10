#include "MovingPlatform.h"
#include "Game.h"

void MovingPlatform::update(float time,float dy) {
	coord.x = coord.x += dx*time;
	coord.y += dy*time;
	sprite.setPosition(coord);
	if (coord.x + width >= static_cast<float>(Game::widthWindow) || coord.x <= 0) {
		dx *= -1;
		coord.x = coord.x += 3*dx*time;
		sprite.setPosition(coord);
	}
}