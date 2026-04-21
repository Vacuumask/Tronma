#include"SceneMain.h"

SceneMain::SceneMain()
{

    loadPicture();
    animationBackgroundMain = new AnimationBackgroundMain(&x, &y, &speed, &sceneWidth, pictures, &ground_Y, &ground_Height);
    player = new Player;
    initEnemies();
    initUI();
    op = new Op(player, &speed, &animationBackgroundMain->dt);

    gen = std::mt19937(rd());
    yDist = std::normal_distribution<float>((float)ground_Y, 200.0f);
    eDist = std::uniform_real_distribution<float>(0.0f, 1.0f);
}

SceneMain::~SceneMain()
{
    if (animationBackgroundMain != NULL) {
        delete animationBackgroundMain;
        animationBackgroundMain = NULL;
    }
    if (player != NULL) {
        delete player;
        player = NULL;
    }
    if (animation != NULL) {
        delete animation;
        animation = NULL;
    }
    if (op != NULL) {
        delete op;
        op = NULL;
    }
    for (int i = 0; i < ui.size(); i++) {
        if (ui[i] != NULL) {
            delete ui[i];
            ui[i] = NULL;
        }
    }
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i] != NULL) {
            delete enemies[i];
            enemies[i] = NULL;
        }
    }
}

void SceneMain::loadPicture()
{
    IMAGE img1, img2, img3, img4, img5;
    loadimage(&img1, "../image/background/main/city1/1.png", sceneWidth, sceneHeight);
    pictures.push_back(img1);
    loadimage(&img2, "../image/background/main/city1/2.png", sceneWidth, sceneHeight);
    pictures.push_back(img2);
    loadimage(&img3, "../image/background/main/city1/3.png", sceneWidth, sceneHeight);
    pictures.push_back(img3);
    loadimage(&img4, "../image/background/main/city1/4.png", sceneWidth, sceneHeight);
    pictures.push_back(img4);
    loadimage(&img5, "../image/background/main/city1/5.png", sceneWidth, sceneHeight);
    pictures.push_back(img5);
    IMAGE img6;
    loadimage(&img6, "../image/background/main/ground.png", 32, 32);
    pictures.push_back(img6);
}

void SceneMain::update()
{
}

void SceneMain::render()
{
}

void SceneMain::handleEvents()
{
    animationBackgroundMain->run();
    player->animationPlayerRun();
    op->opRun();

    generateEnemy();
    enemies[0]->run(&animationBackgroundMain->dt);
    enemies[1]->run(&animationBackgroundMain->dt);
    enemies[2]->run(&animationBackgroundMain->dt);
    enemies[3]->run(&animationBackgroundMain->dt);

    ui[0]->run();

    FlushBatchDraw();

    if (player->health == 0) {
        player->health = 7;
    }

}

void SceneMain::initEnemies()
{
    enemies.push_back(new Enemy1Pool(sceneWidth, &speed, player, sec_enum));
    enemies.push_back(new Enemy2Pool(sceneWidth, &speed, player, sec_enum));
    enemies.push_back(new Enemy3Pool(sceneWidth, &speed, player, sec_enum));
    enemies.push_back(new Enemy4Pool(sceneWidth, &speed, player, sec_enum));
}

void SceneMain::generateEnemy()
{
    if (eDist(gen) < 1.0f / (60.0f + 100.0f * (float)enemyNum())) {
        int sec = generateEnemySection();
        switch (sec) {
        case 3:
            if (eDist(gen) < 0.8f) {
                enemies[0]->acquire(3);
            }
            else {
                enemies[1]->acquire(3);
            }
            break;
        case 2:
        case 1:
        case 0:
            if (sec_enum[sec] == 0 && eDist(gen) < 0.8) {
                enemies[2]->acquire(sec);
            }
            else {
                enemies[3]->acquire(sec);
            }
        }
    }
}

int SceneMain::generateEnemySection()
{
    float y = yDist(gen);
    if (y < 0)y = 0;
    if (y > ground_Y)y = ground_Y;
    int sec = y / 115;
    return sec;
}

int SceneMain::enemyNum()
{
    return sec_enum[0] + sec_enum[1] + sec_enum[2] + sec_enum[3] + sec_enum[4];
}

void SceneMain::initUI()
{
    ui.push_back(new PlayerCondition(player));
}
