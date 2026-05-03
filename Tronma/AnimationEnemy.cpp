#include "AnimationEnemy.h"
#include "AnimationEffect.h"

AnimationEnemy::AnimationEnemy(float* x, float* y, float* speed, std::vector<IMAGE>& pictures)
{
    a_x = x;
    a_y = y;
    a_speed = speed;
    a_pictures = pictures;
}

AnimationEnemy::~AnimationEnemy()
{
    if (animation != NULL) {
        delete animation;
        animation = NULL;
    }
}

void AnimationEnemy::run(int e_num) {
    FPS();

    reset(e_num);

    switch (e_num) {
    case 1:
        drawImg(*a_x, *a_y, &a_pictures[a_num1]);
        a_switch1 += dt * *a_speed / 300;
        if (a_switch1 >= 0.15) {
            a_switch1 = 0;
            a_num1++;
        }
        if (a_num1 == 6)a_num1 = 0;
        break;
    case -1:
        drawImg(*a_x+435, *a_y+150, &a_pictures[a_num_1]);
        a_switch_1 += dt * *a_speed / 300;
        if (a_switch_1 >= 0.02) {
            a_switch_1 = 0;
            a_num_1++;
        }
        if (a_num_1 == 19)a_num_1--;
        break;

    case 21:
        drawImg(*a_x, *a_y, &a_pictures[a_num21]);
        a_switch21 += dt * *a_speed / 300;
        if (a_switch21 >= 0.12) {
            a_switch21 = 0;
            a_num21++;
        }
        if (a_num21 == 8)a_num21 = 0;
        break;
    case 22:
        drawImg(*a_x, *a_y, &a_pictures[a_num22]);
        a_switch22 += dt * *a_speed / 300;
        if (a_switch22 >= 0.12) {
            a_switch22 = 0;
            a_num22++;
        }
        if (a_num22 == 12)a_num22 = 8;
        break;
    case 23:
        drawImg(*a_x, *a_y, &a_pictures[a_num23]);
        a_switch23 += dt * *a_speed / 300;
        if (a_switch23 >= 0.12) {
            a_switch23 = 0;
            a_num23++;
        }
        if (a_num23 == 16)a_num23--;
        break;
    case 24:
        drawImg(*a_x, *a_y, &a_pictures[a_num24]);
        a_switch24 += dt * *a_speed / 300;
        if (a_switch24 >= 0.1) {
            a_switch24 = 0;
            a_num24++;
        }
        if (a_num24 == 23)a_num24--;
        break;
    case 251:
        drawImg(*a_x, *a_y, &a_pictures[0]);
        break;
    case 252:
        drawImg(*a_x, *a_y, &a_pictures[1]);
        break;
    case -2:
        drawImg(*a_x + 250, *a_y, &a_pictures[a_num_2]);
        a_switch_2 += dt * *a_speed / 300;
        if (a_switch_2 >= 0.02) {
            a_switch_2 = 0;
            a_num_2++;
        }
        if (a_num_2 == 36)a_num_2--;
        break;

    case 31:
        drawImg(*a_x, *a_y, &a_pictures[a_num31]);
        a_switch31 += dt * *a_speed / 300;
        if (a_switch31 >= 0.12) {
            a_switch31 = 0;
            a_num31++;
        }
        if (a_num31 == 12)a_num31 = 0;
        break;
    case 32:
        drawImg(*a_x, *a_y, &a_pictures[a_num32]);
        a_switch32 += dt * *a_speed / 300;
        if (a_switch32 >= 0.12) {
            a_switch32 = 0;
            a_num32++;
        }
        if (a_num32 == 16)a_num32 = 0;
        break;
    case 331:
        drawImg(*a_x, *a_y, &a_pictures[0]);
        break;
    case 332:
        drawImg(*a_x, *a_y, &a_pictures[1]);
        break;
    case -3:
        drawImg(*a_x + 270, *a_y - 5, &a_pictures[a_num_3]);
        a_switch_3 += dt * *a_speed / 300;
        if (a_switch_3 >= 0.02) {
            a_switch_3 = 0;
            a_num_3++;
        }
        if (a_num_3 == 29)a_num_3--;
        break;

    case 41:
        drawImg(*a_x, *a_y, &a_pictures[0]);
        break;
    case 42:
        drawImg(*a_x, *a_y, &a_pictures[a_num42]);
        a_switch42 += dt * *a_speed / 300;
        if (a_switch42 >= 0.5) {
            a_switch42 = 0;
            a_num42++;
        }
        if (a_num42 == 4)a_num42--;
        break;
    case 43:
        drawImg(*a_x, *a_y, &a_pictures[4]);
        break;
    case 44:
        drawImg(*a_x, *a_y, &a_pictures[a_num44]);
        a_switch44 += dt * *a_speed / 300;
        if (a_switch44 >= 0.5) {
            a_switch44 = 0;
            a_num44++;
        }
        if (a_num44 == 8)a_num44--;
        break;
    case 45:
        drawImg(*a_x, *a_y, &a_pictures[7]);
        break;
    case 46:
        drawImg(*a_x, *a_y, &a_pictures[0]);
        break;
    case -4:
        if (a_num_4 < 20) {
            drawImg(*a_x, *a_y, &a_pictures[a_num_4]);
        }
        else {
            drawImg(*a_x + 20, *a_y + 35, &a_pictures[a_num_4]);
        }
        a_switch_4 += dt * *a_speed / 300;
        if (a_switch_4 >= (a_num_4 < 20?0.06:0.04)) {
            a_switch_4 = 0;
            a_num_4++;
        }
        if (a_num_4 == 33)a_num_4--;
        break;
    }

    temp_op = e_num;
}

void AnimationEnemy::reset(int e_num)
{
    if (temp_op != e_num) {
        switch (e_num) {
        case -1:
            a_num_1 = 6;
            a_switch_1 = 0;
            break;
        case 23:
            a_num23 = 12;
            a_switch23 = 0;
            break;
        case 24:
            a_num24 = 16;
            a_switch24 = 0;
            break;
        case -2:
            a_num_2 = 23;
            a_switch_2 = 0;
            break;
        case 32:
            a_num32 = 12;
            a_switch32 = 0;
            break;
        case -3:
            a_num_3 = 16;
            a_switch_3 = 0;
            break;
        case 42:
            a_num42 = 0;
            a_switch44 = 0;
        case 44:
            a_num44 = 4;
            a_switch44 = 0;
        case -4:
            a_num_4 = 8;
            a_switch_4 = 0;
        }
    }
}

void AnimationEnemy::reset()
{
    a_num_1 = 6;
    a_switch_1 = 0;

    a_num23 = 12;
    a_switch23 = 0;

    a_num24 = 16;
    a_switch24 = 0;

    a_num_2 = 23;
    a_switch_2 = 0;

    a_num32 = 12;
    a_switch32 = 0;

    a_num_3 = 16;
    a_switch_3 = 0;

    a_num42 = 0;
    a_switch44 = 0;

    a_num44 = 4;
    a_switch44 = 0;

    a_num_4 = 8;
    a_switch_4 = 0;
}