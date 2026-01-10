#pragma once 
#include <exception>
#include <iostream>

bool syntax_checker(const std::string& expr);
int RPN_calculator(const std::string& expr);

class DivisionByZero : public std::exception
{
    public:
        const char * what() const throw();
};

class InvalidRPNsyntax : public std::exception
{
    public:
        const char *what() const throw();
};

class InvalidToken : public std::exception
{
    public:
        const char *what() const throw();
}; 
