#include "Player.h"

Player::Player(char initAppearance, int initX, int initY, float initSpeed)
{
	appearance = initAppearance;
	posX = initX;
	posY = initY;
	speed = initSpeed;
}

Player::~Player()
{
}

void Player::move(KeyInput* keys, int deltatime)
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
}

void Player::draw(Graphics* gfx)
{
	gfx->drawSpot(appearance, posX, posY);
}
