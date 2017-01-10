#pragma once
#include "Entity.h"


class GameOver : Entity {
	enum Buttons { PLAY_AGAIN, MENU, NOTHING };
	bool isGameOver;
	Buttons button;
	Font font;
	Text textPlayerScore, textBestScore;
	std::ifstream fin;
	std::ofstream fout;
	int bestScore;
public:
	GameOver();
	bool start(RenderWindow& window, int score);
};