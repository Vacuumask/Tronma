#include "Op.h"

Op::Op(Player* player, Player* shadow, float* speed, float* dt)
{
	p_dt = dt;
	p_energy = &player->energy;
	p_die = &player->die;
	moveJump = new MoveJump(player, speed, dt, &NItime);
	moveSprint = new MoveSprint(player, speed, dt, &NItime);
	moveFall = new MoveFall(player, dt, &NItime);
	skillChop = new SkillChop(player, dt, &NItime);
	player->attack.push_back(&skillChop->attackChop);
	player->attack.push_back(&skillChop->lightBlade);
	skillTeleport = new SkillTeleport(player, dt, &NItime);
	skillSlow = new SkillSlow(player, speed, dt, &NItime);
	skillEMP = new SkillEMP(player, dt, &NItime);
	skillShadow = new SkillShadow(player, shadow, speed, dt, &NItime);
	skillMoon = new SkillMoon(player, dt, &NItime);
	player->attack.push_back(&skillMoon->moon);
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
	if (skillTeleport != NULL) {
		delete skillTeleport;
		skillTeleport = NULL;
	}
	if (skillSlow != NULL) {
		delete skillSlow;
		skillSlow = NULL;
	}
	if (skillEMP != NULL) {
		delete skillEMP;
		skillEMP = NULL;
	}
	if (skillShadow != NULL) {
		delete skillShadow;
		skillShadow = NULL;
	}
	if (skillMoon != NULL) {
		delete skillMoon;
		skillMoon = NULL;
	}
}

void Op::opRun()
{
	skillShadow->run();
	skillChop->lightBladeRun();
	skillMoon->moonRun();
	if (*p_die == false) {
		energyRecover();
		cdRecover();

		bool currentJump = (GetAsyncKeyState('W') & 0x8000) != 0;
		bool currentSprint = (GetAsyncKeyState('K') & 0x8000) != 0;
		bool currentFall = (GetAsyncKeyState('S') & 0x8000) != 0;
		bool currentChop = (GetAsyncKeyState('J') & 0x8000) != 0;
		bool currentTeleport1 = (GetAsyncKeyState('D') & 0x8000) != 0;
		bool currentTeleport2 = (GetAsyncKeyState('A') & 0x8000) != 0;
		bool currentSlow = (GetAsyncKeyState('L') & 0x8000) != 0;
		bool currentEMP = (GetAsyncKeyState('U') & 0x8000) != 0;
		bool currentShadow = (GetAsyncKeyState('I') & 0x8000) != 0;
		bool currentMoon = (GetAsyncKeyState('O') & 0x8000) != 0;

		moveJump->run();
		moveJump->countY();
		moveSprint->run();
		moveFall->run();
		skillChop->run();
		
		skillTeleport->run();
		skillSlow->run();
		skillEMP->run();
		//skillShadow->run();
		skillMoon->run();
		

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



			if (currentTeleport1 && !lastTeleport1 || currentKey == 'D') {
				if (currentKey == 'D') {
					currentKey = 0;
				}
				if (skillTeleport->isReady() && skillTeleport->ableBack == false) {
					skillTeleport->effect();
					lastKey = 'D';
				}
			}
			lastTeleport1 = currentTeleport1;



			if (currentTeleport2 && !lastTeleport2 || currentKey == 'A') {
				if (currentKey == 'A') {
					currentKey = 0;
				}
				if (skillTeleport->isReady() && skillTeleport->ableBack == true) {
					skillTeleport->effect();
					lastKey = 'A';
				}
			}
			lastTeleport2 = currentTeleport2;



			if (currentSlow && !lastSlow || currentKey == 'L') {
				if (currentKey == 'L') {
					currentKey = 0;
				}
				if (skillSlow->isReady()) {
					skillSlow->effect();
					lastKey = 'L';
				}
			}
			lastSlow = currentSlow;



			if (currentEMP && !lastEMP || currentKey == 'U') {
				if (currentKey == 'U') {
					currentKey = 0;
				}
				if (skillEMP->isReady()) {
					skillEMP->effect();
					lastKey = 'U';
				}
			}
			lastEMP = currentEMP;



			if (currentShadow && !lastShadow || currentKey == 'I') {
				if (currentKey == 'I') {
					currentKey = 0;
				}
				if (skillShadow->isReady()) {
					skillShadow->effect();
					lastKey = 'I';
				}
			}
			lastShadow = currentShadow;



			if (currentMoon && !lastMoon || currentKey == 'O') {
				if (currentKey == 'O') {
					currentKey = 0;
				}
				if (skillMoon->isReady()) {
					skillMoon->effect();
					lastKey = 'O';
				}
			}
			lastMoon = currentMoon;
		}
		else {
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
				if (currentTeleport1 && !lastTeleport1) {
					currentKey = 'D';
				}
				lastTeleport1 = currentTeleport1;
				if (currentTeleport2 && !lastTeleport2) {
					currentKey = 'A';
				}
				lastTeleport2 = currentTeleport2;
				if (currentSlow && !lastSlow) {
					currentKey = 'L';
				}
				lastSlow = currentSlow;
				if (currentEMP && !lastEMP) {
					currentKey = 'U';
				}
				lastEMP = currentEMP;
				if (currentShadow && !lastShadow) {
					currentKey = 'I';
				}
				lastShadow = currentShadow;
				if (currentMoon && !lastMoon) {
					currentKey = 'O';
				}
				lastMoon = currentMoon;
			}
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
		*p_energy += 4;
		if (*p_energy > 100)*p_energy = 100;
	}
}

void Op::cdRecover()
{
	if (skillTeleport->cd > 0) {
		skillTeleport->cd -= *p_dt;
	}
	if (skillSlow->cd > 0) {
		skillSlow->cd -= *p_dt;
	}
	if (skillEMP->cd > 0) {
		skillEMP->cd -= *p_dt;
	}
	if (skillShadow->cd > 0) {
		skillShadow->cd -= *p_dt;
	}
	if (skillMoon->cd > 0) {
		skillMoon->cd -= *p_dt;
	}
}

float Op::getCd(int num)
{
	switch (num) {
	case 1:
		return skillTeleport->cd;
		break;
	case 2:
		return skillSlow->cd;
		break;
	case 3:
		return skillEMP->cd;
		break;
	case 4:
		return skillShadow->cd;
		break;
	case 5:
		return skillMoon->cd;
		break;
	}
	return 0.0f;
}

bool Op::getTele()
{
	if (skillTeleport->ableBack == false) {
		return true;
	}
	return false;
}

void Op::getMoon()
{
	skillMoon->moon.active = true;
	skillMoon->moon.x = 100;
}

void Op::runMoon()
{
	skillMoon->moonRun();
}

void Op::reset() {
	moveJump->isOver();
	moveFall->isOver();
	moveSprint->isOver();
	skillChop->reset();
	skillTeleport->reset();
	skillTeleport->cd = 0;
	skillSlow->reset();
	skillSlow->cd = 0;
	skillEMP->reset();
	skillEMP->cd = 0;
	skillShadow->reset();
	skillShadow->cd = 0;
	skillMoon->reset();
	skillMoon->cd = 0;
	NItime = 0;
	recoverTime = 1.0f;
	currentKey = 0;
	storageTime = 0;
	lastKey = 0;
}