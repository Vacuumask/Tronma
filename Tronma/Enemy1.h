#pragma once
#include"Enemy.h"

class Enemy1 :public Enemy {
public:
	Enemy1();
	~Enemy1();
	void loadPicture()override;
	void run(float* dt)override;
	bool collide()override;
	void damage()override;
	bool attackedCollide()override;
	void beDamaged()override;
	void isOver()override;
};

class Enemy1Pool :public EnemyPool {
public:
	Enemy1Pool(int& sceneWidth, float* speed, Player* player, int* sec_enum);
	~Enemy1Pool();
	void acquire(int sec)override;
	void run(float* dt)override;
protected:
	static const int pool_Size = 5;
	Enemy1 enemy1[pool_Size];
};