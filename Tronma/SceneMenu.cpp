#include"SceneMenu.h"

SceneMenu::SceneMenu()
{
    loadPicture();
    animationBackgroundMenu = new AnimationBackgroundMenu(&x, &y, pictures, &enterGame);
    initUI();
    
}

SceneMenu::~SceneMenu()
{
    if (animation != NULL) {
        delete animation;
        animation = NULL;
    }
    for (int i = 0; i < ui.size(); i++) {
        if (ui[i] != NULL) {
            delete ui[i];
            ui[i] = NULL;
        }
    }
}

void SceneMenu::loadPicture()
{
    IMAGE img1, img2;
    loadimage(&img1, "../image/background/menu/background1.png", sceneWidth, sceneHeight);
    pictures.push_back(img1);
    loadimage(&img2, "../image/background/menu/background2.png", sceneWidth, sceneHeight);
    pictures.push_back(img2);
}

void SceneMenu::update()
{
}

void SceneMenu::render()
{
}

void SceneMenu::handleEvents()
{
    animationBackgroundMenu->run();
    ui[1]->run();
    ui[0]->run();
    FlushBatchDraw();
    optionsRun();
    playMusic();
}

void SceneMenu::optionsRun()
{
    ExMessage msg;
    if (enterGame == true) {
        if (peekmessage(&msg, EM_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                if (msg.x >= 337 && msg.x <= 687 && msg.y >= 260 && msg.y <= 320) {
                    startMain = true;
                }
                if (msg.x >= 337 && msg.x <= 687 && msg.y >= 420 && msg.y <= 480) {
                    exitGame = true;
                }
            }
        }
    }
}

void SceneMenu::playMusic()
{
    if (!MusicPlayer::isPlaying1()) {
        MusicPlayer::play1("../audio/music/black_dragon1.wav");
    }
    MusicPlayer::setVolume1(bg1vol);
    if (!MusicPlayer::isPlaying2()) {
        MusicPlayer::play2("../audio/music/black_dragon2.wav");
    }
    MusicPlayer::setVolume2(bg2vol);
    
    if (Scene::bg1vol < Scene::max_vol) {
        Scene::bg1sp += animationBackgroundMenu->dt / 15;
        Scene::bg1vol += Scene::bg1sp * Scene::bg1sp;
    }
    else {
        Scene::bg1vol = Scene::max_vol;
        Scene::bg1sp = 0.0f;
    }

    if (Scene::bg2vol > 0.0f) {
        Scene::bg2sp += animationBackgroundMenu->dt / 15;
        Scene::bg2vol -= Scene::bg1sp * Scene::bg1sp;
    }
    else {
        Scene::bg2vol = 0.0f;
        Scene::bg2sp = 0.0f;
    }
}

void SceneMenu::initUI()
{
    ui.push_back(new Title(&enterGame));
    ui.push_back(new MenuOptions(&enterGame));
}