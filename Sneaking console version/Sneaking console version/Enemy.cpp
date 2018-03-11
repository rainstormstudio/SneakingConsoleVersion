#include "Enemy.h"

void Enemy::setFacing()
{
	if (facing == UP)
		appearance = 'A';
	if (facing == DOWN)
		appearance = 'V';
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
		color = 96;
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
	int prev_state = 0;
	prev_state = state;
	if (state == NORMAL || state == CAUTION) {
		state = NORMAL;
		if (facing == UP) {
			if (posX - VIEW_HEIGHT <= target_x && target_x <= posX - WARN_HEIGHT
				&& posY - VIEW_WIDTH / 2 <= target_y && target_y <= posY + VIEW_WIDTH / 2) {
				state = CAUTION;
				extent = 100;
			}
			else if (posX - WARN_HEIGHT <= target_x && target_x < posX
				&& posY - WARN_WIDTH / 2 <= target_y && target_y <= posY + WARN_WIDTH / 2) {
				state = WARNING;
				extent = 200;
			}
		}
		else if (facing == DOWN) {
			if (posX + WARN_HEIGHT <= target_x && target_x <= posX + VIEW_HEIGHT
				&& posY - VIEW_WIDTH / 2 <= target_y && target_y <= posY + VIEW_WIDTH / 2){
				state = CAUTION;
				extent = 100;
			}
			else if (posX <= target_x && target_x < posX + WARN_HEIGHT
				&& posY - WARN_WIDTH / 2 <= target_y && target_y <= posY + WARN_WIDTH / 2){
				state = WARNING;
				extent = 200;
			}
		}
		else if (facing == LEFT) {
			if (posY - VIEW_HEIGHT <= target_y && target_y <= posY - WARN_HEIGHT
				&& posX - VIEW_WIDTH / 2 <= target_x && target_x <= posX + VIEW_WIDTH / 2){
				state = CAUTION;
				extent = 100;
			}
			else if (posY - WARN_HEIGHT <= target_y && target_y < posY
				&& posX - WARN_WIDTH / 2 <= target_x && target_x <= posX + WARN_WIDTH / 2){
				state = WARNING;
				extent = 200;
			}
		}
		else if (facing == RIGHT) {
			if (posY + WARN_HEIGHT <= target_y && target_y <= posY + VIEW_HEIGHT
				&& posX - VIEW_WIDTH / 2 <= target_x && target_x <= posX + VIEW_WIDTH / 2){
				state = CAUTION;
				extent = 100;
			}
			else if (posY <= target_y && target_y < posY + WARN_HEIGHT
				&& posX - WARN_WIDTH / 2 <= target_x && target_x <= posX + WARN_WIDTH / 2){
				state = WARNING;
				extent = 200;
			}
		}
		if (state != NORMAL && prev_state == NORMAL) {
			check_x = target_x;
			check_y = target_y;
		}
		else if (state == NORMAL && prev_state != NORMAL) {
			state = prev_state;
			extent -= 2;
			if (extent >= 20 && extent <= 30) facing = UP;
			if (extent >= 45 && extent <= 55) facing = LEFT;
			if (extent >= 70 && extent <= 80) facing = DOWN;
			if (extent >= 90) facing = RIGHT;
			if (extent <= 0){
				state = NORMAL; 
				extent = 0;
			}
		}
	}
	else if (state == WARNING) {
		check_x = target_x;
		check_y = target_y;
		state = NORMAL;
		if (facing == UP) {
			if (posX - VIEW_HEIGHT <= target_x && target_x <= posX - WARN_HEIGHT
				&& posY - VIEW_WIDTH / 2 <= target_y && target_y <= posY + VIEW_WIDTH / 2) {
				state = WARNING;
				extent = 200;
			}
		}
		else if (facing == DOWN) {
			if (posX + WARN_HEIGHT <= target_x && target_x <= posX + VIEW_HEIGHT
				&& posY - VIEW_WIDTH / 2 <= target_y && target_y <= posY + VIEW_WIDTH / 2) {
				state = WARNING;
				extent = 200;
			}
		}
		else if (facing == LEFT) {
			if (posY - VIEW_HEIGHT <= target_y && target_y <= posY - WARN_HEIGHT
				&& posX - VIEW_WIDTH / 2 <= target_x && target_x <= posX + VIEW_WIDTH / 2) {
				state = WARNING;
				extent = 200;
			}
		}
		else if (facing == RIGHT) {
			if (posY + WARN_HEIGHT <= target_y && target_y <= posY + VIEW_HEIGHT
				&& posX - VIEW_WIDTH / 2 <= target_x && target_x <= posX + VIEW_WIDTH / 2) {
				state = WARNING;
				extent = 200;
			}
		}
		if (state == NORMAL && prev_state != NORMAL) {
			state = prev_state;
			extent -= 2;
			if (extent <= 100) {
				state = CAUTION;
				extent = 100;
			}
		}
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
	extent = 0;

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
		if (check_x == posX && check_y == posY) {
			if (extent <= 0) {
				state = NORMAL;
				extent = 0;
			}
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
