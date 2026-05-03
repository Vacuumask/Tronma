#include"SkillTeleport.h"

SkillTeleport::SkillTeleport(Player* player, float* dt, float* NItime)
{
	needEnergy = 20;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_NItime = NItime;

	p_x = &player->x;
	p_y = &player->y;
	p_energy = &player->energy;

	canBeDamaged = &player->canBeDamaged;
}

bool SkillTeleport::isReady()
{
	if (notUsing == true && windDown <= 0 && cd <= 0) {
		if ((ableBack == false && *p_energy >= needEnergy) || ableBack == true) {
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

void SkillTeleport::effect()
{
	notUsing = false;
	*canBeDamaged = false;
	time = 0.8;
	*p_NItime = time;
	if (ableBack == false) {
		*p_energy -= needEnergy;
		*p_op_num = 61;
	}
	else {
		*p_op_num = 62;
	}
}

void SkillTeleport::isOver()
{
	*p_op_num = (*p_y < commomY ? 11 : 0);
	time = 0;
	*p_NItime = 0;
	notUsing = true;
	*canBeDamaged = true;
	if (ableBack == false) {
		ableBack = true;
	}
	else {
		ableBack = false;
		cd = 10;
	}	
}

void SkillTeleport::run()
{
	if (notUsing == false) {
		if (time > 0) {
			time -= *p_dt;
			if (ableBack == false) {
				if (time <= 0.4 && *p_x == 100) {
					*p_x = 400;
				}
			}
			else {
				if (time <= 0.4 && *p_x == 400) {
					*p_x = 100;
				}
			}
		}
		else {
			isOver();
		}
	}
}

void SkillTeleport::reset()
{
	isOver();
	ableBack = false;
}
