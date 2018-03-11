#pragma once
#include "Enemy.h"
#include <math.h>

class Enemy_Group {
private:
	const int NORMAL = 0;
	const int CAUTION = 1;
	const int WARNING = 2;

public:
	Enemy * obj[20];
	int num;
	int state;
	int extent;

	Enemy_Group(int total, int screen_width, int screen_height);
	~Enemy_Group();
	void update(int target_x, int target_y, int screen_width, int screen_height);
	void draw(Graphics* gfx); 
	int randInt(int min, int max);
};