#pragma once
#include"Player.h"
#include"AnimationEffect.h"

class Skill
{
public:
	//virtual void loadPicture() = 0;
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