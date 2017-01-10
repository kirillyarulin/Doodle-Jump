#pragma once
#include "Entity.h"
//#include "Hero.h"


class Score : Entity {
	Font font;
	Text text;
public:
	Score();
	void draw(RenderWindow& window, int score);
};