#pragma once
#include<iostream>

#include"SceneMain.h"
#include"SceneMenu.h"
#include"Player.h"

class Game {
public:
	Game();
	~Game();
	void run();
	void init();
	void clean();
	void changeScene(Scene* scene);
	bool isWindowAlive();

private:
	bool isRunning = true;
	Scene* currentScene = NULL;
	SceneMenu* sceneMenu = NULL;
	SceneMain* sceneMain = NULL;
	const int widgetWidth = 1024;
	const int widgetHeight = 600;
	Animation* animation = NULL;
	Player* player = NULL;


};