#pragma once
#include"Move.h"

class MoveSprint :public Move {
public:
	MoveSprint(Player* player, float* speed, float* dt, float* NItime);
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
protected:
};