#include"SkillShadow.h"

SkillShadow::SkillShadow(Player* player, Player* shadow, float* speed, float* dt, float* NItime)
{
	needEnergy = 30;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_NItime = NItime;

	p_x = &player->x;
	p_y = &player->y;
	p_width = &player->c_width;
	p_height = &player->c_height;
	p_health = &player->health;
	p_energy = &player->energy;
	p_die = &player->die;
	p_canBeDamaged = &player->canBeDamaged;

	this->shadow = shadow;
	shadow->health = 0;
	this->p_speed = speed;
}

void SkillShadow::loadPicture() {

}

bool SkillShadow::isReady()
{
	if (*p_energy >= needEnergy && notUsing == true && windDown <= 0 && cd <= 0) {
		if (*p_y == commomY) {
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

void SkillShadow::effect()
{
	notUsing = false;
	shadow->x = *p_x;
	shadow->y = commomY;
	shadow->health = 1;
	shadow->op_num = 92;
	time = 8;
	*p_energy -= needEnergy;
	*p_op_num = 91;
}

void SkillShadow::isOver()
{
	shadow->y = -150;
	shadow->health = 0;
	cd = 10;
	notUsing = true;
}

void SkillShadow::run()
{
	if (notUsing == false) {
		if (*p_op_num == 91)*p_op_num = (*p_y < commomY ? 13 : 0);
		if (time > 0 && shadow->health != 0) {
			time -= *p_dt;
			if (shadow->x > 0) {
				shadow->x -= shadow->x * *p_dt * *p_speed / 100;
			}
			if (*p_op_num == 3) {
				shadow->op_num = 93;
			}
			else {
				shadow->op_num = 92;
			}
			shadow->animationPlayerRun();
		}
		else {
			if (shadow->health != 0 && *p_health != 7) {
				*p_health += 1;
			}
			if (shadow->health != 0 && *p_die == true) {
				*p_die = false;
				*p_canBeDamaged = true;
				*p_op_num = 0;
			}
			isOver();
		}
	}
}

void SkillShadow::reset()
{
	isOver();
}
