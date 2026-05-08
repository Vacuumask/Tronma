#include"SceneMain.h"

SceneMain::SceneMain()
{

    loadPicture();
    animationBackgroundMain = new AnimationBackgroundMain(&x, &y, &speed, &sceneWidth, pictures, &ground_Y, &ground_Height, &startGame);
    player = new Player(&speed);
    shadow = new Player(&speed);

    shadow->y = -150;

    initEnemies();
    op = new Op(player, shadow, &speed, &animationBackgroundMain->dt);
    initUI();

    gen = std::mt19937(rd());
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
    if (shadow != NULL) {
        delete shadow;
        shadow = NULL;
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
    IMAGE img0_1, img0_2, img0_3, img0_4, img0_5;
    loadimage(&img0_1, "../image/background/main/city1/1.png", sceneWidth, sceneHeight);
    pictures.push_back(img0_1);
    loadimage(&img0_2, "../image/background/main/city1/2.png", sceneWidth, sceneHeight);
    pictures.push_back(img0_2);
    loadimage(&img0_3, "../image/background/main/city1/3.png", sceneWidth, sceneHeight);
    pictures.push_back(img0_3);
    loadimage(&img0_4, "../image/background/main/city1/4.png", sceneWidth, sceneHeight);
    pictures.push_back(img0_4);
    loadimage(&img0_5, "../image/background/main/city1/5.png", sceneWidth, sceneHeight);
    pictures.push_back(img0_5);

    IMAGE img1_1, img1_2, img1_3, img1_4, img1_5, img1_6;
    loadimage(&img1_1, "../image/background/main/city2/1.png", sceneWidth, sceneHeight);
    pictures.push_back(img1_1);
    loadimage(&img1_2, "../image/background/main/city2/2.png", sceneWidth, sceneHeight);
    pictures.push_back(img1_2);
    loadimage(&img1_3, "../image/background/main/city2/3.png", sceneWidth, sceneHeight);
    pictures.push_back(img1_3);
    loadimage(&img1_4, "../image/background/main/city2/4.png", sceneWidth, sceneHeight);
    pictures.push_back(img1_4);
    loadimage(&img1_5, "../image/background/main/city2/5.png", sceneWidth, sceneHeight);
    pictures.push_back(img1_5);
    loadimage(&img1_6, "../image/background/main/city2/6.png", sceneWidth, sceneHeight);
    pictures.push_back(img1_6);

    IMAGE img2_1, img2_2, img2_3, img2_4, img2_5;
    loadimage(&img2_1, "../image/background/main/city3/1.png", sceneWidth, sceneHeight);
    pictures.push_back(img2_1);
    loadimage(&img2_2, "../image/background/main/city3/2.png", sceneWidth, sceneHeight);
    pictures.push_back(img2_2);
    loadimage(&img2_3, "../image/background/main/city3/3.png", sceneWidth, sceneHeight);
    pictures.push_back(img2_3);
    loadimage(&img2_4, "../image/background/main/city3/4.png", sceneWidth, sceneHeight);
    pictures.push_back(img2_4);
    loadimage(&img2_5, "../image/background/main/city3/5.png", sceneWidth, sceneHeight);
    pictures.push_back(img2_5);

    IMAGE img6;
    loadimage(&img6, "../image/background/main/ground.png", 32, 32);
    pictures.push_back(img6);
}

void SceneMain::handleEvents()
{
    Animation::p_speed = Animation::base_speed + Animation::pro_speed;
    startAniRun();
    
    enemies[0]->run(&animationBackgroundMain->dt);
    enemies[1]->run(&animationBackgroundMain->dt);
    enemies[2]->run(&animationBackgroundMain->dt);
    enemies[3]->run(&animationBackgroundMain->dt);
    
    if (startTime >= 9 || startTime <= 0) {
        ui[0]->run();
        ui[2]->run();
    }

    if (startTime >= 9) {
        ui[1]->run();
    }

    if (startAni == true) {
        if (player->op_num == 5)player->op_num = 63;
        if (startTime > 0) {
            startTime -= animationBackgroundMain->dt;
        }
    }


    if (startGame == true) {
        if (player->dis_score <= 40000) {
            Animation::pro_speed = ((float)player->dis_score / 60000);
        }
        
        op->opRun();
        if (player->die == false || shadow->health == 1) {
            if (player->die == false) {
                generateEnemy();
                if (player->health <= 0) {
                    player->health = 0;
                    player->canBeDamaged = false;
                    player->die = true;
                    player->FxDie.play();
                }
            }
            countScore();
        }

        player->recover();

        if(player->die == true) {
            player->canBeDamaged = false;
            player->y = 340;
            if (shadow->health == 1) {
                Animation::base_speed = 1.0f;
            }
            else {
                op->reset();
                speed = 300.0f;
                Animation::base_speed = 0.0f;
                Animation::pro_speed = 0.0f;
                dieTime -= animationBackgroundMain->dt;
            }

            player->op_num = 99;
        }

        

        if (dieTime <= 0) {
            showEndTable();
        }
        else {
            ui[3]->run();
            drawScore();
        }
    }

    playMusic();
    optionsRun();

    FlushBatchDraw();
}

void SceneMain::optionsRun()
{
    ExMessage msg;
    if (startGame == false && startAni == false) {
        if (peekmessage(&msg, EM_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                if (msg.x >= 840 && msg.x <= 990 && msg.y >= 520 && msg.y <= 580) {
                    enterGame.play();
                    startAni = true;
                }
                if (msg.x >= 34 && msg.x <= 184 && msg.y >= 520 && msg.y <= 580) {
                    press.play();
                    startMenu = true;
                }
                if (msg.x >= 540 && msg.x <= 750 && msg.y >= 80 && msg.y <= 115 && chooseMap == false) {
                    press.play();
                    chooseMap = true;
                }
                else {
                    if (chooseMap == true) {
                        if (msg.x >= 498 && msg.x <= 750 && msg.y >= 120 && msg.y <= 155 && chooseMap == true) {
                            press.play();
                            MainOptions::map = 1;
                            animationBackgroundMain->bk_num = 0;
                            animationBackgroundMain->bk_size = 5;
                        }
                        if (msg.x >= 498 && msg.x <= 750 && msg.y >= 160 && msg.y <= 195 && chooseMap == true) {
                            press.play();
                            MainOptions::map = 2;
                            animationBackgroundMain->bk_num = 5;
                            animationBackgroundMain->bk_size = 6;
                        }
                        if (msg.x >= 498 && msg.x <= 750 && msg.y >= 200 && msg.y <= 235 && chooseMap == true) {
                            press.play();
                            MainOptions::map = 3;
                            animationBackgroundMain->bk_num = 11;
                            animationBackgroundMain->bk_size = 5;
                        }
                    }
                    chooseMap = false;
                }
                if (msg.x >= 800 && msg.x <= 1010 && msg.y >= 80 && msg.y <= 115 && chooseMusic == false) {
                    press.play();
                    chooseMusic = true;
                }
                else {
                    if (chooseMusic == true) {
                        if (msg.x >= 758 && msg.x <= 1010 && msg.y >= 120 && msg.y <= 155 && chooseMusic == true) {
                            press.play();
                            MainOptions::music = 1;
                            strcpy_s(introName, "../audio/music/encounter_in.wav");
                            strcpy_s(musicName, "../audio/music/encounter.wav");
                        }
                        if (msg.x >= 758 && msg.x <= 1010 && msg.y >= 160 && msg.y <= 195 && chooseMusic == true) {
                            press.play();
                            MainOptions::music = 2;
                            strcpy_s(introName, "../audio/music/conflict_in.wav");
                            strcpy_s(musicName, "../audio/music/conflict.wav");
                        }
                        if (msg.x >= 758 && msg.x <= 1010 && msg.y >= 200 && msg.y <= 235 && chooseMusic == true) {
                            press.play();
                            MainOptions::music = 3;
                            strcpy_s(introName, "../audio/music/The_Orb_in.wav");
                            strcpy_s(musicName, "../audio/music/The_Orb.wav");
                        }
                        if (msg.x >= 758 && msg.x <= 1010 && msg.y >= 240 && msg.y <= 275 && chooseMusic == true) {
                            press.play();
                            MainOptions::music = 4;
                            strcpy_s(introName, "../audio/music/Air_in.wav");
                            strcpy_s(musicName, "../audio/music/Air.wav");
                        }
                        if (msg.x >= 758 && msg.x <= 1010 && msg.y >= 280 && msg.y <= 315 && chooseMusic == true) {
                            press.play();
                            MainOptions::music = 5;
                            strcpy_s(introName, "../audio/music/shenmi_in.wav");
                            strcpy_s(musicName, "../audio/music/shenmi.wav");
                        }
                    }
                    chooseMusic = false;
                }
            }
        }
    }
    else if (endTable == true) {
        if (peekmessage(&msg, EM_MOUSE)) {
            if (msg.message == WM_LBUTTONDOWN) {
                if (msg.x >= 534 && msg.x <= 804 && msg.y >= 400 && msg.y <= 440) {
                    press.play();
                    reset();
                }
            }
        }
    }
}

void SceneMain::initEnemies()
{
    enemies.push_back(new Enemy1Pool(sceneWidth, &speed, player, shadow, sec_enum));
    enemies.push_back(new Enemy2Pool(sceneWidth, &speed, player, shadow, sec_enum));
    enemies.push_back(new Enemy3Pool(sceneWidth, &speed, player, sec_enum));
    enemies.push_back(new Enemy4Pool(sceneWidth, &speed, player, sec_enum));
}

void SceneMain::generateEnemy()
{
    float pro = 200.0f * exp(-0.0004 * (float)player->dis_score);
    if (pro < 30)pro = 30;

    for (int i = 0; i < 4; i++) {
        if (generate_cd[i] > 0) {
            generate_cd[i] -= animationBackgroundMain->dt;
        }
    }
    
    int sec = generateEnemySection();
    if ((eDist(gen) < 1.0f / (pro + 0.4 * pro * (float)enemyNum() + (sec == 3 ? 7 : 60) * pro * sec_enum[sec])) && generate_cd[sec] <= 0) {
        switch (sec) {
        case 3:
            if (eDist(gen) < 0.8f && Player::dis_score >= 100) {
                enemies[0]->acquire(3);
            }
            else if (Player::dis_score >= 1000) {
                enemies[1]->acquire(3);
            }
            break;
        case 2:
        case 1:
        case 0:
            if (eDist(gen) < 0.8 && Player::dis_score >= 500) {
                enemies[2]->acquire(sec);
            }
            else if (sec_enum[sec] <= 1 && Player::dis_score >= 3000) {
                enemies[3]->acquire(sec);
            }
        }
        generate_cd[sec] = 0.5;
    }
}

int SceneMain::generateEnemySection()
{
    float y = eDist(gen);
    if (y <= 0.5) {
        return 3;
    }
    else if (y <= 0.7) {
        return 2;
    }
    else if (y <= 0.9) {
        return 1;
    }
    else {
        return 0;
    }
}

int SceneMain::enemyNum()
{
    return sec_enum[0] + sec_enum[1] + sec_enum[2] + sec_enum[3] + sec_enum[4];
}

void SceneMain::playMusic()
{
    if (startGame == false && startAni == false) {
        if (!MusicPlayer::isPlaying1()) {
            MusicPlayer::play1("../audio/music/black_dragon1.wav");
        }
        MusicPlayer::setVolume1(bg1vol);
        if (!MusicPlayer::isPlaying2()) {
            MusicPlayer::play2("../audio/music/black_dragon2.wav");
        }
        MusicPlayer::setVolume2(bg2vol);

        if (Scene::bg2vol < Scene::max_vol) {
            Scene::bg2sp += animationBackgroundMain->dt / 15;
            Scene::bg2vol += Scene::bg2sp * Scene::bg2sp;
        }
        else {
            Scene::bg2vol = Scene::max_vol;
            Scene::bg2sp = 0.0f;
        }

        if (Scene::bg1vol > 0.0f) {
            Scene::bg1sp += animationBackgroundMain->dt / 15;
            Scene::bg1vol -= Scene::bg2sp * Scene::bg2sp;
        }
        else {
            Scene::bg1vol = 0.0f;
            Scene::bg1sp = 0.0f;
        }
    }
    else if (startAni == true) {
        if (startTime > 8.2) {
            MusicPlayer::setVolume1(bg1vol);
            MusicPlayer::setVolume2(bg2vol);
            if (Scene::bg2vol > 0.0f) {
                Scene::bg2vol -= animationBackgroundMain->dt / 5;
            }
            else {
                Scene::bg2vol = 0.0f;
                Scene::bg2sp = 0.0f;
            }

            if (Scene::bg1vol > 0.0f) {
                Scene::bg1vol -= animationBackgroundMain->dt / 5;
            }
            else {
                Scene::bg1vol = 0.0f;
                Scene::bg1sp = 0.0f;
            }
        }
        else {
            bg1vol = max_vol;
            MusicPlayer::setVolume1(bg1vol);
            MusicPlayer::update();
            if (MusicPlayer::isPlayingIntro == true) {
                MusicPlayer::play1(musicName);
                MusicPlayer::playIntro(introName, 1);
                MusicPlayer::isPlayingIntro = false;
            }
        }
    }
}

void SceneMain::initUI()
{
    ui.push_back(new PlayerCondition(player));
    ui.push_back(new MainOptions(&startGame, &chooseMap, &chooseMusic));
    ui.push_back(new SkillCondition(op));
    ui.push_back(new Progress);
    ui.push_back(new EndTable(&play_num));
}

void SceneMain::startAniRun()
{
    if (startTime >= 9 || startTime <= 4) {
        animationBackgroundMain->run();
        player->animationPlayerRun();

        if (startTime >= 9) {
            Animation::base_speed = 0;
        }
        else if (startTime > 0) {
            if (Enemy::start == true && start_enemy == true) {
                enemies[0]->acquire(3);
                enemies[1]->acquire(3);
                enemies[2]->acquire(2);
                enemies[2]->acquire(1);
                start_enemy = false;
            }
            speed = 100;
            Animation::base_speed = 0.5;

            if (startTime <= 0.8) {
                if (player->op_num == 63)player->op_num = 64;
            }
            if (startTime <= 0.4) {
                if (moon == true) {
                    op->getMoon();
                    moon = false;
                }
                op->runMoon();
            }
        }
        else {
            if (player->op_num == 64) {
                player->op_num = 0;
                speed = 300;
                Animation::base_speed = 1.0;
                Enemy::start = false;
            }
            startGame = true;
            startAni = false;
        }
    }
    else {
        animationBackgroundMain->FPS();
        cleardevice();
        settextcolor(WHITE);
        setbkmode(TRANSPARENT);
        settextstyle(24, 0, "微软雅黑");
        if (sen == -1)sen = generateEnemySection();
        if (startTime < 8) {
            switch (sen) {
            case 0:
                outtextxy(350, 500, "TRON可以是任何事物，除了救世主。");
                break;
            case 1:
                outtextxy(350, 500, "瓦解人类的不是TRON，是我们自己。");
                break;
            case 2:
                outtextxy(350, 500, "是时候让这座城市走出TRON的阴影了。");
                break;
            case 3:
                outtextxy(380, 500, "它们能被创造，就能被抹除。");
                break;
            }
        }
    }
}

void SceneMain::countScore()
{
    dis += animationBackgroundMain->dt * speed * Animation::p_speed;
    if (dis > 100) {
        player->dis_score += 10;
        dis = 0;
    }
}

void SceneMain::drawScore()
{
    char text[50];
    sprintf_s(text, "%d", player->dis_score + player->kill_score);
    settextcolor(WHITE);
    settextstyle(50, 0, "Arial Black");
    setbkmode(TRANSPARENT);
    outtextxy(20, 525, text);
}

void SceneMain::showEndTable()
{
    if (endTable == false) {
        enemies[0]->isOver();
        enemies[1]->isOver();
        enemies[2]->isOver();
        enemies[3]->isOver();
        start_enemy = true;
        Enemy::start = true;

        ui[4]->all_y = 600;
        if (play_num < 5)play_num++;
        player->allScore[5] = player->dis_score + player->kill_score;
        endScore();
        endTable = true;
    }
    ui[4]->run();
}

void SceneMain::endScore()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (player->allScore[j] < player->allScore[j + 1]) {
                player->allScore[j] = player->allScore[j] ^ player->allScore[j + 1];
                player->allScore[j + 1] = player->allScore[j] ^ player->allScore[j + 1];
                player->allScore[j] = player->allScore[j] ^ player->allScore[j + 1];
            }
        }
    }
}

void SceneMain::reset() {
    dieTime = 5;
    startTime = 12;
    sen = -1;
    startGame = false;
    startAni = false;
    chooseMap = false;
    chooseMusic = false;
    moon = true;
    player->reset();
    Animation::base_speed = 1.0f;
    Animation::pro_speed = 0.0f;
    MusicPlayer::stop1();
    MusicPlayer::stopIn();
    MusicPlayer::isPlayingIntro = true;
    MusicPlayer::setVolume1(Scene::max_vol);
    MusicPlayer::setVolume2(0.0f);
    for (int i = 0; i < 5; i++) {
        sec_enum[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        generate_cd[i] = 0;
    }
    endTable = false;
    startMenu = true;
}