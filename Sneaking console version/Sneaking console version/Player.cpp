#include "Player.h"

Player::Player(char initAppearance, int initColor, int initX, int initY, float initSpeed)
{
	appearance = initAppearance;
	color = initColor;
	posX = initX;
	posY = initY;
	speed = initSpeed;
	strength = 100;
	strength_usable = true;
}

Player::~Player()
{
}

void Player::move(KeyInput* keys, int deltatime, int screen_width, int screen_height)
{
	if (keys->isShiftDown() && strength_usable){
		strength -= 5;
		if (strength <= 0) {
			strength = 0;
			strength_usable = false;
		}
	}
	else{
		strength += 2;
		if (strength >= 100) {
			strength = 100;
			strength_usable = true;
		}
	}

	if (keys->isUpKeyDown())
		if (keys->isShiftDown() && strength_usable) 
			posX -= speed * 2;
		else 
			posX -= speed;
	if (keys->isDownKeyDown())
		if (keys->isShiftDown() && strength_usable)
			posX += speed * 2;
		else
			posX += speed;
	if (keys->isLeftKeyDown())
		if (keys->isShiftDown() && strength_usable)
			posY -= speed * 2;
		else
			posY -= speed;
	if (keys->isRightKeyDown())
		if (keys->isShiftDown() && strength_usable)
			posY += speed * 2;
		else
			posY += speed;

	if (posX <= 1) posX = 2;
	if (posX >= screen_height) posX = screen_height - 1;
	if (posY <= 0) posY = 0;
	if (posY >= screen_width) posY = screen_width - 1;
}

void Player::draw(Graphics* gfx)
{
	gfx->drawSpot(appearance, color, posX, posY);
}
