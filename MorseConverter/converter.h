#ifndef CONVERTER_H
#define CONVERTER_H

#include <QMap>
#include <QRegularExpression>
#include <QString>

#include "morsecodesound.h"

class Converter
{
public:
    Converter();
    QString convert(const QString &text);
    QString morseToAscii(const QString &text);
    QString asiicToMorse(const QString &text);
    bool isMorseCode(const QString &text);

private:
    QMap<QChar, QString> asciiToMorseLUT;
    QMap<QString, QChar> morseToAsciiLUT;
    MorseCodeSound *morseCodeSound;
};

#endif // CONVERTER_H

/*
 * https://en.wikipedia.org/wiki/Morse_code
 * */
