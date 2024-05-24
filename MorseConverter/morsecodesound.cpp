#include "morsecodesound.h"

MorseCodeSound::MorseCodeSound()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        qInfo("Failed to initialize SDL: %s", SDL_GetError());
    }
}

MorseCodeSound::~MorseCodeSound()
{
    SDL_Quit();
}

void MorseCodeSound::generateTone(QVector<short> *buffer, int length, int frequency, int sampleRate)
{
    for (int i = 0; i < length; i++) {
        double time = static_cast<double>(i) / sampleRate;
        double value = (amplitude * SDL_sin(2.0 * M_PI * frequency * time));
        (*buffer)[i] = static_cast<short>(value * 32767);
        //qInfo("%d", (*buffer)[i]);
    }
}

void MorseCodeSound::playTone(int frequency, int durationMs)
{
    const int sampleRate = 44100;
    const int numSamples = (int) (sampleRate * durationMs / 1000.0);
    //    qInfo("%d", numSamples);

    QVector<short> *buffer = new QVector<short>(numSamples, 0.0);

    generateTone(buffer, numSamples, frequency, sampleRate);

    SDL_AudioSpec spec;
    SDL_zero(spec);
    spec.freq = sampleRate;
    spec.format = AUDIO_S16SYS;
    spec.channels = 1;
    spec.samples = 4096;
    spec.callback = nullptr;

    /*
    SDL_AudioSpec wavSpec;
    Uint8 *wavStart;
    Uint32 wavLength;
    QString filePath = "/home/tsg/Downloads/BabyElephantWalk60.wav";
    if (SDL_LoadWAV(filePath.toUtf8().constData(), &wavSpec, &wavStart, &wavLength) == NULL) {
        qInfo("Failed to load WAV file: %s", SDL_GetError());
        return;
    }
    */

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, 0);
    qInfo("%d", deviceId);
    if (deviceId == 0) {
        qInfo("Failed to open audio device: %s", SDL_GetError());
        delete buffer;
        return;
    }

    int bufferSize = numSamples * sizeof(short);
    SDL_QueueAudio(deviceId, buffer->data(), bufferSize);
    SDL_PauseAudioDevice(deviceId, 0);

    // Wait until audio playback is finished
    //while (SDL_GetAudioDeviceStatus(deviceId) == SDL_AUDIO_PLAYING) {
    //SDL_Delay(100); // Adjust delay as needed
    //}

    //QThread::msleep(durationMs);
    //std::this_thread::sleep_for(std::chrono::milliseconds(durationMs));
    SDL_Delay(300);

    SDL_CloseAudioDevice(deviceId);
    //SDL_FreeWAV(wavStart);

    delete buffer;
}

void MorseCodeSound::playMorseCode(const QString morseCode)
{
    for (QChar c : morseCode) {
        if (c == '.') {
            playTone(frequency, dotDurationMs);
        } else if (c == '-') {
            playTone(frequency, dashDurationMs);
        }
    }
}
