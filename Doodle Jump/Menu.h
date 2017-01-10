#pragma once
#include "Entity.h"


class Menu : public Entity {
	enum Buttons { PLAY, RECORDS, EXIT, NOTHING };
	Buttons button;

	Texture texture;
	Sprite sprRecord;

	Font font;
	Text textBestScore;
	std::ifstream fin;
	int bestScore;
public:
	Menu();	
	bool start(RenderWindow& window);
};