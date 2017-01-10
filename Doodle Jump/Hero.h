#pragma once
#include "stdafx.h"
#include "Entity.h"
#include "Platform.h"

using namespace sf;

class Hero : public Entity {
	float dx, dy;
	const float barrier = 150;
	float scoreHero = 0;
	enum { LEFT, STAY, RIGHT } state;

	SoundBuffer bufferJump, bufferCrashPlatform,bufferGameOver;
	Sound soundJump, soundCrashPlatform, soundGameOver;

	void control();
public:
	Hero();
	
	void update(float time);

	float unnecessaryMovement();

	bool coolisionWithPlatform(Platform& plat);

	bool isLive();

	float score() const;
};