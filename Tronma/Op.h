#pragma once
#include"Animation.h"
#include"Player.h"
#include"MoveJump.h"
#include"MoveSprint.h"
#include"MoveFall.h"
#include"SkillChop.h"

class Op {
public:
	Op(Player* player, float* speed, float* dt);
	~Op();
	void opRun();
	void energyRecover();
protected:
	float* p_dt;
	int* p_energy;
	float NItime = 0;
	float recoverTime = 1.0f;
	int currentKey = 0;
	float storageTime = 0;

	int lastKey = 0;

	MoveJump* moveJump = NULL;
	bool lastJump = false;

	MoveSprint* moveSprint = NULL;
	bool lastSprint = false;

	MoveFall* moveFall = NULL;
	bool lastFall = false;

	SkillChop* skillChop = NULL;
	bool lastChop = false;

};