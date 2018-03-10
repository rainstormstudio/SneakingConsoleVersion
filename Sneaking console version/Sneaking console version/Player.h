#pragma once
#include "KeyInput.h"
#include "Graphics.h"

class Player {
private:
	float speed;
	char appearance;
	int color;

public:
	int posX;
	int posY;
	Player(char initAppearance, int color, int initX, int initY, float initSpeed);
	~Player();
	void move(KeyInput* keys, int deltatime, int screen_width, int screen_height);
	void draw(Graphics* gfx);
};