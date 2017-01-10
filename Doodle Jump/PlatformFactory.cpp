#include "PlatformFactory.h"

Platform* PlatformFactory::getPlatform(PlatformType name, Vector2f coord) {
	switch (name) {
	case staticPlatform:
		return new StaticPlatform("staticPlatform.png",coord);
	case movingPlatform:
		return new MovingPlatform("movingPlatform.png", coord);
	case crashPlatform:
		return new CrashPlatform("crashPlatform.png",coord);
	}
}


Platform** PlatformFactory::getRandomPlatforms() {
	Platform** platforms = new Platform*[count];
	float randX, randY;
	float upperBound = 0;
	float h = Game::heightWindow / 4;

	for (int i = 0; i < count; i++) {
		if (i % 2 == 0 && i != 0) upperBound += h;

		randX = rand() % (Game::widthWindow - 90);
		randY = rand() % ((int) h);

		platforms[i] = getPlatform(getRandomType(30, 20), { randX, upperBound + randY });		
	}

	return platforms;
}

Platform* PlatformFactory::getRandomPlatformX(float y) { 
	float randX = rand() % (Game::widthWindow - 90);
	return getPlatform(getRandomType(30,20), { randX,y });
}

PlatformType PlatformFactory::getRandomType(int probabilityMovingPlatform, int probabilityCrashPlatform) {
	int randNumber = rand() % 100;
	int t = probabilityCrashPlatform + probabilityCrashPlatform;

	if (t > 100) return staticPlatform;

	if (randNumber > 100-t) {
		if (randNumber > 100-probabilityMovingPlatform) { return movingPlatform; }
		else { return crashPlatform; }
	}
	else { return staticPlatform; }
}
