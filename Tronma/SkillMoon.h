#pragma once
#include"Skill.h"

class SkillMoon :public Skill {
public:
	SkillMoon(Player* player, float* dt, float* NItime);
	void loadPicture();
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void reset()override;
	void initAttack();
	void moonRun();

	Attack moon;
	AnimationEffect* m_animationEffect = NULL;

	float fc_width = 160;
	float fc_height = 160;
};