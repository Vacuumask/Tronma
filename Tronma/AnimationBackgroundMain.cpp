#include"AnimationBackgroundMain.h"

AnimationBackgroundMain::AnimationBackgroundMain(float* x, float* y, float* speed, int* width, std::vector<IMAGE>& pictures, int* ground_Y, int* ground_Height, bool* startGame)
{
	this->startGame = startGame;
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
	float sp = *a_speed / 3 * dt * Animation::p_speed;
	cleardevice();
	for (int i = bk_num + 1; i <= bk_num + bk_size; i++) {
		a_X[i - 1] -= sp * (i - bk_num) * 5 / bk_size;
		drawImg(a_X[i - 1], *a_y, &a_pictures[i - 1]);
		drawImg(a_X[i - 1] + *a_width, *a_y, &a_pictures[i - 1]);
		if (a_X[i - 1] < -*a_width)a_X[i - 1] = 0;
	}
}

void AnimationBackgroundMain::drawGround()
{
	float sp = *a_speed / 10 * dt * Animation::p_speed;
	for (int i = 0; i < 33; i++) {
		if (*startGame == true) {
			g_x -= sp;
		}
		drawImg(g_x + 32 * i, *a_Ground_Y, &a_pictures[16]);
		drawImg(g_x + 32 * i + *a_width, *a_Ground_Y, &a_pictures[16]);
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
