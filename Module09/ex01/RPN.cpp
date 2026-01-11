/*
    why use RPN calculator -> simpler parsing no need for parentheses handling
    ex : 3 + (4 * 2) => 3 4 2 * + , faster using stack 
    -container used : stack , vector
    - edge cases , division 0
*/
#include "RPN.hpp"
#include <cerrno>
#include <cstdlib>
#include <sstream>
#include <stack>

static bool is_operator(const std::string &tok)
{
    return tok.size() == 1 &&
           (tok[0] == '+' || tok[0] == '-' ||
            tok[0] == '*' || tok[0] == '/');
}

static bool is_number(const std::string& number)
{
    char *end;
    errno  = 0;
    std::strtod(number.c_str(), &end);
    return *end == '\0' && errno == 0;
}

bool syntax_checker(const std::string& expr)
{
    std::istringstream iss(expr);
    std::string token;
    int depth = 0; // the depth should always be =1 to be true

    while(iss >> token)
    {   
        if (is_number(token))
            depth++;
        else if (is_operator(token))
        {
            if (depth < 2) // means the syntax error ,  this should be 2 for the 2 first numbers ex: ( 9 9 +) 
                throw InvalidRPNsyntax();
            depth--;
        }
        else 
            throw InvalidToken(); // we can also throw here an exception , like invalid character
    }
    return depth == 1; // if the depth is 1 true else false. 
}

/* RPN 
    add to the stack and then we incountring a operator we pop 2 numbers from the stack
    - making sure the size of the stack is more than 2 
    - using std::vector is better 
*/
int RPN_calculator(const std::string& expr)
{
    std::istringstream iss(expr);
    std::string token;
    std::stack<int> sstack; 

    while(iss >> token)
    {
        if (is_number(token))
        {
            char *end;
            long value = std::strtol(token.c_str(), &end, 10);
            // end point to the . if double or float accured
            if (*end != '\0')
                throw InvalidToken();
            // handle negative numbers 
            if (value < 0 || value >= 10)
                throw InvalidRPNsyntax();

            sstack.push(static_cast<int>(value));
        }
        else if (is_operator(token))
        {
            if (sstack.size() < 2)
                throw InvalidRPNsyntax();

            int right = sstack.top(); sstack.pop();
            int left = sstack.top(); sstack.pop();

            if (token[0] == '/' && right == 0)
                throw DivisionByZero();
            switch (token[0])
            {
                case '+': sstack.push(left + right); break;
                case '-': sstack.push(left - right); break;
                case '*': sstack.push(left * right); break;
                case '/': sstack.push(left / right); break;
            }
        }
        else
            throw InvalidToken();
    }
    if (sstack.size() != 1)
        throw InvalidRPNsyntax();
    return sstack.top();
}


const char * DivisionByZero::what() const throw()
{
    return "Division by zero";
}

const char * InvalidRPNsyntax::what() const throw()
{
    return "Invalid RPN syntax";
}

const char * InvalidToken::what() const throw()
{
    return "Invalid Character";
}

