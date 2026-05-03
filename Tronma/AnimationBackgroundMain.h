#pragma once
#include"AnimationBackground.h"

class AnimationBackgroundMain :public AnimationBackground {
public:
	AnimationBackgroundMain(float* x, float* y, float* speed, int* width, std::vector<IMAGE>& pictures, int* ground_Y, int* ground_Height, bool* startGame);
	void run();
	void drawBackground();
	void drawGround();
	~AnimationBackgroundMain();

	int bk_num = 0;
	int bk_size = 5;
protected:
	bool* startGame;
	int* a_width;
	int* a_Ground_Y;
	int* a_Ground_Height;
};