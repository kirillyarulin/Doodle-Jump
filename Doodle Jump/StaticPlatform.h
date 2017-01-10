#pragma once
#include "Platform.h"
#include "PlatformType.h"

class StaticPlatform : public Platform {
public:
	StaticPlatform(String file,Vector2f coord) : Platform(file,coord) {
		name = staticPlatform;
	}

	void update(float time, float dy) { 
		coord.y += dy*time;
		sprite.setPosition(coord);
	}
};