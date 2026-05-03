#include "SkillSlow.h"

SkillSlow::SkillSlow(Player* player, float* speed, float* dt, float* NItime)
{
	needEnergy = 20;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_speed = speed;
	p_NItime = NItime;
	p_energy = &player->energy;
}

bool SkillSlow::isReady()
{
	if (*p_energy >= needEnergy && notUsing == true && windDown <= 0 && cd <= 0) {
		switch (*p_op_num) {
		case 0:
		case 11:
		case 12:
		case 13:
		case 14:
		case 41:
		case 42:
		case 43:
		//case 8:
			return true;
			break;
		}
	}
	return false;
}

void SkillSlow::effect()
{
	notUsing = false;
	time = 1.5;
	*p_energy -= needEnergy;
	temp_op = *p_op_num;
	*p_speed /= 5;
}

void SkillSlow::isOver()
{
	notUsing = true;
	cd = 5;
	*p_speed *= 5;
	MusicPlayer::reset();
	//MusicPlayer::isSlowing = false;
}

void SkillSlow::run()
{
	if (notUsing == false) {
		if (time > 0 && (temp_op == *p_op_num || *p_op_num == 0 || *p_op_num == 12 || *p_op_num == 13)) {
			time -= *p_dt;
			MusicPlayer::slow();
		}
		else {
			isOver();
		}
	}

	temp_op = *p_op_num;
}

void SkillSlow::reset()
{
	isOver();
	temp_op = 0;
}
