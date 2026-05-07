#pragma once
#include "bass.h"

class MusicPlayer {
public:
    static bool init();
    static void free();

    static void play1(const char* file);
    static void play2(const char* file);
    static void stop1();
    static void stop2();
    static void stopIn();
    static void setVolume1(float vol);
    static void setVolume2(float vol);
    static bool isPlaying1();
    static bool isPlaying2();

    static void playIntro(const char* file, int targetStream = 2);

    static void update();

    static void slow();
    static void reset();


    static bool isPlayingIntro;
private:
    enum State {
        STATE_IDLE,
        STATE_PLAYING_INTRO,
        STATE_PLAYING_LOOP
    };
    static State currentState;
    static int targetLoopStream;

    static HSTREAM introStream;

    static void CALLBACK OnIntroEnd(HSYNC handle, DWORD channel, DWORD data, void* user);

    static HSTREAM stream1, stream2;
    static bool initialized;
    static int freq;
};

class FxPlayer {
public:
    FxPlayer();
    ~FxPlayer();
    void load(const char* filename, int maxConcurrent = 4);
    void play();
    void stopAll();
    void free();

private:
    HSAMPLE sample;
    int maxInstances;
};