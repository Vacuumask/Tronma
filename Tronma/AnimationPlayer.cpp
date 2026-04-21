#include"AnimationPlayer.h"

AnimationPlayer::AnimationPlayer(float* x, float* y, std::vector<IMAGE>& pictures)
{
    a_x = x;
    a_y = y;
    a_pictures = pictures;
}

AnimationPlayer::~AnimationPlayer()
{
    if (animation != NULL) {
        delete animation;
        animation = NULL;
    }
}

void AnimationPlayer::run(int& op_num) {
    FPS();
    switch (op_num) {
    case 0:
        drawImg(*a_x, *a_y, &a_pictures[a_num0]);
        a_switch0 += dt;
        if (a_switch0 >= 0.06) {
            a_switch0 = 0;
            a_num0++;
        }
        if (a_num0 == 7)a_num0 = 0;
        break;
    case 11:
        drawImg(*a_x, *a_y, &a_pictures[a_num11]);
        a_switch11 += dt;
        if (a_switch11 >= 0.06) {
            a_switch11 = 0;
            a_num11++;
        }
        if (a_num11 == 11)a_num11 = 7;
        break;
    case 12:
        drawImg(*a_x, *a_y, &a_pictures[a_num12]);
        a_switch12 += dt;
        if (a_switch12 >= 0.06) {
            a_switch12 = 0;
            a_num12++;
        }
        if (a_num12 == 15)a_num12 = 11;
        break;
    case 13:
        drawImg(*a_x, *a_y, &a_pictures[a_num13]);
        a_switch13 += dt;
        if (a_switch13 >= 0.06) {
            a_switch13 = 0;
            a_num13++;
        }
        if (a_num13 == 19)a_num13 = 15;
        break;
    case 2:
        drawImg(*a_x, *a_y, &a_pictures[a_num12]);
        a_switch12 += dt;
        if (a_switch12 >= 0.06) {
            a_switch12 = 0;
            a_num12++;
        }
        if (a_num12 == 15)a_num12 = 11;
        break;
    case 3:
        drawImg(*a_x, *a_y, &a_pictures[1]);
        a_num0 = 0;
        break;
    case 41:
        drawImg(*a_x, *a_y, &a_pictures[a_num41]);
        a_switch41 += dt;
        if (a_switch41 >= 0.08) {
            a_switch41 = 0;
            a_num41++;
        }
        if (a_num41 == 22)a_num41--;
        break;
    case 42:
        drawImg(*a_x, *a_y, &a_pictures[a_num42]);
        a_switch42 += dt;
        if (a_switch42 >= 0.08) {
            a_switch42 = 0;
            a_num42++;
        }
        if (a_num42 == 25)a_num42--;
        break;
    case 43:
        drawImg(*a_x, *a_y, &a_pictures[a_num43]);
        a_switch43 += dt;
        if (a_switch43 >= 0.08) {
            a_switch43 = 0;
            a_num43++;
        }
        if (a_num43 == 28)a_num43--;
        break;
    }

    resetChop(op_num);

    temp_op = op_num;
}

void AnimationPlayer::resetChop(int& op_num)
{
    if ((temp_op==41||temp_op==42||temp_op==43)&&temp_op != op_num) {
        a_num41 = 19;
        a_switch41 = 0;
        a_num42 = 22;
        a_switch42 = 0;
        a_num43 = 25;
        a_switch43 = 0;
    }
}
