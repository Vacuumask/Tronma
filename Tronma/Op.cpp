#include "Op.h"

Op::Op(Player* player, float* speed, float* dt)
{
	p_dt = dt;
	p_energy = &player->energy;
	moveJump = new MoveJump(player, dt, &NItime);
	moveSprint = new MoveSprint(player, speed, dt, &NItime);
	moveFall = new MoveFall(player, dt, &NItime);
	skillChop = new SkillChop(player, dt, &NItime);
	player->attack.push_back(&skillChop->attackChop);
	player->attack.push_back(&skillChop->lightBlade);
}

Op::~Op()
{
	if (moveJump != NULL) {
		delete moveJump;
		moveJump = NULL;
	}
	if (moveSprint != NULL) {
		delete moveSprint;
		moveSprint = NULL;
	}
	if (moveFall != NULL) {
		delete moveFall;
		moveFall = NULL;
	}
	if (skillChop != NULL) {
		delete skillChop;
		skillChop = NULL;
	}
}

void Op::opRun()
{
	energyRecover();

	bool currentJump = (GetAsyncKeyState('W') & 0x8000) != 0;
	bool currentSprint = (GetAsyncKeyState('K') & 0x8000) != 0;
	bool currentFall = (GetAsyncKeyState('S') & 0x8000) != 0;
	bool currentChop = (GetAsyncKeyState('J') & 0x8000) != 0;

	moveJump->run();
	moveJump->countY();
	moveSprint->run();
	moveFall->run();
	skillChop->run();
	skillChop->lightBladeRun();

	if (NItime == 0) {
		if (storageTime != 0)storageTime = 0;

		if (currentJump && !lastJump || currentKey == 'W') {
			if (currentKey == 'W') {
				currentKey = 0;
			}
			if (moveJump->isReady()) {
				moveJump->effect();
				lastKey = 'W';
			}
		}
		lastJump = currentJump;
		

		
		if (currentSprint && !lastSprint || currentKey == 'K') {
			if (currentKey == 'K') {
				currentKey = 0;
			}
			if (moveSprint->isReady()) {
				moveSprint->effect();
				lastKey = 'K';
			}
		}
		lastSprint = currentSprint;
		

		
		if (currentFall && !lastFall || currentKey == 'S') {
			if (currentKey == 'S') {
				currentKey = 0;
			}
			if (moveFall->isReady()) {
				moveFall->effect();
				lastKey = 'S';
			}
		}
		lastFall = currentFall;
		

		
		if (currentChop && !lastChop || currentKey == 'J') {
			if (currentKey == 'J') {
				currentKey = 0;
				if (lastKey == 'S') {
					skillChop->fallChop = true;
				}
			}
			if (skillChop->isReady()) {
				skillChop->effect();
				lastKey = 'J';
			}
		}
		lastChop = currentChop;
		
	}
	else{
		if (NItime - storageTime >= 0.2f) {
			storageTime += *p_dt;
		}
		else {
			if (currentJump && !lastJump) {
				currentKey = 'W';
			}
			lastJump = currentJump;
			if (currentSprint && !lastSprint) {
				currentKey = 'K';
			}
			lastSprint = currentSprint;
			if (currentFall && !lastFall) {
				currentKey = 'S';
			}
			lastFall = currentFall;
			if (currentChop && !lastChop) {
				currentKey = 'J';
			}
			lastChop = currentChop;
		}
	}
}

void Op::energyRecover()
{
	if (*p_energy <= 100) {
		recoverTime -= *p_dt;
	}
	if (recoverTime <= 0) {
		recoverTime = 1;
		*p_energy += 3;
		if (*p_energy > 100)*p_energy = 100;
	}
}
