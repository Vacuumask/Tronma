#pragma once
#include"Animation.h"
#include"tools.hpp"

class AnimationEnemy :public Animation {
public:
	AnimationEnemy(float* x, float* y, std::vector<IMAGE>& pictures);
	~AnimationEnemy();
	void run(int e_num);
	void reset(int e_num);
protected:
	float* a_x, * a_y;
	std::vector<IMAGE> a_pictures;
	int temp_op;

	int a_num1 = 0;
	float a_switch1 = 0;
	int a_num_1 = 6;
	float a_switch_1 = 0;

	int a_num21 = 0;
	float a_switch21 = 0;
	int a_num22 = 8;
	float a_switch22 = 0;
	int a_num23 = 12;
	float a_switch23 = 0;
	int a_num24 = 16;
	float a_switch24 = 0;
	int a_num_2 = 23;
	float a_switch_2 = 0;

	int a_num31 = 0;
	float a_switch31 = 0;
	int a_num32 = 12;
	float a_switch32 = 0;
	int a_num_3 = 16;
	float a_switch_3 = 0;

	int a_num42 = 0;
	float a_switch42 = 0;
	int a_num44 = 4;
	float a_switch44 = 0;
	int a_num_4 = 8;
	float a_switch_4 = 0;
};