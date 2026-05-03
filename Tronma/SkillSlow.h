#pragma once
#include"Skill.h"
#include"Audio.h"

class SkillSlow :public Skill {
public:
	SkillSlow(Player* player, float* speed, float* dt, float* NItime);
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void reset()override;
protected:
	int temp_op = 0;
};