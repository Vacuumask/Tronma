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
#include"UI.h"

class SceneMain :public Scene {
public:
	SceneMain();
	~SceneMain();
	void loadPicture()override;
	void update()override;
	void render()override;
	void handleEvents()override;

	void initEnemies();
	void generateEnemy();
	int generateEnemySection();
	int enemyNum();

	void initUI();
private:
	std::vector<IMAGE> pictures;
	float x = 0, y = 0;
	float speed = 300.0f;
	AnimationBackgroundMain* animationBackgroundMain = NULL;
	Player* player = NULL;
	std::vector<EnemyPool*> enemies;
	int ground_Y = 470;
	int ground_Height = 20;
	int sec_enum[5] = { 0,0,0,0,0 };

	std::random_device rd;
	std::mt19937 gen;
	std::normal_distribution<float>yDist;
	std::uniform_real_distribution<float>eDist;
};