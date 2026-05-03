#pragma once
#include"Enemy.h"

class Bullet2 :public Enemy {
public:
	Bullet2();
	~Bullet2();
	void init();
	void loadPicture()override;
	void run(float* dt)override;
	bool collide()override;
	bool collideS();
	void damage()override;
	void damageS();
	bool attackedCollide()override;
	void beDamaged()override;
	void isOver()override;
	int type = 0;
};

class Enemy2 :public Enemy {
public:
	Enemy2();
	~Enemy2();
	void init();
	void loadPicture()override;
	void run(float* dt)override;
	bool collide()override;
	bool collideS();
	bool shootDisCollide();
	void damage()override;
	void damageS();
	bool attackedCollide()override;
	void beDamaged()override;
	void isOver()override;

	void acquire(int bullet);
	void bulletOver();

	bool isCharging = false;
	bool isShooting = false;
	bool isDashing = false;
	bool dashIsReady = false;

	float chargeTime = 0.5;
	float shootTime = 0.3;
	float dashTime = 0.5;
protected:
	float shootDis = 650;
	int shootNum = 0;
	static const int bullet_Size = 4;
	Bullet2 bullet2[bullet_Size];
};

class Enemy2Pool :public EnemyPool {
public:
	Enemy2Pool(int& sceneWidth, float* speed, Player* player, Player* shadow, int* sec_enum);
	~Enemy2Pool();
	void acquire(int sec)override;
	void run(float* dt)override;
	void isOver()override;
protected:
	static const int pool_Size = 1;
	Enemy2 enemy2[pool_Size];
};