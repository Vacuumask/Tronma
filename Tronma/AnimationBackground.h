#pragma once
#include"Animation.h"
#include"tools.hpp"

class AnimationBackground :public Animation {
public:
	virtual void run() = 0;
	virtual void drawBackground() = 0;
	virtual ~AnimationBackground() = default;
protected:
	float* a_x;
	float* a_y;
	std::vector<IMAGE> a_pictures;
	std::vector<float> a_X;
	float g_x = 0;
};