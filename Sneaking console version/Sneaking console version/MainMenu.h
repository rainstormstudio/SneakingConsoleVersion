#pragma once
#include "Graphics.h"
#include "KeyInput.h"
#include <string>
#include <thread>
#include <chrono>

#define MAIN_TITLE	0
#define OPTION		1
#define ABOUT		2

const std::string title[] = {
	" #### #   # #####   #   #  # ### #   #  ####",
	"#     ##  # #      # #  # #   #  ##  # #    ",
	"##### # # # ##### #   # ##    #  # # # # ###",
	"    # #  ## #     ##### # #   #  #  ## #   #",
	"####  #   # ##### #   # #  # ### #   #  ### "
};

void mainMenu(Graphics* gfx, KeyInput* keys);