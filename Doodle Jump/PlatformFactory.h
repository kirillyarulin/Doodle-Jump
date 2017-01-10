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

	//���������� ��������� ��������� �� ������ y
	static Platform* getRandomPlatformX(float y);

	//���������� ������ count ��������� �������� � ��������� �����������
	static Platform** getRandomPlatforms();
};