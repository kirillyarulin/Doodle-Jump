#pragma once
#include "Platform.h"
#include "PlatformType.h"

class MovingPlatform : public Platform {
	float dx;
public:
	MovingPlatform(String file, Vector2f coord) : Platform(file,coord) {
		name = movingPlatform;
		dx = 0.2;
	}

	void update(float time, float dy);	
};