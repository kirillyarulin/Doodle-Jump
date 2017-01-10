#include "Menu.h"
#include <Windows.h>

Menu::Menu() : Entity("menu.png", { 0,0 }), fin("record.txt") {
	//загрузка спрайта окошка с рекордом
	texture.loadFromFile("images/record.png");
	sprRecord.setTexture(texture);
	sprRecord.setPosition({ 85,240 });

	//загрузка текста с рекордом
	font.loadFromFile("font.ttf");
	textBestScore.setPosition({ 170,290 });
	textBestScore.setCharacterSize(40);
	textBestScore.setFont(font);
	textBestScore.setColor(Color::Red);
	textBestScore.setStyle(Text::Bold);

	fin >> bestScore;
	fin.close();
}

bool Menu::start(RenderWindow& window) {
	window.clear();
	button = NOTHING;
	while (true) {
		//преобразование рекорда к текстовому формату
		std::ostringstream bestScoreString;
		bestScoreString << bestScore;
		textBestScore.setString(bestScoreString.str());

		//Выход из окна по нажатию на крестик
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Проверка наведения курсора на кнопки
		if (IntRect(88, 185, 164, 60).contains(Mouse::getPosition(window))) { button = PLAY; }
		if (IntRect(136, 276, 164, 60).contains(Mouse::getPosition(window))) { button = RECORDS; }
		if (IntRect(304, 485, 164, 60).contains(Mouse::getPosition(window))) { button = EXIT; }

		//Проверка нажатия левой кнопки мыши на кнопки
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (button == PLAY) { return true; }
			if (button == RECORDS) { 
				window.draw(sprRecord); 
				window.draw(textBestScore); 
				window.display(); 
				while (!Keyboard::isKeyPressed(Keyboard::Escape)); 
			}
			if (button == EXIT) { window.close(); return false; }
		}

		//Вывод меню
		window.draw(sprite);
		window.display();

	}
}