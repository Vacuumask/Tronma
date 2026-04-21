#include"Game.h"

Game::Game()
{
	init();
	changeScene(new SceneMain);
}

Game::~Game()
{
	clean();
}

void Game::run()
{
	BeginBatchDraw();
	while (isRunning) {
		if (!isWindowAlive()) {
			isRunning = false;
		}
		currentScene->handleEvents();
	}
	closegraph();
	return;
}

void Game::init()
{
	initgraph(widgetWidth, widgetHeight, EW_SHOWCONSOLE);
	setbkcolor(BLACK);
	cleardevice();
	animation = new Animation;
}

void Game::clean()
{
	if (currentScene != NULL) {
		delete currentScene;
	}
	if (animation != NULL) {
		delete animation;
	}
	if (player != NULL) {
		delete player;
	}
}

void Game::changeScene(Scene* scene)
{
	if (currentScene != NULL) {
		delete currentScene;
	}
	currentScene = scene;
}

bool Game::isWindowAlive()
{
	HWND hwnd = GetHWnd();
	return IsWindow(hwnd);
}


