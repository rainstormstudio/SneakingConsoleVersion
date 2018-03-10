#include "Enemy.h"

void Enemy::setFacing()
{
	if (facing == UP)
		appearance = '^';
	if (facing == DOWN)
		appearance = '_';
	if (facing == LEFT)
		appearance = '<';
	if (facing == RIGHT)
		appearance = '>';
}

void Enemy::setColor()
{
	if (state == NORMAL)
		color = 26;
	if (state == CAUTION)
		color = 228;
	if (state == WARNING)
		color = 204;
}

void Enemy::setRoutine(int left, int top, int right, int bottom)
{
	routine_LEFT = left;
	routine_TOP = top;
	routine_RIGHT = right;
	routine_BOTTOM = bottom;
	posX = routine_TOP;
	posY = routine_LEFT;
	routine_direction = 1;
}

void Enemy::see(int target_x, int target_y)
{
	int prev_state = state;
	if (state == NORMAL || state == CAUTION) {
		if (facing == UP) {
			if (posX - VIEW_HEIGHT <= target_x && target_x <= posX - WARN_HEIGHT
				&& posY - VIEW_WIDTH / 2 <= target_y && target_y <= posY + VIEW_WIDTH / 2)
				state = CAUTION;
			else if (posX - WARN_HEIGHT <= target_x && target_x < posX
				&& posY - WARN_WIDTH / 2 <= target_y && target_y <= posY + WARN_WIDTH / 2)
				state = WARNING;
		}
		else if (facing == DOWN) {
			if (posX + WARN_HEIGHT <= target_x && target_x <= posX + VIEW_HEIGHT
				&& posY - VIEW_WIDTH / 2 <= target_y && target_y <= posY + VIEW_WIDTH / 2)
				state = CAUTION;
			else if (posX <= target_x && target_x < posX + WARN_HEIGHT
				&& posY - WARN_WIDTH / 2 <= target_y && target_y <= posY + WARN_WIDTH / 2)
				state = WARNING;
		}
		else if (facing == LEFT) {
			if (posY - VIEW_HEIGHT <= target_y && target_y <= posY - WARN_HEIGHT
				&& posX - VIEW_WIDTH / 2 <= target_x && target_x <= posX + VIEW_WIDTH / 2)
				state = CAUTION;
			else if (posY - WARN_HEIGHT <= target_y && target_y < posY
				&& posX - WARN_WIDTH / 2 <= target_x && target_x <= posX + WARN_WIDTH / 2)
				state = WARNING;
		}
		else if (facing == RIGHT) {
			if (posY + WARN_HEIGHT <= target_y && target_y <= posY + VIEW_HEIGHT
				&& posX - VIEW_WIDTH / 2 <= target_x && target_x <= posX + VIEW_WIDTH / 2)
				state = CAUTION;
			else if (posY <= target_y && target_y < posY + WARN_HEIGHT
				&& posX - WARN_WIDTH / 2 <= target_x && target_x <= posX + WARN_WIDTH / 2)
				state = WARNING;
		}
		if (state != NORMAL && prev_state == NORMAL) {
			check_x = target_x;
			check_y = target_y;
		}
	}
	else if (state == WARNING) {
		check_x = target_x;
		check_y = target_y;
	}
}

Enemy::Enemy(char initAppearance, int initColor, int initX, int initY, float initSpeed)
{
	appearance = initAppearance;
	color = initColor;
	posX = initX;
	posY = initY;
	speed = initSpeed;
	facing = DOWN;
	state = NORMAL;

	routine_LEFT = 0;
	routine_TOP = 0;
	routine_RIGHT = 1;
	routine_BOTTOM = 1;
	routine_direction = 1;

	check_x = routine_LEFT;
	check_y = routine_TOP;
}

Enemy::~Enemy()
{
}

void Enemy::move(int screen_width, int screen_height)
{
	setColor();
	if (state == NORMAL) {
		if (routine_direction == 0) {
			if (routine_TOP == posX && routine_LEFT == posY)
				routine_direction = 1;
			else {
				if (routine_TOP < posX) {
					posX -= speed;
					facing = UP;
				}
				else if (routine_TOP > posX) {
					posX += speed;
					facing = DOWN;
				}
				if (routine_LEFT < posY) {
					posY -= speed;
					facing = LEFT;
				}
				else if (routine_LEFT > posY) {
					posY += speed;
					facing = RIGHT;
				}
			}
		}
		else if (routine_direction == 1) {
			if (routine_BOTTOM == posX && routine_RIGHT == posY)
				routine_direction = 0;
			else {
				if (routine_BOTTOM < posX) {
					posX -= speed;
					facing = UP;
				}
				else if (routine_BOTTOM > posX) {
					posX += speed;
					facing = DOWN;
				}
				if (routine_RIGHT < posY) {
					posY -= speed;
					facing = LEFT;
				}
				else if (routine_RIGHT > posY) {
					posY += speed;
					facing = RIGHT;
				}
			}
		}

		if (posX <= 0) posX = 1;
		if (posX >= screen_height) posX = screen_height - 1;
		if (posY <= 0) posY = 0;
		if (posY >= screen_width) posY = screen_width - 1;
	}
	else if (state == CAUTION) {
		if (check_x == posX && check_y == posY)
			state = NORMAL;
		else {
			if (check_x < posX) {
				posX -= speed;
				facing = UP;
			}
			else if (check_x > posX) {
				posX += speed;
				facing = DOWN;
			}
			if (check_y < posY) {
				posY -= speed;
				facing = LEFT;
			}
			else if (check_y > posY) {
				posY += speed;
				facing = RIGHT;
			}
		}
		if (posX <= 0) posX = 1;
		if (posX >= screen_height) posX = screen_height - 1;
		if (posY <= 0) posY = 0;
		if (posY >= screen_width) posY = screen_width - 1;
	}
	else if (state == WARNING) {
		if (false) {

		}
		else {
			if (check_x < posX) {
				posX -= speed;
				facing = UP;
			}
			else if (check_x > posX) {
				posX += speed;
				facing = DOWN;
			}
			if (check_y < posY) {
				posY -= speed;
				facing = LEFT;
			}
			else if (check_y > posY) {
				posY += speed;
				facing = RIGHT;
			}
		}
		if (posX <= 0) posX = 1;
		if (posX >= screen_height) posX = screen_height - 1;
		if (posY <= 0) posY = 0;
		if (posY >= screen_width) posY = screen_width - 1;
	}

	setFacing();
}

void Enemy::draw(Graphics * gfx)
{
	gfx->drawSpot(appearance, color, posX, posY);
}
