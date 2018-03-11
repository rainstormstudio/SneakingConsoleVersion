#include "Game.h"
#define FPS 10

Game::Game(int initWidth, int initHeight)
{	
	using namespace std;
	using namespace std::chrono;

	system_clock::time_point time_a = system_clock::now();
	system_clock::time_point time_b = system_clock::now();

	screen_width = initWidth;
	screen_height = initHeight;
	gfx = new Graphics(screen_width, screen_height);
	keys = new KeyInput();
	player = new Player(L'O', 43, screen_width / 2, screen_height / 2, 1);
	enemy_group = new Enemy_Group(2, screen_width, screen_height);
	hud = new HUD();
	state = NORMAL;

	bool gameloop = TRUE;
	bool pause = FALSE;
	bool pause_delay = FALSE;
	bool unpause_delay = FALSE;

	while (gameloop) {
		// FPS processing
		time_a = system_clock::now();
		duration<double, milli> delta = time_a - time_b;
		if (delta.count() < 1000 / FPS) {
			duration<double, milli> delta_ms(1000 / FPS - delta.count());
			auto delta_ms_duration = duration_cast<milliseconds>(delta_ms);
			this_thread::sleep_for(milliseconds(delta_ms_duration.count()));
		}
		time_b = system_clock::now();
		duration<double, milli> sleep_time = time_b - time_a;

		if (pause == FALSE) {

			update((delta + sleep_time).count());
			render();

			keys->update();
			if (keys->isESCDown() && unpause_delay == FALSE) {
				pause = TRUE;
				pause_delay = TRUE;
			}
			if (keys->isESCUp())
				unpause_delay = FALSE;
		}
		else {
			pause_screen();

			keys->update();
			if (keys->isESCDown() && pause_delay == FALSE) {
				pause = FALSE;
				unpause_delay = TRUE;
			}
			if (keys->isESCUp())
				pause_delay = FALSE;
		}

		std::cout << " FPS " << (1000 / (delta + sleep_time).count());
	}
}

Game::~Game()
{
}

void Game::update(int delta)
{
	keys->update();
	player->move(keys, delta, screen_width, screen_height);
	enemy_group->update(player->posX, player->posY, screen_width, screen_height);
	state = enemy_group->state;
}

void Game::render()
{
	gfx->clear();
	player->draw(gfx);
	enemy_group->draw(gfx);
	hud->update(state, enemy_group->extent, player->strength, player->strength_usable, gfx, screen_width, screen_height);
	gfx->render();
}

void Game::pause_screen()
{
	gfx->clear();
	gfx->drawRect(0, 0, 0, screen_width, screen_height);
	gfx->render();
}
