#include "KeyInput.h"

bool KeyInput::convert(short value)
{
	if (((unsigned short)value) >> 15 == 1)
		return true;
	else
		return false;
}

KeyInput::KeyInput()
{
	update();
}

KeyInput::~KeyInput()
{
}

bool KeyInput::isUpKeyDown()
{
	return wKeyPressed;
}

bool KeyInput::isDownKeyDown()
{
	return sKeyPressed;
}

bool KeyInput::isLeftKeyDown()
{
	return aKeyPressed;
}

bool KeyInput::isRightKeyDown()
{
	return dKeyPressed;
}

bool KeyInput::isShiftDown()
{
	return shiftPressed;
}

bool KeyInput::isESCDown()
{
	return escapePressed;
}

bool KeyInput::isUpKeyUp()
{
	return wKeyReleased;
}

bool KeyInput::isDownKeyUp()
{
	return sKeyReleased;
}

bool KeyInput::isLeftKeyUp()
{
	return aKeyReleased;
}

bool KeyInput::isRightKeyUp()
{
	return dKeyReleased;
}

bool KeyInput::isShiftUp()
{
	return shiftReleased;
}

bool KeyInput::isESCUp()
{
	return escapeReleased;
}

void KeyInput::update()
{
	if (convert(GetKeyState(KEY_W)) || convert(GetKeyState(VK_UP))) {
		wKeyPressed = true;
		wKeyReleased = false;
	}
	else {
		wKeyPressed = false;
		wKeyReleased = true;
	}
	if (convert(GetKeyState(KEY_S)) || convert(GetKeyState(VK_DOWN))) {
		sKeyPressed = true;
		sKeyReleased = false;
	}
	else {
		sKeyPressed = false;
		sKeyReleased = true;
	}
	if (convert(GetKeyState(KEY_A)) || convert(GetKeyState(VK_LEFT))) {
		aKeyPressed = true;
		aKeyReleased = false;
	}
	else {
		aKeyPressed = false;
		aKeyReleased = true;
	}
	if (convert(GetKeyState(KEY_D)) || convert(GetKeyState(VK_RIGHT))) {
		dKeyPressed = true;
		dKeyReleased = false;
	}
	else {
		dKeyPressed = false;
		dKeyReleased = true;
	}
	if (convert(GetKeyState(VK_SHIFT))) {
		shiftPressed = true;
		shiftReleased = false;
	}
	else {
		shiftPressed = false;
		shiftReleased = true;
	}
	if (convert(GetKeyState(VK_ESCAPE))) {
		escapePressed = true;
		escapeReleased = false;
	}
	else {
		escapePressed = false;
		escapeReleased = true;
	}
}
