#include "audio.h"
#include <cstring>

// 静态成员定义
HSTREAM MusicPlayer::stream1 = 0;
HSTREAM MusicPlayer::stream2 = 0;
bool MusicPlayer::initialized = false;
int MusicPlayer::freq = 44100;

MusicPlayer::State MusicPlayer::currentState = STATE_IDLE;
int MusicPlayer::targetLoopStream = 2;
HSTREAM MusicPlayer::introStream = 0;

bool MusicPlayer::isPlayingIntro = true;

// 原有初始化
bool MusicPlayer::init() {
    if (initialized) return true;
    BASS_Init(-1, freq, 0, 0, NULL);
    initialized = true;
    return true;
}

void MusicPlayer::free() {
    if (stream1) {
        BASS_ChannelStop(stream1);
        BASS_StreamFree(stream1);
        stream1 = 0;
    }
    if (stream2) {
        BASS_ChannelStop(stream2);
        BASS_StreamFree(stream2);
        stream2 = 0;
    }
   /* stop1();
    stop2();*/
    if (introStream) BASS_StreamFree(introStream);
    if (initialized) BASS_Free();
    initialized = false;
}

// 原有 play1 / play2 直接循环播放
void MusicPlayer::play1(const char* file) {
    if (!initialized) return;
    if (stream1) { BASS_StreamFree(stream1); stream1 = 0; }
    stream1 = BASS_StreamCreateFile(FALSE, file, 0, 0, BASS_SAMPLE_LOOP);
    if (stream1) BASS_ChannelPlay(stream1, FALSE);
}

void MusicPlayer::play2(const char* file) {
    if (!initialized) return;
    if (stream2) { BASS_StreamFree(stream2); stream2 = 0; }
    stream2 = BASS_StreamCreateFile(FALSE, file, 0, 0, BASS_SAMPLE_LOOP);
    if (stream2) BASS_ChannelPlay(stream2, FALSE);
}

// 停止、音量、是否播放等函数略（保持原有实现）...

void MusicPlayer::stop1() {
    if (stream1) {
        BASS_ChannelStop(stream1);
        /*BASS_StreamFree(stream1);
        stream1 = 0;*/
    }
}
void MusicPlayer::stop2() {
    if (stream2) {
        BASS_ChannelStop(stream2);
        /*BASS_StreamFree(stream2);
        stream2 = 0;*/
    }
}
void MusicPlayer::stopIn()
{
    if (introStream) {
        BASS_ChannelStop(introStream);
        /*BASS_StreamFree(stream2);
        stream2 = 0;*/
    }
}

void MusicPlayer::setVolume1(float vol) {
    if (stream1) BASS_ChannelSetAttribute(stream1, BASS_ATTRIB_VOL, vol);
}
void MusicPlayer::setVolume2(float vol) {
    if (stream2) BASS_ChannelSetAttribute(stream2, BASS_ATTRIB_VOL, vol);
}
bool MusicPlayer::isPlaying1() {
    return stream1 && BASS_ChannelIsActive(stream1) == BASS_ACTIVE_PLAYING;
}
bool MusicPlayer::isPlaying2() {
    return stream2 && BASS_ChannelIsActive(stream2) == BASS_ACTIVE_PLAYING;
}

// ---- 新功能实现 ----
void MusicPlayer::playIntro(const char* file, int targetStream) {
    if (!initialized) return;

    // 停止当前所有音乐（包括 intro 和两个循环流）
    stop1();
    stop2();
    if (introStream) {
        BASS_ChannelStop(introStream);
        BASS_StreamFree(introStream);
        introStream = 0;
    }

    // 加载一次性 intro 流（不循环）
    introStream = BASS_StreamCreateFile(FALSE, file, 0, 0, 0);
    if (!introStream) return;

    // 设置结束回调
    BASS_ChannelSetSync(introStream, BASS_SYNC_END, 0, OnIntroEnd, (void*)(intptr_t)targetStream);
    BASS_ChannelPlay(introStream, FALSE);

    // 更新状态
    currentState = STATE_PLAYING_INTRO;
    targetLoopStream = targetStream;
}

void CALLBACK MusicPlayer::OnIntroEnd(HSYNC handle, DWORD channel, DWORD data, void* user) {
    int target = (int)(intptr_t)user;

    // 播放目标循环流（假设已经通过 play1/play2 预加载，否则需要加载）
    if (target == 1 && stream1) {
        BASS_ChannelPlay(stream1, FALSE);
        currentState = STATE_PLAYING_LOOP;
    }
    else if (target == 2 && stream2) {
        BASS_ChannelPlay(stream2, FALSE);
        currentState = STATE_PLAYING_LOOP;
    }
    else {
        // 如果目标流尚未创建，可在此调用 play1 或 play2 加载默认文件
        // （根据需求决定，建议提前预加载）
        currentState = STATE_IDLE;
    }

    // 释放 intro 流
    if (introStream) {
        BASS_StreamFree(introStream);
        introStream = 0;
    }
}

void MusicPlayer::update() {
    if (!initialized) return;

    // 根据状态处理自动恢复（可选）
    // 例如：在循环播放状态下，如果循环流意外停止，则重新播放（保持循环）
    if (currentState == STATE_PLAYING_LOOP) {
        if (targetLoopStream == 1 && stream1 && BASS_ChannelIsActive(stream1) != BASS_ACTIVE_PLAYING) {
            BASS_ChannelPlay(stream1, FALSE);
        }
        if (targetLoopStream == 2 && stream2 && BASS_ChannelIsActive(stream2) != BASS_ACTIVE_PLAYING) {
            BASS_ChannelPlay(stream2, FALSE);
        }
    }
    // 其他状态无需额外处理
}



//bool MusicPlayer::init() {
//    if (initialized) return true;
//    BASS_Init(-1, freq, 0, 0, NULL);
//    initialized = true;
//    return true;
//}
//
//void MusicPlayer::play1(const char* file) {
//    if (!initialized) return;
//    if (stream1) {
//        BASS_StreamFree(stream1);
//        stream1 = 0;
//    }
//    stream1 = BASS_StreamCreateFile(FALSE, file, 0, 0, BASS_SAMPLE_LOOP);
//    BASS_ChannelPlay(stream1, FALSE);
//}
//
//void MusicPlayer::play2(const char* file)
//{
//    if (!initialized) return;
//    if (stream2) {
//        BASS_StreamFree(stream2);
//        stream2 = 0;
//    }
//    stream2 = BASS_StreamCreateFile(FALSE, file, 0, 0, BASS_SAMPLE_LOOP);
//    BASS_ChannelPlay(stream2, FALSE);
//}

//void MusicPlayer::stop1() {
//    if (stream1) {
//        BASS_ChannelStop(stream1);
//        BASS_StreamFree(stream1);
//        stream1 = 0;
//    }
//}
//
//void MusicPlayer::stop2()
//{
//    if (stream2) {
//        BASS_ChannelStop(stream2);
//        BASS_StreamFree(stream2);
//        stream2 = 0;
//    }
//}

//void MusicPlayer::stopIn()
//{
//    if (introStream) {
//        BASS_ChannelStop(introStream);
//        BASS_StreamFree(introStream);
//        introStream = 0;
//    }
//}
//
//void MusicPlayer::setVolume1(float vol) {
//    if (stream1) {
//        BASS_ChannelSetAttribute(stream1, BASS_ATTRIB_VOL, vol);
//    }
//}
//
//void MusicPlayer::setVolume2(float vol)
//{
//    if (stream2) {
//        BASS_ChannelSetAttribute(stream2, BASS_ATTRIB_VOL, vol);
//    }
//}
//
//void MusicPlayer::setVolumeIn(float vol)
//{
//    if (introStream) {
//        BASS_ChannelSetAttribute(introStream, BASS_ATTRIB_VOL, vol);
//    }
//}
//
//bool MusicPlayer::isPlaying1() {
//    if (!stream1) return false;
//    return BASS_ChannelIsActive(stream1) == BASS_ACTIVE_PLAYING;
//}
//
//bool MusicPlayer::isPlaying2()
//{
//    if (!stream2) return false;
//    return BASS_ChannelIsActive(stream2) == BASS_ACTIVE_PLAYING;
//}
//
//bool MusicPlayer::isPlayingIn()
//{
//    if (!introStream) return false;
//    return BASS_ChannelIsActive(introStream) == BASS_ACTIVE_PLAYING;
//}

//void MusicPlayer::free() {
//    stop1();
//    stop2();
//    if (initialized) {
//        BASS_Free();
//        initialized = false;
//    }
//}

void MusicPlayer::slow()
{
    //if (isSlowing == false)isSlowing = true;
    freq = (freq >= 33075 ? freq - 45 : 33075);
    BASS_ChannelSetAttribute(stream1, BASS_ATTRIB_FREQ, freq);
    BASS_ChannelSetAttribute(stream1, BASS_ATTRIB_PAN, 0);
    BASS_ChannelSetAttribute(stream2, BASS_ATTRIB_FREQ, freq);
    BASS_ChannelSetAttribute(stream2, BASS_ATTRIB_PAN, 0);
    BASS_ChannelSetAttribute(introStream, BASS_ATTRIB_FREQ, freq);
    BASS_ChannelSetAttribute(introStream, BASS_ATTRIB_PAN, 0);
}

void MusicPlayer::reset()
{
    freq = 44100;
    BASS_ChannelSetAttribute(stream1, BASS_ATTRIB_FREQ, freq);
    BASS_ChannelSetAttribute(stream1, BASS_ATTRIB_PAN, 0);
    BASS_ChannelSetAttribute(stream2, BASS_ATTRIB_FREQ, freq);
    BASS_ChannelSetAttribute(stream2, BASS_ATTRIB_PAN, 0);
    BASS_ChannelSetAttribute(introStream, BASS_ATTRIB_FREQ, freq);
    BASS_ChannelSetAttribute(introStream, BASS_ATTRIB_PAN, 0);

}
