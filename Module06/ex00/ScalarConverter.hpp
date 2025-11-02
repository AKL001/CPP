#pragma  once 
#include <iostream>

typedef struct WhatType 
{
    bool isInt;
    bool isFloat;
    bool isDouble;
    bool isChar;

    WhatType() : isInt(false) , isFloat(false), isDouble(false),isChar(false){}
}   getType;

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&cp);
        ScalarConverter& operator=(const ScalarConverter&cp);
        ~ScalarConverter();
        static WhatType defineType(const std::string& cnv);
        static void convert(const std::string &cnv);
};

