#pragma once
#include"Animation.h"
#include"tools.hpp"

class AnimationEffect :public Animation {
public:
	AnimationEffect(float* x, float* y, std::vector<IMAGE>& pictures);
	~AnimationEffect();
	void run(int e_num);
	void reset();
protected:
	float* a_x, * a_y;
	std::vector<IMAGE> a_pictures;

	int a_num41 = 0;
	float a_switch41 = 0;
	int a_num43 = 14;
	float a_switch43 = 0;
};