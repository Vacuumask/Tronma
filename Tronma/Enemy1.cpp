#include "Enemy1.h"

Enemy1::Enemy1()
{
}

Enemy1::~Enemy1()
{
    if (player != NULL) {
        delete player;
        player = NULL;
    }
    if (animationEnemy != NULL) {
        delete animationEnemy;
        animationEnemy = NULL;
    }
}

void Enemy1::init() {
    y = 207;
    width = 650;
    height = 400;

    c_x = 455;
    c_y = 182;
    c_width = 72;
    c_height = 81;

    loadPicture();
    animationEnemy = new AnimationEnemy(&x, &y, xspeed, pictures);
}

void Enemy1::loadPicture()
{
    IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6;
    loadimage(&img0_1, "../image/enemy/1/run1.png", width, height);
    pictures.push_back(img0_1);
    loadimage(&img0_2, "../image/enemy/1/run2.png", width, height);
    pictures.push_back(img0_2);
    loadimage(&img0_3, "../image/enemy/1/run3.png", width, height);
    pictures.push_back(img0_3);
    loadimage(&img0_4, "../image/enemy/1/run4.png", width, height);
    pictures.push_back(img0_4);
    loadimage(&img0_5, "../image/enemy/1/run5.png", width, height);
    pictures.push_back(img0_5);
    loadimage(&img0_6, "../image/enemy/1/run6.png", width, height);
    pictures.push_back(img0_6);

    IMAGE img1_1, img1_2, img1_3, img1_4, img1_5, img1_6, img1_7, img1_8, img1_9, img1_10, img1_11, img1_12, img1_13;
    loadimage(&img1_1, "../image/effect/ex1g.png", 128, 128);
    pictures.push_back(img1_1);
    loadimage(&img1_2, "../image/effect/ex2g.png", 128, 128);
    pictures.push_back(img1_2);
    loadimage(&img1_3, "../image/effect/ex3g.png", 128, 128);
    pictures.push_back(img1_3);
    loadimage(&img1_4, "../image/effect/ex4g.png", 128, 128);
    pictures.push_back(img1_4);
    loadimage(&img1_5, "../image/effect/ex5g.png", 128, 128);
    pictures.push_back(img1_5);
    loadimage(&img1_6, "../image/effect/ex6g.png", 128, 128);
    pictures.push_back(img1_6);
    loadimage(&img1_7, "../image/effect/ex7g.png", 128, 128);
    pictures.push_back(img1_7);
    loadimage(&img1_8, "../image/effect/ex8g.png", 128, 128);
    pictures.push_back(img1_8);
    loadimage(&img1_9, "../image/effect/ex9g.png", 128, 128);
    pictures.push_back(img1_9);
    loadimage(&img1_10, "../image/effect/ex10g.png", 128, 128);
    pictures.push_back(img1_10);
    loadimage(&img1_11, "../image/effect/ex11g.png", 128, 128);
    pictures.push_back(img1_11);
    loadimage(&img1_12, "../image/effect/ex12g.png", 128, 128);
    pictures.push_back(img1_12);
    loadimage(&img1_13, "../image/effect/void.png", 128, 128);
    pictures.push_back(img1_13);

}

void Enemy1::run(float *dt)
{
    if (active == true) {
        x -= *xspeed * 2 * *dt * Animation::p_speed;
        if (alive == true) {
            animationEnemy->run(1);
            if (collide()) {
                damage();
            }
            if (collideS()) {
                damageS();
            }
        }
        else {
            animationEnemy->run(-1);
        }

        if (x <= -width) {
            isOver();
        }

        if (attackedCollide() && alive == true) {
            beDamaged();
        }
    }
}

bool Enemy1::collide()
{
    if (active == true && canDamage == true && alive == true) {
        return !(x + c_x > player->x + player->c_x + player->c_width || x + c_x + c_width<player->x + player->c_x ||
            y + c_y>player->y + player->c_y + player->c_height || y + c_y + c_height < player->y + player->c_y);
    }
    return false;
}

bool Enemy1::collideS()
{
    if (active == true && alive == true) {
        return !(x + c_x > shadow->x + shadow->c_x + shadow->c_width || x + c_x + c_width<shadow->x + shadow->c_x ||
            y + c_y>shadow->y + shadow->c_y + shadow->c_height || y + c_y + c_height < shadow->y + shadow->c_y);
    }
    return false;
}

void Enemy1::damage()
{
    canDamage = false;
    if (player->canBeDamaged == true) {
        player->health--;
    }
}

void Enemy1::damageS()
{
    shadow->health = 0;
}

bool Enemy1::attackedCollide()
{
    if (active == true && alive == true) {
        for (int i = 0; i < player->attack.size(); i++) {
            if (player->attack[i]->active == true) {
                switch (i) {
                case 0:
                    if (canBeDamaged == true) {
                        if (!(x + c_x > player->x + player->attack[i]->x + player->attack[i]->width || x + c_x + c_width<player->x + player->attack[i]->x ||
                            y + c_y>player->y + player->attack[i]->y + player->attack[i]->height || y + c_y + c_height < player->y + player->attack[i]->y)) {
                            player->damage = true;
                            return true;
                        }
                    }
                    break;
                default:
                    if (!(x + c_x > player->attack[i]->x + player->attack[i]->width || x + c_x + c_width<player->attack[i]->x ||
                        y + c_y>player->attack[i]->y + player->attack[i]->height || y + c_y + c_height < player->attack[i]->y)) {
                        return true;
                    }
                    break;
                }
            }
        }
    }
    return false;
}

void Enemy1::beDamaged()
{
    canDamage = false;
    alive = false;
    if (Enemy::start == false) {
        Player::kill_score += 50;
        Player::kill[0]++;
    }
}

void Enemy1::isOver()
{
    x = -width;
    *sec_enum -= 1;
    active = false;
    canDamage = false;
    alive = false;
}

Enemy1Pool::Enemy1Pool(int& sceneWidth, float* speed, Player* player, Player* shadow, int* sec_enum)
{
    this->player = player;
    this->sec_enum = sec_enum;
    for (int i = 0; i < pool_Size; i++) {
        enemy1[i].player = player;
        enemy1[i].shadow = shadow;
        enemy1[i].start_x = sceneWidth - 300;
        enemy1[i].xspeed = speed;
        enemy1[i].sec_enum = sec_enum;
        enemy1[i].init();
    }
}

Enemy1Pool::~Enemy1Pool()
{
    if (player != NULL) {
        delete player;
        player = NULL;
    }
}

void Enemy1Pool::acquire(int sec)
{
    for (int i = 0; i < pool_Size; i++) {
        if (enemy1[i].active == false) {
            if (Enemy::start == true) {
                enemy1[i].x = 500;
            }
            else {
                enemy1[i].x = enemy1[i].start_x;
            }
            enemy1[i].active = true;
            enemy1[i].canDamage = true;
            enemy1[i].alive = true;
            enemy1[i].sec_enum = &sec_enum[sec];
            sec_enum[sec]++;
            //std::cout << sec_enum[sec];
            break;
        }
    }
}

void Enemy1Pool::run(float* dt) {
    for (int i = 0; i < pool_Size; i++) {
        enemy1[i].run(dt);
    }
}

void Enemy1Pool::isOver()
{
    for (int i = 0; i < pool_Size; i++) {
        enemy1[i].isOver();
        enemy1[i].animationEnemy->reset();
    }
}
