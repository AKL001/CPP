/* 
    - we can use map::count(<key>) to search for a key if valid in the map
    - we also can use map::find(<key>) return a pointer to that key else the map.end()
    -  we can also access the map using random access operator [ ]
    - map::size to know the size of the map
    - map::insert to insert new elements 
    // use of std::multimap , for multiple keys to use 
    - map by default it sort the keys 

*/

// validating the data of input.txt  
// then validating the date , and the value 
// if the date is not in our database , we use the closest date contained in our DB (we use the lower date not the upper one)

/* throw exception when an  error is ocurred */
#include <cstdarg>
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include "BitcoinExchange.hpp"

/*  Exceptions  override*/
const char * NonPositiveNumber::what() const throw()
{
    return "not a positive number.";
}

const char * BadInput::what() const throw()
{
    return "bad input";
}

const char * LargeNumber::what() const throw()
{
    return "too large a number.";
}

const char * InvalidDateFormat::what() const throw()
{
    return "Invalid Date Format.";
}
/*----------Utils----------------*/
std::string trim(const std::string &line)
{
    size_t l = line.find_first_not_of(" \t\r\n");
    if (l == std::string::npos) return ""; // empty string
    size_t r = line.find_last_not_of(" \t\r\n");
    return line.substr(l, r - l + 1);
}

/*-----------validating date format------------*/
bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}



/*---------------validating value--------------*/
void is_valid_database_value(const std::string &s,double &value)
{
    char *end;
    const char *c = s.c_str();
    double v = strtod(c, &end);
    if (c == end) throw BadInput();
    if (*end != '\0') throw BadInput(); //  meaning there is something after the number
    if (v < 0.0) throw NonPositiveNumber(); // meaning no number is there it should be more than 0
    value = v;
}

void is_valid_input_value(const std::string &s,double &value)
{
    is_valid_database_value(s,value);
    if (value > 1000.0) throw LargeNumber(); // meaning value bigger than 1000
    // value = v;
}



/*-------------validating database && input file-----------*/
void set_database_csv(std::map<std::string,int> &database)
{
    std::string line;
    std::string filename = "db.csv";
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cout << "Error: cannot open file " << filename << std::endl;
        return;
    }
    size_t line_count = 0;
    while(std::getline(infile, line))
    {
        line_count++;
        line = trim(line);
        if(line.empty()) continue;
        size_t pos = line.find(',');
        if (pos == std::string::npos)
        {
            // std::cout << "Error: bad Format in line -> " << line << std::endl;
            continue;
        }
        std::string date_str = trim(line.substr(0, pos));
        std::string value_str = trim(line.substr(pos + 1));
        try
        {
            // validate_date(date_str);
        }
        catch(std::exception &e)
        {
            // std::cout << "Error (Line " << line_count << "): Invalid date -> " << date_str << std::endl;
            continue;
        }
        double value;
        try
        {
            is_valid_database_value(value_str, value);
            database[date_str] = value;
        }
        catch(const std::exception &e)
        {
            // std::cout << "Error (Line " << line_count << "): " << e.what() << " on value string -> " << value_str << std::endl;
            continue;
        }
    }
}


void validate_input_data(std::ifstream &input)
{
    std::string line;
    const std::string sep = " | ";
    while(std::getline(input,line))
    {
        line = trim(line); 
        if (line.empty()) continue;
        size_t pos = line.find(sep); // maybe needs a .c_str() for c++98
        if (pos != 10 || pos == std::string::npos)
        {
            std::cout << "Error : bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0,pos));
        std::string value = trim(line.substr(pos + 3));
        try
        {
            // is_valid_date(date);
            double number = 0;
            is_valid_input_value(value, number);
            std::cout << date << " => " << value << std::endl; //here we need to extract the value
        }
        catch (const NonPositiveNumber &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch (const LargeNumber &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch (const BadInput &e)
        {
            std::cout << "Error: " << e.what() << " => " << line << std::endl;
        }
        
    }

}