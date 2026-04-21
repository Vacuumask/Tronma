#pragma once
#include"Skill.h"

class SkillChop :public Skill {
public:
	SkillChop(Player* player, float* dt, float* NItime);
	void loadPicture()override;
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void initAttack();
	void lightBladeRun();

	Attack attackChop;
	Attack attackChopArray[3];

	Attack lightBlade;
	AnimationEffect* lb_animationEffect = NULL;

	float fc_width = 160;
	float fc_height = 160;

	bool fallChop = false;
	bool* p_damage;
	bool superChop = false;
};