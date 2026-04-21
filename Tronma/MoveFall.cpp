#include "MoveFall.h"

MoveFall::MoveFall(Player* player, float* dt, float* NItime)
{
	p_dt = dt;
	p_op_num = &player->op_num;
	p_NItime = NItime;

	p_y = &player->y;
	y_speed = &player->ySpeed;
	p_energy = &player->energy;
}

bool MoveFall::isReady()
{
	if (*p_NItime == 0 && *p_energy >= needEnergy && notUsing == true && windDown <= 0) {
		if (*p_y != commomY) {
			switch (*p_op_num) {
			case 0:
			case 11:
			case 12:
			case 13:
			case 41:
			case 42:
			case 43:
				return true;
				break;
			}
		}
	}
	return false;
}

void MoveFall::effect()
{
	notUsing = false;
	*p_op_num = 2;
	*p_energy -= needEnergy;
	*p_NItime = -1;
	*y_speed = 30000 * *p_dt;
}

void MoveFall::isOver()
{
	*p_op_num = 0;
	windDown = 0;
	*p_NItime = 0;
	*p_y = commomY;
	*y_speed = 0;
	notUsing = true;
}

void MoveFall::run()
{
	if (notUsing == false) {
		if (*p_y >= commomY) {
			isOver();
		}
	}
}
