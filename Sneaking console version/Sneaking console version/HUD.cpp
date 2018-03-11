#include "HUD.h"

void HUD::update(int state, int extent, int strength, int strength_usable, Graphics* gfx, int screen_width, int screen_height)
{
	std::string temp = "";
	int temp_color = 7;
	if (state == NORMAL) { temp = " NORMAL "; temp_color = 58; }
	else if (state == CAUTION) { temp = " CAUTION"; temp_color = 110; }
	else if (state == WARNING) { temp = " WARNING"; temp_color = 76; }
	gfx->drawText(temp, temp_color, 0, 0, 10);

	int level = screen_width - 10;
	int level_extent = extent;
	int back_color = 120;
	if (state == NORMAL) temp_color = 120;
	else if (state == CAUTION) temp_color = 239;
	else if (state == WARNING) { temp_color = 205; level_extent -= 100; back_color = 239; }
	level_extent = round(level_extent / 100.0 * level);
	gfx->drawRect(temp_color, 11, 0, 11 + level_extent, 0);
	gfx->drawRect(back_color, 12 + level_extent, 0, screen_width, 0);

	gfx->drawText(" STRENGTH", 158, 1, 0, 10);
	if (strength_usable)
		gfx->drawRect(34, 11, 1, 11 + round(strength / 100.0 * level), 1);
	else
		gfx->drawRect(255, 11, 1, 11 + round(strength / 100.0 * level), 1);
	gfx->drawRect(0, 12 + round(strength / 100.0 * level), 1, screen_width, 1);
}
