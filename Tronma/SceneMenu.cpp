#include"SceneMenu.h"

SceneMenu::SceneMenu()
{
    loadPicture();
    animationBackgroundMenu = new AnimationBackgroundMenu(&x, &y, pictures, &enterGame);
    initUI();
    Scene::press.load("../audio/fx/press.wav", 2);
    Scene::enterGame.load("../audio/fx/enterGame.wav", 2);
}

SceneMenu::~SceneMenu()
{
    if (animationBackgroundMenu != NULL) {
        delete animationBackgroundMenu;
        animationBackgroundMenu = NULL;
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

void SceneMenu::handleEvents()
{
    animationBackgroundMenu->run();
    ui[1]->run();
    ui[0]->run();
    if (instruction == true) {
        showInsTable();
        ui[3]->run();
    }
    FlushBatchDraw();
    optionsRun();
    playMusic();
}

void SceneMenu::optionsRun()
{
    ExMessage msg;
    if (enterGame == true && instruction == false) {
        if (peekmessage(&msg, EM_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                if (msg.x >= 337 && msg.x <= 687 && msg.y >= 260 && msg.y <= 320) {
                    press.play();
                    startMain = true;
                }
                if (msg.x >= 337 && msg.x <= 687 && msg.y >= 340 && msg.y <= 400) {
                    press.play();
                    instruction = true;
                    ins_num = 0;
                }
                if (msg.x >= 337 && msg.x <= 687 && msg.y >= 420 && msg.y <= 480) {
                    press.play();
                    exitGame = true;
                }
            }
        }
    }
    else if (instruction == true) {
        if (peekmessage(&msg, EM_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                if (msg.x >= 120 && msg.x <= 200 && msg.y >= 240 && msg.y <= 360) {
                    ins_num = 11;
                    press.play();
                }
                else if (ins_num >= 11 && ins_num < 16 && msg.x >= 772 && msg.x <= 792 && msg.y >= 230 && msg.y <= 290) {
                    ins_num++;
                    press.play();
                }
                else if (ins_num > 11 && ins_num <= 16 && msg.x >= 232 && msg.x <= 252 && msg.y >= 230 && msg.y <= 290) {
                    ins_num--;
                    press.play();
                }
                else if (msg.x >= 322 && msg.x <= 382 && msg.y >= 480 && msg.y <= 540) {
                    ins_num = 21;
                    press.play();
                }
                else if (msg.x >= 402 && msg.x <= 462 && msg.y >= 480 && msg.y <= 540) {
                    ins_num = 22;
                    press.play();
                }
                else if (msg.x >= 482 && msg.x <= 542 && msg.y >= 480 && msg.y <= 540) {
                    ins_num = 23;
                    press.play();
                }
                else if (msg.x >= 562 && msg.x <= 622 && msg.y >= 480 && msg.y <= 540) {
                    ins_num = 24;
                    press.play();
                }
                else if (msg.x >= 642 && msg.x <= 702 && msg.y >= 480 && msg.y <= 540) {
                    ins_num = 25;
                    press.play();
                }
                else if (msg.x >= 820 && msg.x <= 920 && msg.y >= 100 && msg.y <= 200) {
                    ins_num = 31;
                    press.play();
                }
                else if (msg.x >= 820 && msg.x <= 920 && msg.y >= 200 && msg.y <= 300) {
                    ins_num = 32;
                    press.play();
                }
                else if (msg.x >= 820 && msg.x <= 920 && msg.y >= 300 && msg.y <= 400) {
                    ins_num = 33;
                    press.play();
                }
                else if (msg.x >= 820 && msg.x <= 920 && msg.y >= 400 && msg.y <= 500) {
                    ins_num = 34;
                    press.play();
                }
                else if (msg.x >= 362 && msg.x <= 662 && msg.y >= 554 && msg.y <= 594) {
                    instruction = false;
                    press.play();
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
    ui.push_back(new InsTable(&ins_num));
    ui.push_back(new SkillCondition());
}

void SceneMenu::showInsTable()
{
    ui[2]->run();
}
