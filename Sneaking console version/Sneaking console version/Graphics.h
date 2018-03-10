#pragma once
#include <windows.h>
#include <string>

class Graphics {
private:
	int screen_width;
	int screen_height;
	HANDLE consoleHandle;
	char foreground[500][500];

public:
	Graphics(int width, int height);				// constructor
	~Graphics();									// destructor
	void clear();									// clear
	void render();									// render the frame
	void drawSpot(char value, int posX, int posY);
};