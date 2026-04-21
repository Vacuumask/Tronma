#pragma once
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<vector>

#include"Animation.h"
#include"Op.h"
#include"UI.h"

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void loadPicture() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvents() = 0;
protected:
	int sceneWidth = 1024;
	int sceneHeight = 600;
	Animation* animation = NULL;
	Op* op = NULL;
	std::vector<UI*> ui;
};