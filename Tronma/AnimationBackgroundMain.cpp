#include"AnimationBackgroundMain.h"

AnimationBackgroundMain::AnimationBackgroundMain(float* x, float* y, float* speed, int* width, std::vector<IMAGE>& pictures, int* ground_Y, int* ground_Height)
{
	a_x = x;
	a_y = y;
	a_speed = speed;
	a_width = width;
	a_pictures = pictures;
	a_Ground_Y = ground_Y;
	a_Ground_Height = ground_Height;
	for (int i = 0; i < pictures.size(); i++) {
		a_X.push_back(0);
	}
}

void AnimationBackgroundMain::run() {
	FPS();
	drawBackground();
	drawGround();
}

void AnimationBackgroundMain::drawBackground()
{
	float sp = *a_speed / 3 * dt;
	cleardevice();
	for (int i = 1; i <= 5; i++) {
		a_X[i - 1] -= sp * i;
		drawImg(a_X[i - 1], *a_y, &a_pictures[i - 1]);
		drawImg(a_X[i - 1] + *a_width, *a_y, &a_pictures[i - 1]);
		if (a_X[i - 1] < -*a_width)a_X[i - 1] = 0;
	}
}

void AnimationBackgroundMain::drawGround()
{
	float sp = *a_speed / 10 * dt;
	for (int i = 0; i < 33; i++) {
		g_x -= sp;
		drawImg(g_x + 32 * i, *a_Ground_Y, &a_pictures[5]);
		drawImg(g_x + 32 * i + *a_width, *a_Ground_Y, &a_pictures[5]);
	}
	if (g_x < -*a_width)g_x = 0;
}

AnimationBackgroundMain::~AnimationBackgroundMain()
{
	if (animation != NULL) {
		delete animation;
		animation = NULL;
	}
}
