#pragma once
#include"Animation.h"
#include"Player.h"
#include"MoveJump.h"
#include"MoveSprint.h"
#include"MoveFall.h"
#include"SkillChop.h"
#include"SkillTeleport.h"
#include"SkillSlow.h"
#include"SkillEMP.h"
#include"SkillShadow.h"
#include"SkillMoon.h"

class Op {
public:
	Op(Player* player, Player*shadow, float* speed, float* dt);
	~Op();
	void opRun();
	void energyRecover();
	void cdRecover();
	float getCd(int num);
	bool getTele();
	void getMoon();
	void runMoon();
	void reset();
protected:
	float* p_dt;
	int* p_energy;
	bool* p_die;
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

	SkillTeleport* skillTeleport = NULL;
	bool lastTeleport1 = false;
	bool lastTeleport2 = false;

	SkillSlow* skillSlow = NULL;
	bool lastSlow = false;

	SkillEMP* skillEMP = NULL;
	bool lastEMP = false;

	SkillShadow* skillShadow = NULL;
	bool lastShadow = false;

	SkillMoon* skillMoon = NULL;
	bool lastMoon = false;
};