#include "LOGO.h"

void logo(Graphics * gfx)
{
	gfx->clear();
	gfx->render();
	gfx->drawRect(255, 0, 0, gfx->screen_width, gfx->screen_height);
	gfx->drawText("     R. S.      ", 249, gfx->screen_height / 2 - 2, gfx->screen_width / 2 - 8, 16);
	gfx->render();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	gfx->drawText("     R  S       ", 249, gfx->screen_height / 2 - 2, gfx->screen_width / 2 - 8, 16);
	gfx->render();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	gfx->drawText("    RA  ST      ", 249, gfx->screen_height / 2 - 2, gfx->screen_width / 2 - 8, 16);
	gfx->render();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	gfx->drawText("   RAI  STU     ", 249, gfx->screen_height / 2 - 2, gfx->screen_width / 2 - 8, 16);
	gfx->render();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	gfx->drawText("  RAINS  STUD   ", 249, gfx->screen_height / 2 - 2, gfx->screen_width / 2 - 8, 16);
	gfx->render();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	gfx->drawText(" RAINSTR  STUDI ", 249, gfx->screen_height / 2 - 2, gfx->screen_width / 2 - 8, 16);
	gfx->render();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
	gfx->drawText("RAINSTORM STUDIO", 249, gfx->screen_height / 2 - 2, gfx->screen_width / 2 - 8, 16);
	gfx->render();
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}
