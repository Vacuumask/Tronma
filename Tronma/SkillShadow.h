#pragma once
#include"Skill.h"

class SkillShadow :public Skill {
public:
	SkillShadow(Player* player, Player* shadow, float* speed, float* dt, float* NItime);
	void loadPicture();
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void reset()override;

protected:
	Player* shadow = NULL;
	bool* p_die = NULL;
	bool* p_canBeDamaged = NULL;
};