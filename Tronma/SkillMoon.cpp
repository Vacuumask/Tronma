#include"SkillMoon.h"

SkillMoon::SkillMoon(Player* player, float* dt, float* NItime) {
	needEnergy = 60;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_NItime = NItime;

	p_x = &player->x;
	p_y = &player->y;
	p_energy = &player->energy;

	initAttack();

	loadPicture();
	p_animationEffect = new AnimationEffect(p_x, p_y, pictures);
	m_animationEffect = new AnimationEffect(&moon.x, &moon.y, pictures);
}

void SkillMoon::loadPicture() {
	IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6, img0_7, img0_8, img0_9, img0_10, img0_11;
	loadimage(&img0_1, "../image/effect/moon1.png", fc_width, fc_height);
	pictures.push_back(img0_1);
	loadimage(&img0_2, "../image/effect/moon2.png", fc_width, fc_height);
	pictures.push_back(img0_2);
	loadimage(&img0_3, "../image/effect/moon3.png", fc_width, fc_height);
	pictures.push_back(img0_3);
	loadimage(&img0_4, "../image/effect/moon4.png", fc_width, fc_height);
	pictures.push_back(img0_4);
	loadimage(&img0_5, "../image/effect/moon5.png", fc_width, fc_height);
	pictures.push_back(img0_5);
	loadimage(&img0_6, "../image/effect/moon6.png", fc_width, fc_height);
	pictures.push_back(img0_6);
	loadimage(&img0_7, "../image/effect/moon7.png", fc_width, fc_height);
	pictures.push_back(img0_7);
	loadimage(&img0_8, "../image/effect/moon8.png", fc_width, fc_height);
	pictures.push_back(img0_8);
	loadimage(&img0_9, "../image/effect/moon9.png", fc_width, fc_height);
	pictures.push_back(img0_9);
	loadimage(&img0_10, "../image/effect/moon10.png", fc_width, fc_height);
	pictures.push_back(img0_10);
	loadimage(&img0_11, "../image/effect/void.png", fc_width, fc_height);
	pictures.push_back(img0_11);

	IMAGE img1_1;
	loadimage(&img1_1, "../image/effect/moon.png", moon.width, moon.height);
	pictures.push_back(img1_1);
}

bool SkillMoon::isReady()
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
			return true;
			break;
		}
	}
	return false;
}

void SkillMoon::effect()
{
	notUsing = false;
	moon.active = true;
	*p_op_num = 10;
	moon.x = *p_x;
	*p_energy -= needEnergy;
	time = 1.2;
	cd = 20;
	*p_NItime = time;
	p_animationEffect->reset();
}

void SkillMoon::isOver()
{
	*p_op_num = (*p_y < commomY ? 13 : 0);
	time = 0;
	windDown = 0;
	*p_NItime = 0;
	notUsing = true;
}

void SkillMoon::run()
{
	if (notUsing == false) {
		if (time > 0) {
			time -= *p_dt;
			p_animationEffect->run(101);
		}
		else {
			*p_op_num = (*p_y < commomY ? 13 : 0);
			isOver();
		}
	}
}

void SkillMoon::reset()
{
	isOver();
}

void SkillMoon::initAttack() 
{
	moon.y = 20;
	moon.width = 450;
	moon.height = 450;
}

void SkillMoon::moonRun()
{
	if (moon.active == true) {
		moon.x += *p_dt * 2500;
		m_animationEffect->run(102);
		if (moon.x >= 1024) {
			moon.active = false;
		}
	}
}
