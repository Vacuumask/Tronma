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
	virtual ~Animation();
	float dt = 0;
protected:
	Animation* animation = NULL;
private:
	LARGE_INTEGER freq, last, current = { 0 };
};