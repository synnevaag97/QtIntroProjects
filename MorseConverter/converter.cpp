#include "converter.h"

Converter::Converter()
{
    asciiToMorseLUT = {{'A', ".-"},     {'B', "-..."},   {'C', "-.-."},   {'D', "-.."},
                       {'E', "."},      {'F', "..-."},   {'G', "--."},    {'H', "...."},
                       {'I', ".."},     {'J', ".---"},   {'K', "-.-"},    {'L', ".-.."},
                       {'M', "--"},     {'N', "-."},     {'O', "---"},    {'P', ".--."},
                       {'Q', "--.-"},   {'R', ".-."},    {'S', "..."},    {'T', "-"},
                       {'U', "..-"},    {'V', "...-"},   {'W', ".--"},    {'X', "-..-"},
                       {'Y', "-.--"},   {'Z', "--.."},   {'0', "-----"},  {'1', ".----"},
                       {'2', "..---"},  {'3', "...--"},  {'4', "....-"},  {'5', "....."},
                       {'6', "-...."},  {'7', "--..."},  {'8', "---.."},  {'9', "----."},
                       {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'=', "-...-"},
                       {' ', " "}};

    // build the reversed map
    for (auto i = asciiToMorseLUT.cbegin(), end = asciiToMorseLUT.cend(); i != end; ++i)
        morseToAsciiLUT[i.value()] = i.key();

    // Initiate morse code audio.
}
bool Converter::isMorseCode(const QString &text)
{
    static QRegularExpression morsePattern("^[\\.\\-\\s]+$");
    return text.contains(morsePattern);
}

QString Converter::convert(const QString &text)
{
    if (isMorseCode(text)) {
        return morseToAscii(text);
    } else {
        return asiicToMorse(text);
    }
    return "error";
}

QString Converter::morseToAscii(const QString &text)
{
    // Split text into spaces, and convert multiple dots and dashes to letter.
    // Currently spaces is not converted correctly.
    QString converted_text = "";
    for (int i = 0; i < text.length(); i++) {
        QString c = morseToAsciiLUT[text[i]];
        converted_text.push_back(c);
    }
    return converted_text;
}

QString Converter::asiicToMorse(const QString &text)
{
    // Here we just want to convert each letter to a morse so keep as is.
    QString converted_text = "";
    for (int i = 0; i < text.length(); i++) {
        converted_text.push_back(asciiToMorseLUT[text[i]]);
        converted_text.push_back(morseToAsciiLUT[" "]);
    }

    return converted_text;
}
