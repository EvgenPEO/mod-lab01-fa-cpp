// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool isWord = false;
    bool containsDigit = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            isWord = true;
            if (isdigit(str[i])) {
                containsDigit = true;
            }
        }
        else {
            if (isWord && !containsDigit) {
                count++;
            }
            isWord = false;
            containsDigit = false;
        }
    }

    if (isWord && !containsDigit) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool isWord = false;
    bool isValidWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            if (!isWord && isupper(str[i])) {
                isValidWord = true;
            }
            else if (!islower(str[i])) {
                isValidWord = false;
            }
            isWord = true;
        }
        else {
            if (isWord && isValidWord) {
                count++;
            }
            isWord = false;
            isValidWord = false;
        }
    }

    if (isWord && isValidWord) {
        count++;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    unsigned int currentWordLength = 0;
    bool isWord = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            isWord = true;
            currentWordLength++;
        }
        else {
            if (isWord) {
                wordCount++;
                totalLength += currentWordLength;
            }
            isWord = false;
            currentWordLength = 0;
        }
    }

    if (isWord) {
        wordCount++;
        totalLength += currentWordLength;
    }

    return wordCount == 0 ? 0 : (totalLength + wordCount / 2) / wordCount;
}
