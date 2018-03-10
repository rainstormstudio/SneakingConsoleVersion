#include "Player.h"

Player::Player(char initAppearance, int initColor, int initX, int initY, float initSpeed)
{
	appearance = initAppearance;
	color = initColor;
	posX = initX;
	posY = initY;
	speed = initSpeed;
}

Player::~Player()
{
}

void Player::move(KeyInput* keys, int deltatime, int screen_width, int screen_height)
{
	if (keys->isUpKeyDown())
		if (keys->isShiftDown())
			posX -= speed * 2;
		else
			posX -= speed;
	if (keys->isDownKeyDown())
		if (keys->isShiftDown())
			posX += speed * 2;
		else
			posX += speed;
	if (keys->isLeftKeyDown())
		if (keys->isShiftDown())
			posY -= speed * 2;
		else
			posY -= speed;
	if (keys->isRightKeyDown())
		if (keys->isShiftDown())
			posY += speed * 2;
		else
			posY += speed;
	if (posX <= 0) posX = 1;
	if (posX >= screen_height) posX = screen_height - 1;
	if (posY <= 0) posY = 0;
	if (posY >= screen_width) posY = screen_width - 1;
}

void Player::draw(Graphics* gfx)
{
	gfx->drawSpot(appearance, color, posX, posY);
}
