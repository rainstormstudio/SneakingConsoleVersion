#pragma once
#include "Graphics.h"
#include <string>

class HUD {
private:
	const int NORMAL = 0;
	const int CAUTION = 1;
	const int WARNING = 2;

public:
	void update(int state, Graphics* gfx, int screen_width, int screen_height);
};