#pragma once
#include"Move.h"

class MoveFall :public Move {
public:
	MoveFall(Player* player, float* dt, float* NItime);
	bool isReady()override;
	void effect()override;
	void isOver()override;
	void run()override;
protected:
};