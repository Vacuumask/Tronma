#include"AnimationPlayer.h"

AnimationPlayer::AnimationPlayer(float* x, float* y, float* speed, std::vector<IMAGE>& pictures)
{
    a_x = x;
    a_y = y;
    a_speed = speed;
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
        a_switch0 += dt * *a_speed / 300;
        if (a_switch0 >= 0.06) {
            a_switch0 = 0;
            a_num0++;
        }
        if (a_num0 == 7)a_num0 = 0;
        break;
    case 11:
    case 14:
        drawImg(*a_x, *a_y, &a_pictures[a_num11]);
        a_switch11 += dt * *a_speed / 300;
        if (a_switch11 >= 0.06) {
            a_switch11 = 0;
            a_num11++;
        }
        if (a_num11 == 11)a_num11 = 7;
        break;
    case 12:
        drawImg(*a_x, *a_y, &a_pictures[a_num12]);
        a_switch12 += dt * *a_speed / 300;
        if (a_switch12 >= 0.06) {
            a_switch12 = 0;
            a_num12++;
        }
        if (a_num12 == 15)a_num12 = 11;
        break;
    case 13:
        drawImg(*a_x, *a_y, &a_pictures[a_num13]);
        a_switch13 += dt * *a_speed / 300;
        if (a_switch13 >= 0.06) {
            a_switch13 = 0;
            a_num13++;
        }
        if (a_num13 == 19)a_num13 = 15;
        break;
    case 2:
        drawImg(*a_x, *a_y, &a_pictures[a_num12]);
        a_switch12 += dt * *a_speed / 300;
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
        a_switch41 += dt * *a_speed / 300;
        if (a_switch41 >= 0.08) {
            a_switch41 = 0;
            a_num41++;
        }
        if (a_num41 == 22)a_num41--;
        break;
    case 42:
    case 10:
        drawImg(*a_x, *a_y, &a_pictures[a_num42]);
        a_switch42 += dt * *a_speed / 300;
        if (a_switch42 >= 0.08) {
            a_switch42 = 0;
            a_num42++;
        }
        if (a_num42 == 25)a_num42--;
        break;
    case 43:
        drawImg(*a_x, *a_y, &a_pictures[a_num43]);
        a_switch43 += dt * *a_speed / 300;
        if (a_switch43 >= 0.08) {
            a_switch43 = 0;
            a_num43++;
        }
        if (a_num43 == 28)a_num43--;
        break;

    case 5:
        drawImg(*a_x, *a_y, &a_pictures[a_num5]);
        a_switch5 += dt * *a_speed / 300;
        if (a_switch5 >= 0.10) {
            a_switch5 = 0;
            a_num5++;
        }
        if (a_num5 == 36)a_num5 = 28;
        break;

    case 61:
    case 62:
        drawImg(*a_x, *a_y, &a_pictures[a_num6]);
        a_switch6 += dt * *a_speed / 300;
        if (a_switch6 >= 0.05) {
            a_switch6 = 0;
            a_num6++;
        }
        if (a_num6 == 60)a_num6--;
        break;
    case 63:
        drawImg(*a_x, *a_y, &a_pictures[a_num63]);
        a_switch63 += dt * *a_speed / 300;
        if (a_switch63 >= 0.1) {
            a_switch63 = 0;
            a_num63++;
        }
        if (a_num63 == 52)a_num63--;
        break;
    case 64:
        drawImg(*a_x, *a_y, &a_pictures[a_num64]);
        a_switch64 += dt * *a_speed / 300;
        if (a_switch64 >= 0.04) {
            a_switch64 = 0;
            a_num64++;
        }
        if (a_num64 == 57)a_num64 = 55;
        break;

    case 92:
        drawImg(*a_x, *a_y, &a_pictures[a_num9]);
        a_switch9 += dt * *a_speed / 300;
        if (a_switch9 >= 0.06) {
            a_switch9 = 0;
            a_num9++;
        }
        if (a_num9 == 67)a_num9 = 60;
        break;
    case 93:
        drawImg(*a_x, *a_y, &a_pictures[61]);
        a_num9 = 60;
        break;

    case 99:
        drawImg(*a_x, *a_y, &a_pictures[a_num99]);
        a_switch99 += dt * *a_speed / 300;
        if (a_switch99 >= 0.3) {
            a_switch99 = 0;
            a_num99++;
        }
        if (a_num99 == 71)a_num99--;
        break;
    }

    reset(op_num);

    temp_op = op_num;
}

void AnimationPlayer::reset(int& op_num)
{
    if (temp_op != op_num) {
        switch (temp_op) {
        case 41:
        case 42:
        case 43:
        case 10:
            a_num41 = 19;
            a_switch41 = 0;
            a_num42 = 22;
            a_switch42 = 0;
            a_num43 = 25;
            a_switch43 = 0;
            break;
        case 61:
        case 62:
            a_num6 = 42;
            a_switch6 = 0;
            break;
        case 63:
            a_num63 = 36;
            a_switch63 = 0;
            break;
        case 64:
            a_num63 = 52;
            a_switch63 = 0;
            break;
        case 99:
            a_num99 = 67;
            a_switch99 = 0;
            break;
        }
    }
}

void AnimationPlayer::reset() {
    a_num41 = 19;
    a_switch41 = 0;
    a_num42 = 22;
    a_switch42 = 0;
    a_num43 = 25;
    a_switch43 = 0;

    a_num6 = 42;
    a_switch6 = 0;
    a_num63 = 36;
    a_switch63 = 0;
    a_num64 = 52;
    a_switch63 = 0;

    a_num99 = 67;
    a_switch99 = 0;
}
