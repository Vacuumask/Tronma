#include "MoveSprint.h"

MoveSprint::MoveSprint(Player* player, float* speed, float* dt, float* NItime)
{
	needEnergy = 2;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_speed = speed;
	p_NItime = NItime;

	p_y = &player->y;
	p_energy = &player->energy;
}

bool MoveSprint::isReady()
{
	if (*p_energy >= needEnergy && notUsing == true && windDown <= 0) {
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
	return false;
}

void MoveSprint::effect()
{
	notUsing = false;
	*p_op_num = 3;
	*p_energy -= needEnergy;
	time = 0.3;
	windDown = 0.1;
	*p_NItime = time;
	*p_speed *= 2;
	//std::cout << *p_speed;
}

void MoveSprint::isOver()
{
	*p_op_num = (*p_y < commomY ? 11 : 0);
	time = 0;
	*p_NItime = 0;
	*p_speed /= 2;
	notUsing = true;
	//std::cout << *p_speed;

}

void MoveSprint::run()
{
	if (notUsing == false) {
		if (time > 0) {
			time -= *p_dt;
		}
		else {
			isOver();
		}
	}
	else {
		if (windDown > 0) {
			windDown -= *p_dt;
		}
	}
}
