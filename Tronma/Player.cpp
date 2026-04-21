#include"Player.h"

Player::Player()
{
	x = 100;
	y = 340;
	width = 150;
	height = 150;

	c_x = 38;
	c_y = 50;
	c_width = 66;
	c_height = 76;

	loadPicture();
	animationPlayer = new AnimationPlayer(&x, &y, pictures);

}

Player::~Player()
{
	if (animationPlayer != NULL) {
		delete animationPlayer;
		animationPlayer = NULL;
	}
}

void Player::loadPicture() {
	IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6, img0_7;
	loadimage(&img0_1, "../image/player/move/02.png", width, height);
	pictures.push_back(img0_1);
	loadimage(&img0_2, "../image/player/move/03.png", width, height);
	pictures.push_back(img0_2);
	loadimage(&img0_3, "../image/player/move/04.png", width, height);
	pictures.push_back(img0_3);
	loadimage(&img0_4, "../image/player/move/05.png", width, height);
	pictures.push_back(img0_4);
	loadimage(&img0_5, "../image/player/move/06.png", width, height);
	pictures.push_back(img0_5);
	loadimage(&img0_6, "../image/player/move/07.png", width, height);
	pictures.push_back(img0_6);
	loadimage(&img0_7, "../image/player/move/08.png", width, height);
	pictures.push_back(img0_7);

	IMAGE img1_1, img1_2, img1_3, img1_4, img1_5, img1_6, img1_7, img1_8, img1_9, img1_10, img1_11, img1_12;
	loadimage(&img1_1, "../image/player/jump/01.png", width, height);
	pictures.push_back(img1_1);
	loadimage(&img1_2, "../image/player/jump/02.png", width, height);
	pictures.push_back(img1_2);
	loadimage(&img1_3, "../image/player/jump/03.png", width, height);
	pictures.push_back(img1_3);
	loadimage(&img1_4, "../image/player/jump/04.png", width, height);
	pictures.push_back(img1_4);
	loadimage(&img1_5, "../image/player/jump/05.png", width, height);
	pictures.push_back(img1_5);
	loadimage(&img1_6, "../image/player/jump/06.png", width, height);
	pictures.push_back(img1_6);
	loadimage(&img1_7, "../image/player/jump/07.png", width, height);
	pictures.push_back(img1_7);
	loadimage(&img1_8, "../image/player/jump/08.png", width, height);
	pictures.push_back(img1_8);
	loadimage(&img1_9, "../image/player/jump/09.png", width, height);
	pictures.push_back(img1_9);
	loadimage(&img1_10, "../image/player/jump/10.png", width, height);
	pictures.push_back(img1_10);
	loadimage(&img1_11, "../image/player/jump/11.png", width, height);
	pictures.push_back(img1_11);
	loadimage(&img1_12, "../image/player/jump/12.png", width, height);
	pictures.push_back(img1_12);

	IMAGE img2_1, img2_2, img2_3, img2_4, img2_5, img2_6, img2_7, img2_8, img2_9;
	loadimage(&img2_1, "../image/player/attack1/04.png", width * 1.5, height);
	pictures.push_back(img2_1);
	loadimage(&img2_2, "../image/player/attack1/05.png", width * 1.5, height);
	pictures.push_back(img2_2);
	loadimage(&img2_3, "../image/player/attack1/06.png", width * 1.5, height);
	pictures.push_back(img2_3);
	loadimage(&img2_4, "../image/player/attack2/04.png", width * 1.5, height);
	pictures.push_back(img2_4);
	loadimage(&img2_5, "../image/player/attack2/05.png", width * 1.5, height);
	pictures.push_back(img2_5);
	loadimage(&img2_6, "../image/player/attack2/06.png", width * 1.5, height);
	pictures.push_back(img2_6);
	loadimage(&img2_7, "../image/player/attack3/04.png", width * 1.5, height);
	pictures.push_back(img2_7);
	loadimage(&img2_8, "../image/player/attack3/05.png", width * 1.5, height);
	pictures.push_back(img2_8);
	loadimage(&img2_9, "../image/player/attack3/06.png", width * 1.5, height);
	pictures.push_back(img2_9);

}

void Player::animationPlayerRun()
{
	animationPlayer->run(op_num);
}