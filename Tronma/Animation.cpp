#include"Animation.h"

float Animation::p_speed = 1.0f;
float Animation::base_speed = 1.0f;
float Animation::pro_speed = 0.0f;

Animation::Animation()
{
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&last);
}

void Animation::FPS()
{
    QueryPerformanceCounter(&current);
    dt = (float)(current.QuadPart - last.QuadPart) / freq.QuadPart;
    last = current;
    if (dt > 0.033f) dt = 0.033f;  // 限制最大间隔
}



