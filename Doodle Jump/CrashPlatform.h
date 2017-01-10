#pragma once
#include "Platform.h"
#include "PlatformType.h"

class CrashPlatform : public Platform {
public:
	CrashPlatform(String file, Vector2f coord) : Platform(file,coord) {
		name = crashPlatform;
	}

	void update(float time, float dy) {
		coord.y += dy*time;
		sprite.setPosition(coord);
	}

};