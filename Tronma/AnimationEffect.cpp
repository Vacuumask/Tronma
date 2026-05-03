#include"AnimationEffect.h"

AnimationEffect::AnimationEffect(float* x, float* y, std::vector<IMAGE>& pictures)
{
    a_x = x;
    a_y = y;
    a_pictures = pictures;
}

AnimationEffect::AnimationEffect(float* x, float* y, float* p_x, float* p_y, std::vector<IMAGE>& pictures)
{
    a_x = x;
    a_y = y;
    b_x = p_x;
    b_y = p_y;
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
    case 8:
        //IMAGE temp = a_pictures[a_num5];
        //temp.Resize(size5, size5);
        if (a_num5 < 12) {
            drawImg(*(a_x + a_num5) + *b_x + 10, *(a_y + a_num5) + *b_y, &a_pictures[a_num5]);
        }
        a_switch5 += dt;
        if (a_switch5 >= 0.012) {
            a_switch5 = 0;
            a_num5++;
            //size5 += 64;
        }
        if (a_num5 == 150)a_num5 = 0;
        break;
    case 101:
        drawImg(*a_x + 60, *a_y, &a_pictures[a_num10]);
        a_switch10 += dt;
        if (a_switch10 >= 0.04) {
            a_switch10 = 0;
            a_num10++;
        }
        if (a_num10 == 11)a_num10--;
        break;
    case 102:
        drawImg(*a_x, *a_y, &a_pictures[11]);
        break;
    }
}

void AnimationEffect:: reset() 
{
    a_num41 = 0;
    a_switch41 = 0;
    a_num43 = 14;
    a_switch43 = 0;

    a_num5 = 0;
    a_switch5 = 0;
    
    a_num10 = 0;
    a_switch10 = 0;
}