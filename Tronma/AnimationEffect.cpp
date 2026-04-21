#include"AnimationEffect.h"


AnimationEffect::AnimationEffect(float* x, float* y, std::vector<IMAGE>& pictures)
{
    a_x = x;
    a_y = y;
    a_pictures = pictures;
}

AnimationEffect::~AnimationEffect()
{
    if (animation != NULL) {
        delete animation;
        animation = NULL;
    }
}

void AnimationEffect::run(int e_num) 
{
    FPS();

    switch (e_num) {
    case 411:
        drawImg(*a_x + 80, *a_y + 10, &a_pictures[a_num41]);
        a_switch41 += dt;
        if (a_switch41 >= 0.02) {
            a_switch41 = 0;
            a_num41++;
        }
        if (a_num41 == 13)a_num41--;
        break;
    case 42:
        drawImg(*a_x, *a_y, &a_pictures[13]);
        break;
    case 412:
        drawImg(*a_x + 80, *a_y + 10, &a_pictures[a_num41]);
        a_switch41 += dt;
        if (a_switch41 >= 0.02) {
            a_switch41 = 0;
            a_num41++;
        }
        if (a_num41 == 13)a_num41--;
    case 43:
        drawImg(*a_x+30, *a_y+70, &a_pictures[a_num43]);
        a_switch43 += dt;
        if (a_switch43 >= 0.02) {
            a_switch43 = 0;
            a_num43++;
        }
        if (a_num43 == 37)a_num43 = 14;
        break;
    }
}

void AnimationEffect:: reset() 
{
    a_num41 = 0;
    a_switch41 = 0;
    a_num43 = 14;
    a_switch43 = 0;
}