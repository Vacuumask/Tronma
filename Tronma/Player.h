#pragma once
#include"AnimationPlayer.h"
#include"Character.h"
#include"Attack.h"

struct Player :public Character
{
	Player(float* speed);
	~Player();
	void loadPicture();
	void animationPlayerRun();
	void reset();

	int health = 7;
	int energy = 100;
	float ySpeed = 0;
	int op_num = 5;
	bool canBeDamaged = true;
	bool damage = false;
	bool die = false;

	static int dis_score;
	static int kill_score;
	static int allScore[6];
	static int kill[4];

	std::vector<IMAGE> pictures;
	std::vector<Attack*> attack;
	AnimationPlayer* animationPlayer = NULL;
};