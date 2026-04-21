#pragma once
#include"Move.h"

class MoveJump :public Move {
public:
	MoveJump(Player* player, float* dt, float* NItime);
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
	void countY();
protected:
	int ableTime = 2;
};