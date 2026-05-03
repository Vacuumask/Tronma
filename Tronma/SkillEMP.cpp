#include "SkillEMP.h"

SkillEMP::SkillEMP(Player* player, float* dt, float* NItime)
{
	needEnergy = 20;

	p_dt = dt;
	p_op_num = &player->op_num;
	p_NItime = NItime;

	p_x = &player->x;
	p_y = &player->y;
	p_width = &player->c_width;
	p_height = &player->c_height;
	p_energy = &player->energy;

	for (int i = 0; i < 12; i++) {
		if (i == 0) {
			size[i] = 360;
		}
		else {
			size[i] = size[0] * (i + 1);
		}
		x[i] = *p_width - size[i] / 2;
		y[i] = *p_height - size[i] / 2;
	}

	loadPicture();
	p_animationEffect = new AnimationEffect(x, y, p_x, p_y, pictures);
}

void SkillEMP::loadPicture() {
	IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6, img0_7, img0_8, img0_9, img0_10, img0_11, img0_12;
	loadimage(&img0_1, "../image/effect/empa1.png", size[0], size[0]);
	pictures.push_back(img0_1);
	loadimage(&img0_2, "../image/effect/empa2.png", size[1], size[1]);
	pictures.push_back(img0_2);
	loadimage(&img0_3, "../image/effect/empa3.png", size[2], size[2]);
	pictures.push_back(img0_3);
	loadimage(&img0_4, "../image/effect/empa4.png", size[3], size[3]);
	pictures.push_back(img0_4);
	loadimage(&img0_5, "../image/effect/empa5.png", size[4], size[4]);
	pictures.push_back(img0_5);
	loadimage(&img0_6, "../image/effect/empa6.png", size[5], size[5]);
	pictures.push_back(img0_6);
	loadimage(&img0_7, "../image/effect/empa7.png", size[6], size[6]);
	pictures.push_back(img0_7);
	loadimage(&img0_8, "../image/effect/empa8.png", size[7], size[7]);
	pictures.push_back(img0_8);
	loadimage(&img0_9, "../image/effect/empa9.png", size[8], size[8]);
	pictures.push_back(img0_9);
	loadimage(&img0_10, "../image/effect/empa10.png", size[9], size[9]);
	pictures.push_back(img0_10);
	loadimage(&img0_11, "../image/effect/empa11.png", size[10], size[10]);
	pictures.push_back(img0_11);
	loadimage(&img0_12, "../image/effect/empa12.png", size[11], size[11]);
	pictures.push_back(img0_12); 
}

bool SkillEMP::isReady()
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

void SkillEMP::effect()
{
	notUsing = false;
	time = 6;
	*p_energy -= needEnergy;
	*p_op_num = 8;
	Enemy::EMP = true;
	p_animationEffect->reset();
}

void SkillEMP::isOver()
{
	notUsing = true;
	Enemy::EMP = false;
	cd = 12;
}

void SkillEMP::run()
{
	if (notUsing == false) {
		if (*p_op_num == 8)*p_op_num = (*p_y < commomY ? 13 : 0);
		if (time > 0) {
			time -= *p_dt;
			p_animationEffect->run(8);
		}
		else {
			isOver();
		}
	}
}

void SkillEMP::reset()
{
	isOver();
}
