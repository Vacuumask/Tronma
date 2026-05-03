#pragma once
#include<random>
#include<algorithm>

#include"Scene.h"
#include"Player.h"
#include"Enemy1.h"
#include"Enemy2.h"
#include"Enemy3.h"
#include"Enemy4.h"
#include"AnimationBackgroundMain.h"
#include"AnimationPlayer.h"
#include"AnimationEnemy.h"
#include"UI.h"

class SceneMain :public Scene {
public:
	SceneMain();
	~SceneMain();
	void loadPicture()override;
	void update()override;
	void render()override;
	void handleEvents()override;
	void optionsRun()override;
	void playMusic()override;

	void initEnemies();
	void generateEnemy();
	int generateEnemySection();
	int enemyNum();

	void initUI();

	void startAniRun();

	void countScore();
	void drawScore();
	void showEndTable();
	void endScore();

	void reset();

	bool startGame = false;
	bool startAni = false;
	bool chooseMap = false;
	bool chooseMusic = false;
	bool endTable = false;

	char introName[50] = "../audio/music/encounter_in.wav";
	char musicName[50] = "../audio/music/encounter.wav";
private:
	std::vector<IMAGE> pictures;
	float x = 0, y = 0;
	float speed = 300.0f;
	AnimationBackgroundMain* animationBackgroundMain = NULL;
	Player* player = NULL;
	Player* shadow = NULL;
	std::vector<EnemyPool*> enemies;
	int ground_Y = 470;
	int ground_Height = 20;
	int sec_enum[5] = { 0,0,0,0,0 };

	float startTime = 12;

	bool start_enemy = true;

	bool moon = true;

	float dieTime = 5;

	double dis = 0;

	int play_num = 0;

	std::random_device rd;
	std::mt19937 gen;
	std::normal_distribution<float>yDist;
	std::uniform_real_distribution<float>eDist;
};