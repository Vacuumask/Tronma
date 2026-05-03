#include"AnimationBackgroundMenu.h"

AnimationBackgroundMenu::AnimationBackgroundMenu(float* x, float* y, std::vector<IMAGE>& pictures, bool* enterGame)
{
	a_x = x;
	a_y = y;
	a_pictures = pictures;
	for (int i = 0; i < pictures.size(); i++) {
		a_X.push_back(0);
	}
	this->enterGame = enterGame;
}

void AnimationBackgroundMenu::run() 
{
	FPS();
	drawBackground();
}

void AnimationBackgroundMenu::drawBackground() 
{
	cleardevice();
	if (*enterGame == false) {
		bk1_time -= dt;
		if (bk1_time > 0) {
			drawImg(*a_x, *a_y, &a_pictures[0]);
		}
	}
	if (bk1_time <= 0) {
		drawImg(*a_x, *a_y, &a_pictures[1]);
	}
}

AnimationBackgroundMenu::~AnimationBackgroundMenu()
{
}