#include "Game.h"
#include "Audio.h"

Game::Game()
{
	init();
	changeScene(sceneMenu);
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
		if (currentScene->startMenu == true) {
			currentScene->startMenu = false;
			changeScene(sceneMenu);
		}
		if (currentScene->startMain == true) {
			currentScene->startMain = false;
			changeScene(sceneMain);
		}
		currentScene->handleEvents();
		if (currentScene->exitGame == true) {
			break;
		}
	}
	closegraph();
	return;
}

void Game::init()
{
	initgraph(widgetWidth, widgetHeight, EW_SHOWCONSOLE);
	setbkcolor(BLACK);
	cleardevice();
	MusicPlayer::init();
	sceneMenu = new SceneMenu;
	sceneMain = new SceneMain;
}


void Game::clean()
{
	if (sceneMenu != NULL) {
		delete sceneMenu;
	}
	if (sceneMain != NULL) {
		delete sceneMain;
	}
}

void Game::changeScene(Scene* scene)
{
	currentScene = scene;
}

bool Game::isWindowAlive()
{
	HWND hwnd = GetHWnd();
	return IsWindow(hwnd);
}


