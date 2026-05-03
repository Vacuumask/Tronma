#pragma once
#include"Skill.h"
#include"Enemy.h"

class SkillEMP :public Skill {
public:
	SkillEMP(Player* player, float* dt, float* NItime);
	void loadPicture();
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void reset()override;
protected:
	float x[12];
	float y[12];
	float size[12];
};