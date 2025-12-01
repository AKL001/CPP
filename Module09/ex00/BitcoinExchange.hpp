#pragma  once
#include <exception>
#include <iostream>
#include <map>


class NonPositiveNumber : public std::exception
{
    public:
        const char * what() const throw();
};


class BadInput : public std::exception
{
    public:
        const char * what() const throw();
};


class LargeNumber : public std::exception
{
    public:
        const char * what() const throw();
};

class InvalidDateFormat : public std::exception
{
    public:
        const char * what() const throw();
};

class NoLowerBoundDataFound : public std::exception
{
    private:
        std::string _msg;
    public:
        NoLowerBoundDataFound(const std::string &date);
        const char* what() const throw();
};



std::string trim(const std::string &line);
void validate_input_data(std::ifstream &input);

void set_database_csv(std::map<std::string,int> &database);