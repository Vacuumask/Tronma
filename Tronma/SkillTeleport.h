#pragma once
#include"Skill.h"

class SkillTeleport :public Skill {
public:
	SkillTeleport(Player* player, float* dt, float* NItime);
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void reset()override;

	bool ableBack = false;
protected:
	bool* canBeDamaged;
};