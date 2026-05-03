#pragma once
#include"Animation.h"
#include"tools.hpp"

class AnimationEffect :public Animation {
public:
	AnimationEffect(float* x, float* y, std::vector<IMAGE>& pictures);
	AnimationEffect(float* x, float* y, float* p_x, float* p_y, std::vector<IMAGE>& pictures);
	~AnimationEffect();
	void run(int e_num);
	void reset();
protected:
	float* a_x, * a_y;
	float* b_x, * b_y;
	std::vector<IMAGE> a_pictures;

	int a_num41 = 0;
	float a_switch41 = 0;
	int a_num43 = 14;
	float a_switch43 = 0;

	int a_num5 = 0;
	float a_switch5 = 0;
	
	int a_num10 = 0;
	float a_switch10 = 0;
};