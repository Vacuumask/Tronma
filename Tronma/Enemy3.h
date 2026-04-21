#pragma once
#include"Enemy.h"

class Bullet3 :public Enemy {
public:
	Bullet3();
	~Bullet3();
	void loadPicture()override;
	void run(float* dt)override;
	bool collide()override;
	void damage()override;
	bool attackedCollide()override;
	void beDamaged()override;
	void isOver()override;
	int type = 0;
};

class Enemy3 :public Enemy {
public:
	Enemy3();
	~Enemy3();
	void loadPicture()override;
	void run(float* dt)override;
	bool collide()override;
	void damage()override;
	bool attackedCollide()override;
	void beDamaged()override;
	void isOver()override;

	void acquire(int bullet);

	bool isCharging = false;

	float voidTime = 0.8;
	float chargeTime = 0.3;

	float y0 = 30;
	float y1 = 140;
	float y2 = 250;
protected:
	int shootNum = 0;
	static const int bullet_Size = 4;
	Bullet3 bullet3[bullet_Size];
};

class Enemy3Pool :public EnemyPool {
public:
	Enemy3Pool(int& sceneWidth, float* speed, Player* player, int* sec_enum);
	~Enemy3Pool();
	void acquire(int sec)override;
	void run(float* dt)override;
protected:
	static const int pool_Size = 4;
	Enemy3 enemy3[pool_Size];
};