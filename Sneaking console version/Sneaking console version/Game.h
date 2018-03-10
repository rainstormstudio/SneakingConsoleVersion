#pragma once
#include <iostream>
#include <chrono>
#include <cstdint>
#include <thread>
#include "Graphics.h"
#include "KeyInput.h"
#include "Player.h"

class Game {
private:
	int screen_width;
	int screen_height;
	Graphics* gfx;
	KeyInput* keys;
	Player* player;
public:
	Game(int initWidth, int initHeight);
	~Game();
	void update(int delta);
	void render();
};