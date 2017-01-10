#include "GameOver.h"

GameOver::GameOver() : Entity("gameOver.png", { 0,0 }), fin("record.txt") {
	//Загрузка шрифта
	font.loadFromFile("font.ttf");

	//Загрузка текста для вывода счета игрока
	textPlayerScore.setPosition({ 263,208 });
	textPlayerScore.setCharacterSize(23);
	textPlayerScore.setFont(font);
	textPlayerScore.setColor({ 200,36,23 });
	textPlayerScore.setStyle(Text::Bold);

	//Загрузка текста для вывода рекорда
	textBestScore.setPosition({ 205,273 });
	textBestScore.setCharacterSize(23);
	textBestScore.setFont(font);
	textBestScore.setColor({ 46,37,95 });
	textBestScore.setStyle(Text::Bold);

	fin >> bestScore;
	fin.close();
}


bool GameOver::start(RenderWindow& window, int score) {
	isGameOver = true;
	button = NOTHING;
	//Перезапись файла при установлении нового рекорда
	if (score > bestScore) {
		fout.open("record.txt");
		fout.clear();
		fout << score;
		bestScore = score;
		fout.close();
	}
	//Преобразование счета и рекорда к текстовому типу
	std::ostringstream playerScoreString, bestScoreString;
	playerScoreString << score;
	bestScoreString << bestScore;
	textPlayerScore.setString(playerScoreString.str());
	textBestScore.setString(bestScoreString.str());

	while (isGameOver) {
		//Выход из окна по нажатию на крестик
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}	window.clear();

		//Проверка наведения курсора на кнопки
		if (IntRect(103, 386, 164, 60).contains(Mouse::getPosition(window))) { button = PLAY_AGAIN; }
		if (IntRect(289, 480, 164, 60).contains(Mouse::getPosition(window))) { button = MENU; }

		//Проверка нажатия левой кнопки мыши на кнопки
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (button == PLAY_AGAIN) { return true; }
			if (button == MENU) { return false; }
		}

		//Вывод
		window.clear();
		window.draw(sprite);
		window.draw(textPlayerScore);
		window.draw(textBestScore);
		window.display();
	}
}