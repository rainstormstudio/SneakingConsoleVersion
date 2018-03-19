#include "MainMenu.h"

void mainMenu(Graphics * gfx, KeyInput * keys)
{
	gfx->clear();
	gfx->render();

	int state = MAIN_TITLE;
	int pointer = 0;
	bool changeDown = true;
	bool changeUp = true;

	gfx->clear();
	for (int i = 0; i < 5; i++) {
		gfx->drawText(title[i], 138, 10 + i, gfx->screen_width / 2 - 22, 44);
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		gfx->render();
	}
	bool loop = true;
	while (loop) {
		if (state == MAIN_TITLE) {
			gfx->clear();
			for (int i = 0; i < 5; i++) {
				gfx->drawText(title[i], 138, 10 + i, gfx->screen_width / 2 - 22, 44);
			}
			gfx->drawText("START GAME", 129, gfx->screen_height / 2, gfx->screen_width / 2, 10);
			gfx->drawText("OPTION    ", 129, gfx->screen_height / 2 + 2, gfx->screen_width / 2, 10);
			gfx->drawText("ABOUT     ", 129, gfx->screen_height / 2 + 4, gfx->screen_width / 2, 10);
			gfx->drawText("*", 132, gfx->screen_height / 2 + pointer * 2, gfx->screen_width / 2 - 2, 1);
			gfx->render();

			keys->update();
			if (keys->isDownKeyDown()) {
				if (pointer != 2 && changeDown)
					pointer++;
				changeDown = false;
			}
			else if (keys->isDownKeyUp())
				changeDown = true;
			if (keys->isUpKeyDown()) {
				if (pointer != 0 && changeUp)
					pointer--;
				changeUp = false;
			}
			else if (keys->isUpKeyUp())
				changeUp = true;
			if (keys->isEnterDown() && pointer == 0)
				loop = false;
			if (keys->isEnterDown() && pointer == 1)
				state = OPTION;
			if (keys->isEnterDown() && pointer == 2)
				state = ABOUT;
		}
		else if (state == OPTION) {
			gfx->clear();
			gfx->render();
		}
		else if (state == ABOUT) {
			gfx->clear();
			gfx->render();
		}
	}
}
