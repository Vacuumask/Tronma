#pragma once
#include<conio.h>

#include"Scene.h"
#include"AnimationBackgroundMenu.h"
#include"UI.h"

class SceneMenu :public Scene {
public:
	SceneMenu();
	~SceneMenu();
	void loadPicture()override;
	void update() override;
	void render()override;
	void handleEvents() override;
	void optionsRun()override;
	void playMusic()override;

	void initUI();

	bool enterGame = false;

private:
	std::vector<IMAGE> pictures;
	float x = 0, y = 0;
	AnimationBackgroundMenu* animationBackgroundMenu = NULL;
	
};