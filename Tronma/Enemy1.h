#pragma once
#include"Enemy.h"

class Enemy1 :public Enemy {
public:
	Enemy1();
	~Enemy1();
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
};

class Enemy1Pool :public EnemyPool {
public:
	Enemy1Pool(int& sceneWidth, float* speed, Player* player, Player* shadow, int* sec_enum);
	~Enemy1Pool();
	void acquire(int sec)override;
	void run(float* dt)override;
	void isOver()override;
protected:
	static const int pool_Size = 5;
	Enemy1 enemy1[pool_Size];
};