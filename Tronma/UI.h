#pragma once
#include"Animation.h"
#include"Player.h"
#include"Op.h"
#include"tools.hpp"

class UI :public Animation {
public:
	virtual ~UI() = 0;
	virtual void loadPicture() = 0;
	virtual void run() = 0;

	float all_y = 600;
protected:
	std::vector<IMAGE> pictures;
	int sceneWidth = 1024;
	int sceneHeight = 600;
};

class Title :public UI{
public:
	Title(bool* enterGame);
	~Title();
	void loadPicture()override;
	void run()override;
protected:
	float title_y = 70;
	float title_width = 720;
	float title_height = 120;
	bool* enterGame;
	float titleTime = 3.2;
};

class MenuOptions :public UI {
public:
	MenuOptions(bool* enterGame);
	~MenuOptions();
	void loadPicture()override;
	void run()override;

	float option_x;
	float option_width = 350;
	float option_height = 60;
	float option_gap = 20;

	float option1_y = 260;
	float option2_y;
	float option3_y;

protected:
	bool* enterGame;
	float enterTime = 5.6;
};

class MainOptions :public UI {
public:
	MainOptions(bool* startGame, bool* chooseMap, bool* chooseMusic);
	~MainOptions();
	void loadPicture()override;
	void run()override;

	float start_x = 840;
	float start_y = 520;
	float start_width = 150;
	float start_height = 60;

	float exit_x = 34;
	float exit_y = 520;
	float exit_width = 150;
	float exit_height = 60;

	float map_x = 540;
	float music_x = 800;
	float sl_y = 80;
	float sl_width = 210;
	float sl_height = 35;
	float sl_gap = 5;
	float dis1 = 0;
	float dis2 = 0;

	static int map;
	static int music;
protected:
	bool* startGame;
	bool* chooseMap;
	bool* chooseMusic;
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
	float attack_time;

	float health_x = 35;
	float stamina_x = 70;
	float hs_y = 110;
	int hs_width = 15;
	float health_height = 133.0f;
	float stamina_height = 133.0f;
	float hsBorder_thick = 4;

	int* health;
	int* energy;
	int temp_health = 7;
};

class SkillCondition :public UI {
public:
	SkillCondition(Op* op);
	~SkillCondition();
	void loadPicture()override;
	void run()override;
protected:
	float skill_x = 322;
	float skill_y = 520;
	float skill_width = 60;
	float skill_height = 60;
	float skill_gap = 20;

	Op* op = NULL;
};

class Progress :public UI {
public:
	Progress();
	void loadPicture()override;
	void run()override;
protected:
	float score_x = 10;
	float score_y = 520;
	float score_width = 270;
	float score_height = 60;
};

class EndTable :public UI {
public:
	EndTable(int* play_num);
	void loadPicture()override;
	void run()override;
protected:
	int* play_num;

	float table_width = 700;
	float table_height = 440;

	float score_x = 220;
	float score_y = 150;
	float score_width = 270;
	float score_height = 290;

	float kill_x = 534;
	float kill_y = 150;
	float kill_width = 270;
	float kill_height = 240;

	float back_x = 534;
	float back_y = 400;
	float back_width = 270;
	float back_height = 40;

	float e_x = 554;
	float e_y = 180;
	float e_size = 40;
	float e_gap = 10;
};