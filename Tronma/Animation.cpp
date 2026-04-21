#include"Animation.h"

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

Animation::~Animation()
{
    if (animation != NULL) {
        delete animation;
        animation = NULL;
    }
}

