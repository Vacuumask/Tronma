#pragma once
#include"Scene.h"

class SceneMenu :public Scene {
public:
	SceneMenu() = default;
	void update() override;
	void render()override;
	void handleEvents() override;
private:
};