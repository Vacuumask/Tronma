#pragma once
#include"AnimationBackground.h"

class AnimationBackgroundMenu :public AnimationBackground {
public:
	AnimationBackgroundMenu(float* x, float* y, std::vector<IMAGE>& pictures, bool* enterGame);
	void run();
	void drawBackground();
	~AnimationBackgroundMenu();
protected:
	bool* enterGame;
	float bk1_time = 2.25;
};