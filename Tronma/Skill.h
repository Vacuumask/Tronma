#pragma once
#include"Player.h"
#include"Enemy.h"
#include"AnimationEffect.h"
#include"Audio.h"

class Skill
{
public:
	virtual bool isReady() = 0;
	virtual void effect() = 0;
	virtual void isOver() = 0;
	virtual void run() = 0;
	virtual void reset() = 0;

	int needEnergy = 0;
	float cd = 0;
protected:
	float windUp = 0;
	float windDown = 0;
	float time = 0;
	bool notUsing = true;

	int* p_op_num;
	float* p_dt;
	float* p_speed;
	float* p_NItime;

	float* p_x;
	float* p_y;
	float* y_speed;
	float* p_width;
	float* p_height;
	int* p_health;
	int* p_energy;
	float commonX = 100;
	float commomY = 340;

	std::vector<IMAGE> pictures;
	AnimationEffect* p_animationEffect = NULL;
};

class SkillChop :public Skill {
public:
	SkillChop(Player* player, float* dt, float* NItime);
	~SkillChop();
	void loadPicture();
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void reset()override;
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

	FxPlayer chop;
	FxPlayer lbFx;
};

class SkillEMP :public Skill {
public:
	SkillEMP(Player* player, float* dt, float* NItime);
	~SkillEMP();
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

	FxPlayer Fx;
};

class SkillMoon :public Skill {
public:
	SkillMoon(Player* player, float* dt, float* NItime);
	~SkillMoon();
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

	FxPlayer FxMoon;
};

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
	bool* p_rec = NULL;

	FxPlayer out;
	FxPlayer dis;
};

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

	FxPlayer Fx;
};