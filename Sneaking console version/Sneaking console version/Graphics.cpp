#include "Graphics.h"

Graphics::Graphics(int width, int height)
{
	screen_width = width;
	screen_height = height;
	AllocConsole();
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTitle(L"Sneaking console version");	// the title of the window

	// window setting
	SMALL_RECT window_rect;
	window_rect.Left = 0;
	window_rect.Top = 0;
	window_rect.Right = screen_width;
	window_rect.Bottom = screen_height;
	SetConsoleWindowInfo(consoleHandle, TRUE, &window_rect);

	// buffer setting
	COORD buffer_size;
	buffer_size.X = screen_width;
	buffer_size.Y = screen_height;
	SetConsoleScreenBufferSize(consoleHandle, buffer_size);

	// font setting
	CONSOLE_FONT_INFOEX font_info = { 0 };
	font_info.cbSize = sizeof(font_info);
	font_info.nFont = 0;
	font_info.dwFontSize.X = 8;
	font_info.dwFontSize.Y = 8;
	font_info.FontFamily = FF_DONTCARE;
	font_info.FontWeight = 600;//FW_NORMAL;
	SetCurrentConsoleFontEx(consoleHandle, FALSE, &font_info);

	// cursor setting
	CONSOLE_CURSOR_INFO cursor_set;
	cursor_set.dwSize = 50;
	cursor_set.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &cursor_set); 
	SetConsoleMode(consoleHandle, ENABLE_EXTENDED_FLAGS);

	// initialize the foreground and color
	for (int i = 0; i < screen_height; i++)
		for (int j = 0; j < screen_width; j++) {
			foreground[i][j] = L' ';
			color[i][j] = 7;
		}
}

Graphics::~Graphics()
{
}

void Graphics::clear()
{
	for (int i = 0; i < screen_height; i++)
		for (int j = 0; j < screen_width; j++) {
			foreground[i][j] = L' ';
			color[i][j] = 136;
		}
}

void Graphics::render()
{
	COORD cursor_pos = { 0,0 };
	SetConsoleCursorPosition(consoleHandle, cursor_pos);
	SetConsoleTextAttribute(consoleHandle, 7);
	for (int i = 0; i < screen_height; i++) {
		for (int j = 0; j < screen_width; j++) {
			SetConsoleTextAttribute(consoleHandle, color[i][j]);
			std::cout << foreground[i][j];
		}
		std::cout << "\n";
	}
	SetConsoleTextAttribute(consoleHandle, 7);
}

void Graphics::drawSpot(char value, int initColor, int posX, int posY)
{
	foreground[posX][posY] = value;
	color[posX][posY] = initColor;
}

void Graphics::drawRect(int initColor, int left, int top, int right, int bottom)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			color[i][j] = initColor;
}

void Graphics::drawText(std::string text, int initColor, int start_x, int start_y, int length)
{
	int i = start_x;
	int len = text.length();
	if (length < len)
		length = len;
	int count = 0;
	for (int j = start_y; j <= start_y + length; j ++){
		color[i][j] = initColor;
		if (count < len) {
			foreground[i][j] = text[count];
			count++;
		}
	}
}


