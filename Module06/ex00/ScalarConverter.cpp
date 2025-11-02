#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits.h>

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter&cp){ *this = cp;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&cp)
{
    (void)cp;
    return *this;
}
ScalarConverter::~ScalarConverter(){}

static WhatType defineType(const std::string& cnv)
{
    getType type;

    if(cnv.empty())
        return type;
    // checking for single char
    if (cnv.length() == 1 && !isdigit(cnv[0]))
    {
        type.isChar =true;
        return type;
    }
    //  checking for float +inff o -inff
    if (cnv == "nanf" || cnv == "+inff" || cnv == "-inff") {
        type.isFloat = true;
        return type;
    }

    // check for  double values
    if (cnv == "nan" || cnv == "+inf" || cnv == "-inf") {
        type.isDouble = true;
        return type;
    }
    // checking if we have a double or float
    bool hasF = (cnv[cnv.length() - 1] == 'f');
    bool hasDot = (cnv.find('.') != std::string::npos);

    char *endptr = NULL;
    //  float convert 
    if (hasF && hasDot)
    {
        //  removing the f from float
        std::string num = cnv.substr(0, cnv.length() - 1);
        // not converting the number from float to double
        strtod(num.c_str(), &endptr);
        if(*endptr == '\0')
        { 
            type.isFloat = true;
            return type;
        }
    }
    // double 
    if(hasDot && !hasF)
    {
        strtod(cnv.c_str(), &endptr);
        if (*endptr == '\0')
        {
            type.isDouble = true;
            return type;
        }
    }
    if (!hasDot && !hasF) {
        long val = strtol(cnv.c_str(), &endptr , 10);
        if (*endptr == '\0' && val >= INT_MIN && val <= INT_MAX) {
            type.isInt = true;
            return type;
        }
    }
    return type;
}

static void convert(const std::string &cnv)
{
    getType type = defineType(cnv);

    if (!type.isInt && !type.isFloat && !type.isDouble && !type.isChar) {
        std::cout << "Error: Invalid input" << std::endl;
        return;
    }
    // checking for input special value
    bool isSpecial = (cnv == "nan" || cnv == "nanf" || 
                      cnv == "+inf" || cnv == "-inf" || 
                      cnv == "+inff" || cnv == "-inff");
    // actual values
    int intVal = 0;
    float floatVal = 0.0f;
    double doubleVal = 0.0;
    char charVal = 0;
    
    if (type.isChar) {
        charVal = cnv[0];
        intVal = static_cast<int>(charVal);
        floatVal = static_cast<float>(charVal);
        doubleVal = static_cast<double>(charVal);
    }
    else if (type.isInt) {
        intVal = atoi(cnv.c_str());
        charVal = static_cast<char>(intVal);
        floatVal = static_cast<float>(intVal);
        doubleVal = static_cast<double>(intVal);
    }
    else if (type.isFloat) {
        floatVal = static_cast<float>(strtod(cnv.c_str(), NULL));
        intVal = static_cast<int>(floatVal);
        charVal = static_cast<char>(floatVal);
        doubleVal = static_cast<double>(floatVal);
    }
    else if (type.isDouble) {
        doubleVal = strtod(cnv.c_str(), NULL);
        intVal = static_cast<int>(doubleVal);
        charVal = static_cast<char>(doubleVal);
        floatVal = static_cast<float>(doubleVal);
    }
    
    std::cout << "char: ";
    if (isSpecial || intVal < 32 || intVal > 126) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << "'" << charVal << "'" << std::endl;
    }
    
    std::cout << "int: ";
    if (isSpecial) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << intVal << std::endl;
    }
    
    std::cout << "float: " << floatVal << "f" << std::endl;
    
    std::cout << "double: " << doubleVal << std::endl;
}
