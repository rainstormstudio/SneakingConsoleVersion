#pragma once
#include "KeyInput.h"
#include "Graphics.h"

class Player {
private:
	int posX;
	int posY;
	float speed;
	char appearance;

public:
	Player(char initAppearance, int initX, int initY, float initSpeed);
	~Player();
	void move(KeyInput* keys, int deltatime);
	void draw(Graphics* gfx);
};