#pragma once
#include "bass.h"

class MusicPlayer {
public:
    // 初始化与释放
    static bool init();
    static void free();

    // 原有接口：两个独立的循环流（直接播放循环）
    static void play1(const char* file);
    static void play2(const char* file);
    static void stop1();
    static void stop2();
    static void stopIn();
    static void setVolume1(float vol);
    static void setVolume2(float vol);
    static bool isPlaying1();
    static bool isPlaying2();

    // 新增接口：播放 intro，结束后自动切换到 targetStream (1 或 2)
    static void playIntro(const char* file, int targetStream = 2);

    // 新增：在主循环中每帧调用，维护状态（自动恢复、处理切换）
    static void update();

    static void slow();
    static void reset();


    static bool isPlayingIntro;
private:
    // 内部状态
    enum State {
        STATE_IDLE,
        STATE_PLAYING_INTRO,
        STATE_PLAYING_LOOP
    };
    static State currentState;
    static int targetLoopStream;            // 记录 intro 结束后要播放的目标流编号

    // 临时 intro 流
    static HSTREAM introStream;

    // 回调函数
    static void CALLBACK OnIntroEnd(HSYNC handle, DWORD channel, DWORD data, void* user);

    // 现有成员
    static HSTREAM stream1, stream2;
    static bool initialized;
    static int freq;
};