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
	enemy_group = new Enemy_Group(4, screen_width, screen_height);
	hud = new HUD();
	state = NORMAL;

	bool gameloop = TRUE;

	while (gameloop) {
		time_a = system_clock::now();
		duration<double, milli> delta = time_a - time_b;

		if (delta.count() < 1000 / FPS) {
			duration<double, milli> delta_ms(1000 / FPS - delta.count());
			auto delta_ms_duration = duration_cast<milliseconds>(delta_ms);
			this_thread::sleep_for(milliseconds(delta_ms_duration.count()));
		}
		time_b = system_clock::now();
		duration<double, milli> sleep_time = time_b - time_a;

		update((delta + sleep_time).count());
		render();

		cout << " FPS " << (1000 / (delta + sleep_time).count());
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
	hud->update(state, enemy_group->extent, gfx, screen_width, screen_height);
	gfx->render();
}
