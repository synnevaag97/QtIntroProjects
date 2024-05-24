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
    }
}

void MorseCodeSound::playTone(int frequency, int durationMs)
{
    const int sampleRate = 44100;
    const int numSamples = (int) (sampleRate * durationMs / 1000.0);

    QVector<short> *buffer = new QVector<short>(numSamples, 0.0);

    generateTone(buffer, numSamples, frequency, sampleRate);

    SDL_AudioSpec spec;
    SDL_zero(spec);
    spec.freq = sampleRate;
    spec.format = AUDIO_S16SYS;
    spec.channels = 1;
    spec.samples = 4096;
    spec.callback = nullptr;

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, 0);
    if (deviceId == 0) {
        qInfo("Failed to open audio device: %s", SDL_GetError());
        delete buffer;
        return;
    }

    int bufferSize = numSamples * sizeof(short);
    SDL_QueueAudio(deviceId, buffer->data(), bufferSize);
    SDL_PauseAudioDevice(deviceId, 0);

    SDL_Delay(150);

    SDL_CloseAudioDevice(deviceId);

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
