#pragma once
#include "Graphics.h"

class Enemy {
private:
	const int UP	= 0;
	const int DOWN	= 1;
	const int LEFT	= 2;
	const int RIGHT = 3;

	const int NORMAL		= 0;
	const int CAUTION		= 1;
	const int WARNING		= 2;
	const int VIEW_WIDTH	= 3;
	const int VIEW_HEIGHT	= 10;
	const int WARN_WIDTH	= 3;
	const int WARN_HEIGHT	= 6;

	int posX;
	int posY;
	float speed;
	char appearance;
	int facing;
	int color;

	int routine_LEFT;
	int routine_TOP;
	int routine_RIGHT;
	int routine_BOTTOM;
	int routine_direction;

	int check_x;
	int check_y;

	void setFacing();
	void setColor();

public:
	int extent;
	int state;

	Enemy(char initAppearance, int initColor, int initX, int initY, float initSpeed);
	~Enemy();
	void setRoutine(int left, int top, int right, int bottom);
	void see(int target_x, int target_y);
	void move(int screen_width, int screen_height);
	void draw(Graphics* gfx);
};