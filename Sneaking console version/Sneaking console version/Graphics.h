#pragma once
#include <windows.h>
#include <iostream>
#include <string>

class Graphics {
private:
	int screen_width;
	int screen_height;
	HANDLE consoleHandle;
	char foreground[500][500];
	int color[500][500];

public:
	Graphics(int width, int height);				// constructor
	~Graphics();									// destructor
	void clear();									// clear
	void render();									// render the frame
	void drawSpot(char value, int initColor, int posX, int posY);
	void drawRect(int initColor, int left, int top, int right, int bottom);
	void drawText(std::string text, int initColor, int start_x, int start_y, int length);
};