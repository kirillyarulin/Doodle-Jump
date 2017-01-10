#pragma once
#include "stdafx.h"
#include "Hero.h"
#include "Platform.h"
#include "Map.h"

#include "Score.h"
#include "Menu.h"
#include "GameOver.h"

using namespace sf;

class Game {
public:
	static const unsigned int widthWindow = 500;
	static const unsigned int heightWindow = 600;

	RenderWindow window;

	Menu menu;
	GameOver gameOver;
	Score score;

	float dY;
	Map map;

	Game();

	int run();
	bool startGame();
};
