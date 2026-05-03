#include "MoveJump.h"

MoveJump::MoveJump(Player* player, float* speed, float* dt, float* NItime)
{
	//needEnergy = 3;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_NItime = NItime;

	p_y = &player->y;
	p_speed = speed;
	y_speed = &player->ySpeed;
	p_energy = &player->energy;
}

bool MoveJump::isReady()
{
	if (*p_NItime == 0 && *p_energy >= needEnergy) {
		if (*p_y == commomY || ableTime == 1) {
			switch (*p_op_num) {
			case 0:
			case 11:
			case 12:
			case 13:
			case 14:
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

void MoveJump::effect()
{
	notUsing = false;
	if (ableTime == 2) {
		*p_op_num = 11;
	}
	else {
		*p_op_num = 14;
	}
	*p_energy -= needEnergy;
	*y_speed = -20;
	*p_y += *y_speed * (*p_dt) * 40;
	ableTime--;
}

void MoveJump::isOver()
{
	switch (*p_op_num) {
	case 11:
	case 12:
	case 13:
	case 14:
	//case 8:
		*p_op_num = 0;
		break;
	default:
		break;
	}
	*p_y = commomY;
	*y_speed = 0;
	ableTime = 2;
	notUsing = true;
}

void MoveJump::run()
{
	if (notUsing == false) {
		if (*p_y >= commomY) {
			isOver();
		}
		else {
			switch (*p_op_num) {
			case 11:
			case 12:
			case 13:
			case 14:
				if (*y_speed < -7) {
					if (ableTime == 1) {
						*p_op_num = 11;
					}
					else {
						*p_op_num = 14;
					}
				}
				else if (*y_speed > 7) {
					*p_op_num = 12;
				}
				else {
					*p_op_num = 13;
				}
			}
		}
	}
}

void MoveJump::countY()
{
	if (*p_y < commomY) {
		switch (*p_op_num) {
		case 11:
		case 12:
		case 13:
		case 14:
		case 2:
		case 41:
		case 42:
		case 43:
		case 8:
		case 91:
			*p_y += *y_speed * *p_speed / 300 * (*p_dt) * 40;
			*y_speed += *p_speed / 300 * (*p_dt) * 45;
			break;
		default:
			*y_speed = 0;
			break;
		}
	}
}

