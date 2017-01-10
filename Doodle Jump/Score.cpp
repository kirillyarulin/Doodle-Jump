#include "Score.h"

Score::Score() : Entity("scoreRect.png", { 0,0 }) {
	//�������� ������ ��� ������ �����
	font.loadFromFile("font.ttf");
	text.setString("");
	text.setPosition({ 170,3 });
	text.setCharacterSize(18);
	text.setFont(font);
	text.setColor(Color::Black);
}

void Score::draw(RenderWindow& window, int score) {
	//�������������� ����� � ���������� ����
	std::ostringstream playerScoreString;
	playerScoreString << score;
	text.setString(playerScoreString.str());

	//������ �����
	window.draw(sprite);
	window.draw(text);
}