#pragma once
#include<graphics.h>
#include<windows.h>
#include<mmsystem.h>
#include<iostream>
#include<vector>
#include<cstring>

#include"Animation.h"
#include"Op.h"
#include"UI.h"
#include"Audio.h"

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void loadPicture() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvents() = 0;
	virtual void optionsRun() = 0;
	virtual void playMusic() = 0;
	bool startMenu = false;
	bool startMain = false;
	bool exitGame = false;

	static float bg1vol;
	static float bg1sp;
	static float bg2vol;
	static float bg2sp;
	static float max_vol;
protected:
	int sceneWidth = 1024;
	int sceneHeight = 600;
	Animation* animation = NULL;
	Op* op = NULL;
	std::vector<UI*> ui;

	
};