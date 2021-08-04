#pragma once

#include <iostream>
#include <cmath>
#include <string>

class Exercise2
{
public:
    Exercise2();
    ~Exercise2()=default;
    bool CompareFloats(float num1, float num2);
    void PrintTriangle();
    void PrintRing();
private:
    short varShort = 97;
    short varShort1 = -115;
    int varInt = 52130;
    long varLong = 4825932;
    long varLong2 = -10000;
    float varFloat = 12.345;
    float varFloat2 =3456.091;
    double varDouble = 34.567839023;
    double varDouble2 = 8923.1234857;

    int varHex = 0x100;
    char varChar = 72;
    bool isFemale = false;
    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string str3 = str1 + " " + str2;
    std::string str4 = str3;
    std::string str5 = "The \"use\" of quotations causes difficulties";
    std::string str6 = "The \"use\" of quotations causes difficulties";

};
