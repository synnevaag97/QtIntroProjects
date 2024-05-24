#ifndef MORSECODESOUND_H
#define MORSECODESOUND_H

#include <QString>
#include <QThread>
#include <QVector>
#include <QtLogging>

#include <SDL2/SDL.h>

class MorseCodeSound
{
public:
    MorseCodeSound();
    ~MorseCodeSound();
    void playMorseCode(const QString morseCode);

private:
    // Frequency of a single unit in Morse code (in milliseconds)
    const int dotDurationMs = 100;
    const int dashDurationMs = 300;

    // Frequencie and amplitude tunes for dot and dash sounds.
    const double frequency = 500;
    const double amplitude = 0.5;

    void generateTone(QVector<short> *buffer, int length, int frequency, int sampleRate);
    void playTone(int frequency, int durationMs);
};

#endif // MORSECODESOUND_H
