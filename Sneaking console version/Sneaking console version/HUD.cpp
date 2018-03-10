#include "HUD.h"

void HUD::update(int state, int extent, Graphics* gfx, int screen_width, int screen_height)
{
	std::string temp = "";
	int temp_color = 7;
	if (state == NORMAL) { temp = " NORMAL "; temp_color = 58; }
	else if (state == CAUTION) { temp = " CAUTION"; temp_color = 110; }
	else if (state == WARNING) { temp = " WARNING"; temp_color = 76; }
	gfx->drawText(temp, temp_color, 0, 0, 9);
	int level = screen_width - 10;
	int level_extent = extent;
	int back_color = 120;
	if (state == NORMAL) temp_color = 120;
	else if (state == CAUTION) temp_color = 239;
	else if (state == WARNING) { temp_color = 205; level_extent -= 100; back_color = 239; }
	level_extent = round(level_extent / 100.0 * level);
	gfx->drawRect(temp_color, 10, 0, 10 + level_extent, 0);
	gfx->drawRect(back_color, 11 + level_extent, 0, screen_width, 0);
}
