#include "Hero.h"
#include "Platform.h"
#include "Game.h"


Hero::Hero() : Entity("hero.png", { 250,150 }) {
	state = STAY;
	dx = 0.3;
	dy = 0;

	//Подключение звуков
	bufferJump.loadFromFile("sounds/jump.wav");
	soundJump.setBuffer(bufferJump);

	bufferCrashPlatform.loadFromFile("sounds/crash.wav");
	soundCrashPlatform.setBuffer(bufferCrashPlatform);

	bufferGameOver.loadFromFile("sounds/gameOver.wav");
	soundGameOver.setBuffer(bufferGameOver);
}

void Hero::update(float time) {
	control();
	if (state == LEFT) coord.x += -dx*time;
	if (state == RIGHT) coord.x += dx*time;

	dy += 0.0008*time;
	coord.y += dy*time;
	
	//телепортация
	if (coord.x > Game::widthWindow + 10) coord.x = -height - 10;
	if (coord.x < -height - 10) coord.x = Game::widthWindow + 10;

	if (scoreHero == 0 && coord.y > Game::heightWindow-height) dy = -0.8;	

	sprite.setPosition(coord);
	state = STAY;
}

void Hero::control() {
	if (Keyboard::isKeyPressed(Keyboard::Left)) { state = LEFT; }
	if (Keyboard::isKeyPressed(Keyboard::Right)) { state = RIGHT; }
}


bool Hero::coolisionWithPlatform(Platform& plat) {
	if (dy > 0 && 
		coord.x + width  >= plat.getCoord().x					&&
		coord.x + 20	 <= plat.getCoord().x + plat.getWidth() &&
		coord.y + height >= plat.getCoord().y					&&
		coord.y + height <= plat.getCoord().y + plat.getHeight())
	{
		dy = -0.6;
		if (plat.getName() == crashPlatform) {
			plat.kill();
			soundCrashPlatform.play();
		}
		else soundJump.play();

		return true;
	}
	return false;
}


float Hero::unnecessaryMovement() {
	if (coord.y < barrier) {
		coord.y = barrier;
		scoreHero -= dy;
		return -dy;
	}
	else return 0;
}

bool Hero::isLive()  {
	if (coord.y < Game::heightWindow) {
		return true;
	}
	else { 
		soundGameOver.play();
		while (soundGameOver.getStatus() == Sound::Playing) {}
		return false; 
	}
}

float Hero::score() const { return scoreHero; }