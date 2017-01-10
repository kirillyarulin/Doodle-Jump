#pragma once
#include "PlatformType.h"
#include "StaticPlatform.h"
#include "CrashPlatform.h"
#include "MovingPlatform.h"
#include <time.h>
#include "Game.h"

class PlatformFactory {
	static Platform* getPlatform(PlatformType name, Vector2f coord);
	static PlatformType getRandomType(int probabilityMovingPlatform, int probabilityCrashPlatform);
public:
	static const unsigned int count = 8;

	//Возвращает случайную платформу на высоте y
	static Platform* getRandomPlatformX(float y);

	//Возвращает массив count случайных платформ в случайных координатах
	static Platform** getRandomPlatforms();
};