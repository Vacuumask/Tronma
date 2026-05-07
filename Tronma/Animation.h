#pragma once
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<vector>
#include<cmath>

class Animation {
public:
	Animation();
	void FPS();
	float dt = 0;
	static float p_speed;
	static float base_speed;
	static float pro_speed;
protected:
	float* a_speed;
private:
	LARGE_INTEGER freq, last, current = { 0 };
};