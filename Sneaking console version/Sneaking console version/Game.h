#pragma once
#include <iostream>
#include <chrono>
#include <cstdint>
#include <thread>
#include "Graphics.h"
#include "KeyInput.h"
#include "Player.h"
#include "Enemy_Group.h"
#include "Enemy.h"
#include "HUD.h"

class Game {
private:
	const int NORMAL	= 0;
	const int CAUTION	= 1;
	const int WARNING	= 2;

	int screen_width;
	int screen_height;
	Graphics* gfx;
	KeyInput* keys;
	Player* player;
	HUD* hud;
	int state;

	Enemy_Group* enemy_group;
public:
	Game(int initWidth, int initHeight);
	~Game();
	void update(int delta);
	void render();
	void pause_screen();
};