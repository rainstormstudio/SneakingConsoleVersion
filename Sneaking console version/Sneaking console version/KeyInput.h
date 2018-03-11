#pragma once
#include <Windows.h>

#define KEY_W	0x57
#define KEY_S	0x53
#define KEY_A	0x41
#define KEY_D	0x44

class KeyInput {
private:
	bool wKeyPressed = false;
	bool sKeyPressed = false;
	bool aKeyPressed = false;
	bool dKeyPressed = false;
	bool shiftPressed = false;
	bool escapePressed = false;

	bool wKeyReleased = false;
	bool sKeyReleased = false;
	bool aKeyReleased = false;
	bool dKeyReleased = false;
	bool shiftReleased = false;
	bool escapeReleased = false;

	bool convert(short value);

public:
	KeyInput();
	~KeyInput();

	bool isUpKeyDown();
	bool isDownKeyDown();
	bool isLeftKeyDown();
	bool isRightKeyDown();
	bool isShiftDown();
	bool isESCDown();

	bool isUpKeyUp();
	bool isDownKeyUp();
	bool isLeftKeyUp();
	bool isRightKeyUp();
	bool isShiftUp();
	bool isESCUp();

	void update();
};