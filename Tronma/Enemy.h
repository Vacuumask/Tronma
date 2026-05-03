#pragma once
#include"AnimationEnemy.h"
#include"Character.h"
#include"Player.h"
#include"Attack.h"

struct Enemy :public Character
{
	virtual ~Enemy() = default;
	virtual void loadPicture() = 0;
	virtual void run(float* dt) = 0;
	virtual bool collide() = 0;
	virtual void damage() = 0;
	virtual bool attackedCollide() = 0;
	virtual void beDamaged() = 0;
	virtual void isOver() = 0;

	float start_x, start_y;
	float* xspeed;
	float yspeed;

	int* sec_enum;

	bool active = false;
	bool canDamage = false;
	bool canBeDamaged = true;
	bool alive = false;

	static bool start;
	static bool EMP;

	std::vector<IMAGE> pictures;
	Player* player = NULL;
	Player* shadow = NULL;
	AnimationEnemy* animationEnemy = NULL;
};

class EnemyPool {
public:
	virtual ~EnemyPool() = default;
	virtual void acquire(int sec) = 0;
	virtual void run(float* dt) = 0;
	virtual void isOver() = 0;
	Player* player = NULL;
	Player* shadow = NULL;
	int* sec_enum;
};