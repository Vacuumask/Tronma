#pragma once
#include"Player.h"

class Move {
public:
	virtual bool isReady() = 0;
	virtual void effect() = 0;
	virtual void isOver() = 0;
	virtual void run() = 0;
protected:
	int needEnergy = 0;
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
	int* p_width;
	int* p_height;
	int* p_health;
	int* p_energy;
	float commonX = 100;
	float commomY = 340;
};