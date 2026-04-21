#pragma once
#include"Enemy.h"

class Bullet4 :public Enemy {
public:
	Bullet4();
	~Bullet4();
	void loadPicture()override;
	void run(float* dt)override;
	bool collide()override;
	void damage()override;
	bool attackedCollide()override;
	void beDamaged()override;
	void isOver()override;
	int type = 0;

	float shootTime = 0.6;
};

class Enemy4 :public Enemy {
public:
	Enemy4();
	~Enemy4();
	void loadPicture()override;
	void run(float* dt)override;
	bool collide()override;
	void damage()override;
	bool attackedCollide()override;
	void beDamaged()override;
	void isOver()override;

	void acquire(int bullet);

	bool isCharging = false;
	bool isShooting = false;
	bool isWaiting = false;
	bool isBacking = false;

	float chargeTime = 2;
	float shootTime = 0.6;
	float waitTime = 1;
	float dieTime = 2;

	float y0 = 0;
	float y1 = 110;
	float y2 = 220;
protected:
	static const int bullet_Size = 1;
	Bullet4 bullet4[bullet_Size];
};

class Enemy4Pool :public EnemyPool {
public:
	Enemy4Pool(int& sceneWidth, float* speed, Player* player, int* sec_enum);
	~Enemy4Pool();
	void acquire(int sec)override;
	void run(float* dt)override;
protected:
	static const int pool_Size = 1;
	Enemy4 enemy4[pool_Size];
};