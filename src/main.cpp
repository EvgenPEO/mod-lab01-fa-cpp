// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    const char* str1 = "Hello world123 42 test";
    const char* str2 = "Hello World anotherWord Test notValid";
    const char* str3 = "Hello world test string";

    std::cout << "faStr1: " << faStr1(str1) << std::endl;
    std::cout << "faStr2: " << faStr2(str2) << std::endl;
    std::cout << "faStr3: " << faStr3(str3) << std::endl;

    return 0;
}
