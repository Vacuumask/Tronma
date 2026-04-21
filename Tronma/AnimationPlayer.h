#pragma once
#include"Animation.h"
#include"tools.hpp"

class AnimationPlayer :public Animation {
public:
	AnimationPlayer(float* x, float* y, std::vector<IMAGE>& pictures);
	~AnimationPlayer();
	void run(int& op_num);
	void resetChop(int& op_num);
protected:
	float* a_x, * a_y;
	std::vector<IMAGE> a_pictures;
	int temp_op;

	int a_num0 = 0;
	float a_switch0 = 0;

	int a_num11 = 7;
	float a_switch11 = 0;
	int a_num12 = 11;
	float a_switch12 = 0;
	int a_num13 = 15;
	float a_switch13 = 0;

	int a_num41 = 19;
	float a_switch41 = 0;
	int a_num42 = 22;
	float a_switch42 = 0;
	int a_num43 = 25;
	float a_switch43 = 0;
};