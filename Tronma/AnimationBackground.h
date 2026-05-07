#pragma once
#include"Animation.h"
#include"tools.hpp"

class AnimationBackground :public Animation {
public:
	virtual void run() = 0;
	virtual void drawBackground() = 0;
protected:
	float* a_x;
	float* a_y;
	std::vector<IMAGE> a_pictures;
	std::vector<float> a_X;
	float g_x = 0;
};

class AnimationBackgroundMain :public AnimationBackground {
public:
	AnimationBackgroundMain(float* x, float* y, float* speed, int* width, std::vector<IMAGE>& pictures, int* ground_Y, int* ground_Height, bool* startGame);
	void run();
	void drawBackground();
	void drawGround();

	int bk_num = 0;
	int bk_size = 5;
protected:
	bool* startGame;
	int* a_width;
	int* a_Ground_Y;
	int* a_Ground_Height;
};

class AnimationBackgroundMenu :public AnimationBackground {
public:
	AnimationBackgroundMenu(float* x, float* y, std::vector<IMAGE>& pictures, bool* enterGame);
	void run();
	void drawBackground();
protected:
	bool* enterGame;
	float bk1_time = 2.25;
};