#include "SkillChop.h"

SkillChop::SkillChop(Player* player, float* dt, float* NItime)
{
	needEnergy = 2;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_NItime = NItime;

	p_x = &player->x;
	p_y = &player->y;
	y_speed = &player->ySpeed;
	p_energy = &player->energy;
	p_damage = &player->damage;

	initAttack();

	loadPicture();
	p_animationEffect = new AnimationEffect(p_x, p_y, pictures);
	lb_animationEffect = new AnimationEffect(&lightBlade.x, &lightBlade.y, pictures);
}

void SkillChop::loadPicture()
{
	IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6, img0_7, img0_8, img0_9, img0_10, img0_11, img0_12, img0_13;
	loadimage(&img0_1, "../image/effect/chop1.png", fc_width, fc_height);
	pictures.push_back(img0_1);
	loadimage(&img0_2, "../image/effect/chop2.png", fc_width, fc_height);
	pictures.push_back(img0_2);
	loadimage(&img0_3, "../image/effect/chop3.png", fc_width, fc_height);
	pictures.push_back(img0_3);
	loadimage(&img0_4, "../image/effect/chop4.png", fc_width, fc_height);
	pictures.push_back(img0_4);
	loadimage(&img0_5, "../image/effect/chop5.png", fc_width, fc_height);
	pictures.push_back(img0_5);
	loadimage(&img0_6, "../image/effect/chop6.png", fc_width, fc_height);
	pictures.push_back(img0_6);
	loadimage(&img0_7, "../image/effect/chop7.png", fc_width, fc_height);
	pictures.push_back(img0_7);
	loadimage(&img0_8, "../image/effect/chop8.png", fc_width, fc_height);
	pictures.push_back(img0_8);
	loadimage(&img0_9, "../image/effect/chop9.png", fc_width, fc_height);
	pictures.push_back(img0_9);
	loadimage(&img0_10, "../image/effect/chop10.png", fc_width, fc_height);
	pictures.push_back(img0_10);
	loadimage(&img0_11, "../image/effect/chop11.png", fc_width, fc_height);
	pictures.push_back(img0_11);
	loadimage(&img0_12, "../image/effect/chop12.png", fc_width, fc_height);
	pictures.push_back(img0_12);
	loadimage(&img0_13, "../image/effect/void.png", fc_width, fc_height);
	pictures.push_back(img0_13);

	IMAGE img1_1;
	loadimage(&img1_1, "../image/effect/lightBlade.png", lightBlade.width, lightBlade.height);
	pictures.push_back(img1_1);

	IMAGE img2_1, img2_2, img2_3, img2_4, img2_5, img2_6, img2_7, img2_8, img2_9, img2_10, img2_11, img2_12,
		  img2_13, img2_14, img2_15, img2_16, img2_17, img2_18, img2_19, img2_20, img2_21, img2_22, img2_23;
	loadimage(&img2_1, "../image/effect/sc1.png", 48, 48);
	pictures.push_back(img2_1);
	loadimage(&img2_2, "../image/effect/sc2.png", 48, 48);
	pictures.push_back(img2_2);
	loadimage(&img2_3, "../image/effect/sc3.png", 48, 48);
	pictures.push_back(img2_3);
	loadimage(&img2_4, "../image/effect/sc4.png", 48, 48);
	pictures.push_back(img2_4);
	loadimage(&img2_5, "../image/effect/sc5.png", 48, 48);
	pictures.push_back(img2_5);
	loadimage(&img2_6, "../image/effect/sc6.png", 48, 48);
	pictures.push_back(img2_6);
	loadimage(&img2_7, "../image/effect/sc7.png", 48, 48);
	pictures.push_back(img2_7);
	loadimage(&img2_8, "../image/effect/sc8.png", 48, 48);
	pictures.push_back(img2_8);
	loadimage(&img2_9, "../image/effect/sc9.png", 48, 48);
	pictures.push_back(img2_9);
	loadimage(&img2_10, "../image/effect/sc10.png", 48, 48);
	pictures.push_back(img2_10);
	loadimage(&img2_11, "../image/effect/sc11.png", 48, 48);
	pictures.push_back(img2_11);
	loadimage(&img2_12, "../image/effect/sc12.png", 48, 48);
	pictures.push_back(img2_12);
	loadimage(&img2_13, "../image/effect/sc13.png", 48, 48);
	pictures.push_back(img2_13);
	loadimage(&img2_14, "../image/effect/sc14.png", 48, 48);
	pictures.push_back(img2_14);
	loadimage(&img2_15, "../image/effect/sc15.png", 48, 48);
	pictures.push_back(img2_15);
	loadimage(&img2_16, "../image/effect/sc16.png", 48, 48);
	pictures.push_back(img2_16);
	loadimage(&img2_17, "../image/effect/sc17.png", 48, 48);
	pictures.push_back(img2_17);
	loadimage(&img2_18, "../image/effect/sc18.png", 48, 48);
	pictures.push_back(img2_18);
	loadimage(&img2_19, "../image/effect/sc19.png", 48, 48);
	pictures.push_back(img2_19);
	loadimage(&img2_20, "../image/effect/sc20.png", 48, 48);
	pictures.push_back(img2_20);
	loadimage(&img2_21, "../image/effect/sc21.png", 48, 48);
	pictures.push_back(img2_21);
	loadimage(&img2_22, "../image/effect/sc22.png", 48, 48);
	pictures.push_back(img2_22);
	loadimage(&img2_23, "../image/effect/sc23.png", 48, 48);
	pictures.push_back(img2_23);
}

bool SkillChop::isReady()
{
	if (*p_energy >= needEnergy && notUsing == true && windDown <= 0) {
		switch (*p_op_num) {
		case 0:
		case 11:
		case 12:
		case 13:
		case 14:
			return true;
			break;
		}
	}
	return false;
}

void SkillChop::effect()
{
	notUsing = false;
	if (superChop == true) {
		superChop = false;
		lightBlade.active = true;
		lightBlade.x = *p_x + 75;
		lightBlade.y = *p_y + 40;
	}
	if (*y_speed < -7) {
		*p_op_num = 41;
		attackChop = attackChopArray[0];
	}
	else if (*y_speed > 7) {
		*p_op_num = 42;
		attackChop = attackChopArray[2];
	}
	else {
		*p_op_num = 43;
		attackChop = attackChopArray[1];
	}
	attackChop.active = true;
	*p_energy -= needEnergy;
	time = 0.1;
	windDown = 0.3;
	*p_NItime = time;
	p_animationEffect->reset();
}

void SkillChop::isOver()
{
	time = 0;
	windDown = 0;
	notUsing = true;
	fallChop = false;
	*p_damage = false;
	attackChop.active = false;
}

void SkillChop::run()
{
	if (notUsing == false) {
		if (time > 0) {
			time -= *p_dt;
			if (fallChop == true) {
				if (superChop != true) {
					p_animationEffect->run(411);
				}
				else {
					p_animationEffect->run(412);
				}
				
				if (*p_damage == true && superChop != true) {
					superChop = true;
				}
			}
		}
		else if (windDown > 0) {
			if (*p_NItime != 0) {
				switch (*p_op_num) {
				case 41:
				case 42:
				case 43:
					*p_NItime = 0;
					attackChop.active = false;
					break;
				}
			}
			if (fallChop == true) {
				if (superChop != true) {
					p_animationEffect->run(411);
				}
				else {
					p_animationEffect->run(412);
				}
			}
			windDown -= *p_dt;
			switch (*p_op_num) {
			case 11:
			case 14:
			case 2:
			case 3:
			case 61:
			case 62:
			case 8:
			case 9:
			case 10:
				isOver();
			}
		}
		else {
			*p_op_num = (*p_y < commomY ? 13 : 0);
			isOver();
		}
	}
	if (superChop == true) {
		p_animationEffect->run(43);
	}
}

void SkillChop::reset()
{
	isOver();
	fallChop = false;
	superChop = false;
}

void SkillChop::initAttack()
{
	for (int i = 0; i < 3; i++) {
		attackChopArray[i].x = 75;
		attackChopArray[i].width = 150;
		attackChopArray[i].height = 150;
		switch (i) {
		case 0:
			attackChopArray[i].y = -50;
			break;
		case 1:
			attackChopArray[i].y = 0;
			break;
		case 2:
			attackChopArray[i].y = 50;
			break;
		}
	}

	lightBlade.width = 100;
	lightBlade.height = 100;
}

void SkillChop::lightBladeRun()
{
	if (lightBlade.active == true) {
		lightBlade.x += *p_dt * 3000;
		lb_animationEffect->run(42);
		if (lightBlade.x >= 1024) {
			lightBlade.active = false;
		}
	}
}
