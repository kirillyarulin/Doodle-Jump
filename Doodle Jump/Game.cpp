#include "Game.h"
#include "PlatformFactory.h"
#include <iostream>

Game::Game() :	window(sf::VideoMode(widthWindow, heightWindow), "Doodle Jump") {}

bool Game::startGame() {
	if (!menu.start(window)) return false;

	while (gameOver.start(window, run())) {}
	return true;
}

int Game::run() {
	Clock clock;
	srand(time(0));	
	Platform** platforms = PlatformFactory::getRandomPlatforms();
	Hero hero;
	float speedGame = 600;
	float tempY;
	
	while (window.isOpen())
	{
		//�������� �� �������
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / speedGame;

		//����� �� ���� �� ������� �� �������
		Event event;
		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		hero.update(time);

		dY = hero.unnecessaryMovement();

		for (int i = 0; i < PlatformFactory::count; i++) {
			(*platforms[i]).update(time,dY);

			//��������� ����
			if (hero.coolisionWithPlatform(*platforms[i]) && speedGame > 200) { speedGame--; }

			//�������� ����� �������� � �������� ������
			if ((*platforms[i]).getCoord().y >= heightWindow || !(*platforms[i]).isLive()) {
				tempY = (*platforms[i]).getCoord().y;
				delete platforms[i];
				platforms[i] = PlatformFactory::getRandomPlatformX(tempY - heightWindow);
			}
		}
		
		//����� 
		window.clear();
		map.draw(window);
		for (int i = 0; i < PlatformFactory::count; i++) (*platforms[i]).draw(window);
		hero.draw(window);
		score.draw(window, hero.score());
		window.display();
		
		//�������� �� ��������
		if (hero.isLive() == false) {
			for (int i = 0; i < PlatformFactory::count; i++) delete platforms[i];
			return hero.score();
		}
	}
}