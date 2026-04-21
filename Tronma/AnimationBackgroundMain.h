#pragma once
#include"AnimationBackground.h"
//#include"tools.hpp"

class AnimationBackgroundMain :public AnimationBackground {
public:
	AnimationBackgroundMain(float* x, float* y, float* speed, int* width, std::vector<IMAGE>& pictures, int* ground_Y, int* ground_Height);
	void run();
	void drawBackground();
	void drawGround();
	~AnimationBackgroundMain();
protected:
	int* a_width;
	int* a_Ground_Y;
	int* a_Ground_Height;
};