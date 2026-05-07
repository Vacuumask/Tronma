#include "audio.h"
#include <cstring>

HSTREAM MusicPlayer::stream1 = 0;
HSTREAM MusicPlayer::stream2 = 0;
bool MusicPlayer::initialized = false;
int MusicPlayer::freq = 44100;

MusicPlayer::State MusicPlayer::currentState = STATE_IDLE;
int MusicPlayer::targetLoopStream = 2;
HSTREAM MusicPlayer::introStream = 0;

bool MusicPlayer::isPlayingIntro = true;

bool MusicPlayer::init() {
    if (initialized) return true;
    BASS_Init(-1, freq, 0, 0, NULL);
    initialized = true;
    return true;
}

FxPlayer::FxPlayer() : sample(0), maxInstances(4) {}

FxPlayer::~FxPlayer()
{
    free();
}

void FxPlayer::load(const char* filename, int maxConcurrent)
{
    if (sample) {
        BASS_SampleFree(sample);
        sample = 0;
    }

    maxInstances = maxConcurrent;
    sample = BASS_SampleLoad(FALSE, filename, 0, 0, maxInstances, BASS_SAMPLE_OVER_POS);
}

void FxPlayer::play()
{
    if (!sample) return;
    HCHANNEL channel = BASS_SampleGetChannel(sample, FALSE);
    if (channel) {
        BASS_ChannelPlay(channel, FALSE);
    }
}

void FxPlayer::stopAll() {
    if (sample) {
        BASS_SampleStop(sample);
    }
}

void FxPlayer::free()
{
    if (sample) {
        BASS_SampleFree(sample);
        sample = 0;
    }
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

    if (introStream) BASS_StreamFree(introStream);
    if (initialized) BASS_Free();
    initialized = false;
}

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

void MusicPlayer::stop1() {
    if (stream1) {
        BASS_ChannelStop(stream1);
    }
}
void MusicPlayer::stop2() {
    if (stream2) {
        BASS_ChannelStop(stream2);
    }
}
void MusicPlayer::stopIn()
{
    if (introStream) {
        BASS_ChannelStop(introStream);
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

void MusicPlayer::playIntro(const char* file, int targetStream) {
    if (!initialized) return;

    stop1();
    stop2();
    if (introStream) {
        BASS_ChannelStop(introStream);
        BASS_StreamFree(introStream);
        introStream = 0;
    }

    introStream = BASS_StreamCreateFile(FALSE, file, 0, 0, 0);
    if (!introStream) return;

    BASS_ChannelSetSync(introStream, BASS_SYNC_END, 0, OnIntroEnd, (void*)(intptr_t)targetStream);
    BASS_ChannelPlay(introStream, FALSE);

    currentState = STATE_PLAYING_INTRO;
    targetLoopStream = targetStream;
}

void CALLBACK MusicPlayer::OnIntroEnd(HSYNC handle, DWORD channel, DWORD data, void* user) {
    int target = (int)(intptr_t)user;

    if (target == 1 && stream1) {
        BASS_ChannelPlay(stream1, FALSE);
        currentState = STATE_PLAYING_LOOP;
    }
    else if (target == 2 && stream2) {
        BASS_ChannelPlay(stream2, FALSE);
        currentState = STATE_PLAYING_LOOP;
    }
    else {
        currentState = STATE_IDLE;
    }

    if (introStream) {
        BASS_StreamFree(introStream);
        introStream = 0;
    }
}

void MusicPlayer::update() {
    if (!initialized) return;

    if (currentState == STATE_PLAYING_LOOP) {
        if (targetLoopStream == 1 && stream1 && BASS_ChannelIsActive(stream1) != BASS_ACTIVE_PLAYING) {
            BASS_ChannelPlay(stream1, FALSE);
        }
        if (targetLoopStream == 2 && stream2 && BASS_ChannelIsActive(stream2) != BASS_ACTIVE_PLAYING) {
            BASS_ChannelPlay(stream2, FALSE);
        }
    }
}

void MusicPlayer::slow()
{
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
