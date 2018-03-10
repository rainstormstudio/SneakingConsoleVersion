#include "HUD.h"

void HUD::update(int state, Graphics* gfx, int screen_width, int screen_height)
{
	std::string temp = "";
	int temp_color = 7;
	if (state == NORMAL) { temp = " NORMAL "; temp_color = 58; }
	else if (state == CAUTION) { temp = " CAUTION"; temp_color = 110; }
	else if (state == WARNING) { temp = " WARNING"; temp_color = 76; }
	gfx->drawText(temp, temp_color, 0, 0, 9);
	gfx->drawRect(120, 10, 0, screen_width, 0);
}
