#pragma once
#include"AnimationPlayer.h"
#include"Character.h"
#include"Attack.h"

struct Player :public Character
{
	Player();
	~Player();
	void loadPicture();
	void animationPlayerRun();

	int health = 7;
	int energy = 100;
	float ySpeed = 0;
	int op_num = 0;
	bool canBeDamaged = true;
	bool damage = false;

	std::vector<IMAGE> pictures;
	std::vector<Attack*> attack;
	AnimationPlayer* animationPlayer = NULL;
};