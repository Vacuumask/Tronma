#pragma once
#include"Animation.h"
#include"Player.h"
#include"tools.hpp"

class UI :public Animation {
public:
	virtual ~UI() = 0;
	virtual void loadPicture() = 0;
	virtual void run() = 0;
protected:
	std::vector<IMAGE> pictures;
	int sceneWidth = 1024;
	int sceneHeight = 600;
};

class PlayerCondition :public UI {
public:
	PlayerCondition(Player* player);
	~PlayerCondition();
	void loadPicture()override;
	void run()override;
protected:
	float profile_x = 20;
	float profile_y = 20;
	int profile_width = 80;
	int profile_height = 80;
	float profileBorder_thick = 4;

	float health_x = 35;
	float stamina_x = 70;
	float hs_y = 110;
	int hs_width = 15;
	float health_height = 133.0f;
	float stamina_height = 133.0f;
	float hsBorder_thick = 4;

	int* health;
	int* energy;
};