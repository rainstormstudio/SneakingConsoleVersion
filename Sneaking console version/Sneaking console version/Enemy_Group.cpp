#include "Enemy_Group.h"

Enemy_Group::Enemy_Group(int total, int screen_width, int screen_height)
{
	num = total;
	int quadrant_x = round(sqrt(total));
	int quadrant_y = total / quadrant_x;
	int count = 0;
	for (int i = 0; i < quadrant_x; i ++)
		for (int j = 0; j < quadrant_y; j++) {
			if (count < num) {
				int temp_x = randInt((screen_height / quadrant_x) * i, (screen_height / quadrant_x) * (i + 1));
				int temp_y = randInt((screen_width / quadrant_y) * j, (screen_width / quadrant_y) * (j + 1));
				obj[count] = new Enemy('A', 26, temp_x, temp_y, 1);
				obj[count]->setRoutine(temp_y, temp_x,
					randInt((screen_height / quadrant_x) * i, (screen_height / quadrant_x) * (i + 1)),
					randInt((screen_width / quadrant_y) * j, (screen_width / quadrant_y) * (j + 1)));
				//obj[count]->setRoutine(i*5 + 10, i*5 + 10, j * 4, j * 4 + 20);
				count++;
			}
		}
}

Enemy_Group::~Enemy_Group()
{
}

void Enemy_Group::update(int target_x, int target_y, int screen_width, int screen_height)
{
	extent = 0;
	state = NORMAL;
	for (int i = 0; i < num; i++) {
		obj[i]->see(target_x, target_y);
		if (obj[i]->state == CAUTION && state != WARNING)
			state = CAUTION;
		else if (obj[i]->state == WARNING)
			state = WARNING;
		if (obj[i]->extent > extent)
			extent = obj[i]->extent;
	}
	if (state == WARNING) {
		for (int i = 0; i < num; i++) {
			obj[i]->state = state;
			obj[i]->extent = extent;
		}
	}
	for (int i = 0; i < num; i ++)
		obj[i]->move(screen_width, screen_height);
}

void Enemy_Group::draw(Graphics * gfx)
{
	for (int i = 0; i < num; i++)
		obj[i]->draw(gfx);
}

int Enemy_Group::randInt(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

