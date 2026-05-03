#include"Player.h"

int Player::dis_score = 0;
int Player::kill_score = 0;
int Player::allScore[6] = { 0,0,0,0,0,0 };
int Player::kill[4] = {0,0,0,0};

Player::Player(float* speed)
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
	animationPlayer = new AnimationPlayer(&x, &y, speed, pictures);
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

	IMAGE img3_1, img3_2, img3_3, img3_4, img3_5, img3_6, img3_7, img3_8;
	loadimage(&img3_1, "../image/player/idle/01.png", width, height);
	pictures.push_back(img3_1);
	loadimage(&img3_2, "../image/player/idle/02.png", width, height);
	pictures.push_back(img3_2);
	loadimage(&img3_3, "../image/player/idle/03.png", width, height);
	pictures.push_back(img3_3);
	loadimage(&img3_4, "../image/player/idle/04.png", width, height);
	pictures.push_back(img3_4);
	loadimage(&img3_5, "../image/player/idle/05.png", width, height);
	pictures.push_back(img3_5);
	loadimage(&img3_6, "../image/player/idle/06.png", width, height);
	pictures.push_back(img3_6);
	loadimage(&img3_7, "../image/player/idle/07.png", width, height);
	pictures.push_back(img3_7);
	loadimage(&img3_8, "../image/player/idle/08.png", width, height);
	pictures.push_back(img3_8);

	IMAGE img4_1, img4_2, img4_3, img4_4, img4_5, img4_6, img4_7, img4_8, 
		img4_9, img4_10, img4_11, img4_12, img4_13, img4_14, img4_15, img4_16;
	loadimage(&img4_1, "../image/player/teleport1/01.png", width, height);
	pictures.push_back(img4_1);
	loadimage(&img4_2, "../image/player/teleport1/02.png", width, height);
	pictures.push_back(img4_2);
	loadimage(&img4_3, "../image/player/teleport1/03.png", width, height);
	pictures.push_back(img4_3);
	loadimage(&img4_4, "../image/player/teleport1/04.png", width, height);
	pictures.push_back(img4_4);
	loadimage(&img4_5, "../image/player/teleport1/05.png", width, height);
	pictures.push_back(img4_5);
	loadimage(&img4_6, "../image/player/teleport1/06.png", width, height);
	pictures.push_back(img4_6);
	loadimage(&img4_7, "../image/player/teleport1/07.png", width, height);
	pictures.push_back(img4_7);
	loadimage(&img4_8, "../image/player/teleport1/08.png", width, height);
	pictures.push_back(img4_8);
	loadimage(&img4_9, "../image/player/teleport1/09.png", width, height);
	pictures.push_back(img4_9);
	loadimage(&img4_10, "../image/player/teleport1/10.png", width, height);
	pictures.push_back(img4_10);
	loadimage(&img4_11, "../image/player/teleport1/11.png", width, height);
	pictures.push_back(img4_11);
	loadimage(&img4_12, "../image/player/teleport1/12.png", width, height);
	pictures.push_back(img4_12);
	loadimage(&img4_13, "../image/player/teleport1/13.png", width, height);
	pictures.push_back(img4_13);
	loadimage(&img4_14, "../image/player/teleport1/14.png", width, height);
	pictures.push_back(img4_14);
	loadimage(&img4_15, "../image/player/teleport1/15.png", width, height);
	pictures.push_back(img4_15);
	loadimage(&img4_16, "../image/player/teleport1/16.png", width, height);
	pictures.push_back(img4_16);

	IMAGE img5_1, img5_2, img5_3, img5_4, img5_5, img5_6, img5_7, img5_8;
	loadimage(&img5_1, "../image/player/teleport2/01.png", width, height);
	pictures.push_back(img5_1);
	loadimage(&img5_2, "../image/player/teleport2/02.png", width, height);
	pictures.push_back(img5_2);
	loadimage(&img5_3, "../image/player/teleport2/03.png", width, height);
	pictures.push_back(img5_3);
	loadimage(&img5_4, "../image/player/teleport2/04.png", width, height);
	pictures.push_back(img5_4);
	loadimage(&img5_5, "../image/player/teleport2/05.png", width, height);
	pictures.push_back(img5_5);
	loadimage(&img5_6, "../image/player/teleport2/06.png", width, height);
	pictures.push_back(img5_6);
	loadimage(&img5_7, "../image/player/teleport2/07.png", width, height);
	pictures.push_back(img5_7);
	loadimage(&img5_8, "../image/player/teleport2/08.png", width, height);
	pictures.push_back(img5_8);

	IMAGE img6_1, img6_2, img6_3, img6_4, img6_5, img6_6, img6_7;
	loadimage(&img6_1, "../image/shadow/1.png", width, height);
	pictures.push_back(img6_1);
	loadimage(&img6_2, "../image/shadow/2.png", width, height);
	pictures.push_back(img6_2);
	loadimage(&img6_3, "../image/shadow/3.png", width, height);
	pictures.push_back(img6_3);
	loadimage(&img6_4, "../image/shadow/4.png", width, height);
	pictures.push_back(img6_4);
	loadimage(&img6_5, "../image/shadow/5.png", width, height);
	pictures.push_back(img6_5);
	loadimage(&img6_6, "../image/shadow/6.png", width, height);
	pictures.push_back(img6_6);
	loadimage(&img6_7, "../image/shadow/7.png", width, height);
	pictures.push_back(img6_7);

	IMAGE img7_1, img7_2, img7_3, img7_4;
	loadimage(&img7_1, "../image/player/hurt/1.png", width, height);
	pictures.push_back(img7_1);
	loadimage(&img7_2, "../image/player/hurt/2.png", width, height);
	pictures.push_back(img7_2);
	loadimage(&img7_3, "../image/player/hurt/3.png", width, height);
	pictures.push_back(img7_3);
	loadimage(&img7_4, "../image/effect/void.png", width, height);
	pictures.push_back(img7_4);
}

void Player::animationPlayerRun()
{
	animationPlayer->run(op_num);
}

void Player::reset() {
	x = 100;
	y = 340;
	health = 7;
	energy = 100;
	ySpeed = 0;
	op_num = 5;
	canBeDamaged = true;
	damage = false;
	die = false;
	animationPlayer->reset();
	dis_score = 0;
	kill_score = 0;
	kill[0] = kill[1] = kill[2] = kill[3] = 0;
}