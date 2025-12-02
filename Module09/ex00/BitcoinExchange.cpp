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

NoLowerBoundDataFound::NoLowerBoundDataFound(const std::string &date)
{
    _msg = "No early date in DB for " + date;
}

NoLowerBoundDataFound::~NoLowerBoundDataFound() throw(){}

const char * NoLowerBoundDataFound::what() const throw()
{
    return _msg.c_str();
}

/*----------Utils----------------*/
std::string trim(const std::string &line)
{
    size_t l = line.find_first_not_of(" \t\r\n");
    if (l == std::string::npos) return ""; // empty string
    size_t r = line.find_last_not_of(" \t\r\n");
    return line.substr(l, r - l + 1);
}
/* the lower and high bound work */
double get_db_value(const std::map<std::string,double> &data_base,const std::string &date)
{
    std::map<std::string,double>::const_iterator it = data_base.find(date);
    if (it != data_base.end())
        return it->second;
    else
    {
        it = data_base.lower_bound(date);
        if (it == data_base.begin())
            throw NoLowerBoundDataFound(date);
        --it;
        return it->second;
    }
}

/*-----------validating date format------------*/
bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void validate_date(const std::string &date)
{
     if (date.size() != 10 ||
        date[4] != '-' || date[7] != '-' ||
        !isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3]) ||
        !isdigit(date[5]) || !isdigit(date[6]) ||
        !isdigit(date[8]) || !isdigit(date[9]))
    {
        throw BadInput();
    }
    int year = atoi(date.substr(0,4).c_str());
    int month  = atoi(date.substr(5,2).c_str());
    int day = atoi(date.substr(8,2).c_str());

    if (month < 1 || month > 12)
        throw InvalidDateFormat();
    int max_day;
    switch(month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: max_day = 31; break;
        case 4: case 6: case 9: case 11: max_day = 30; break;
        case 2:
            if (is_leap_year(year))
                max_day = 29;
            else
                max_day = 28;
        break;
        default:
            throw InvalidDateFormat();
    }
    if (day < 1 || day > max_day)
        throw InvalidDateFormat();
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
}

/*-------------validating database && input file-----------*/
void set_database_csv(std::map<std::string,double> &database)
{
    std::string line;
    std::string log_file = ".db_log.txt";
    std::string filename = "data.csv";
    std::ifstream infile(filename.c_str());
    if (!infile)    
    {
        std::cout << "Error: cannot open file " << filename << std::endl;
        return;
    }
    std::ofstream logfile(log_file.c_str());
    if (!logfile.is_open()) 
    {
        std::cerr << "Warning: Could not open log file " << log_file << ". Proceeding without logging." << std::endl;
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
            logfile << "Error: bad Format in line -> " << line << std::endl;
            continue;
        }
        std::string date_str = trim(line.substr(0, pos));
        std::string value_str = trim(line.substr(pos + 1));
        try
        {
            validate_date(date_str);
        }
        catch(std::exception &e)
        {
            logfile << "Error (Line " << line_count << "): Invalid date -> " << date_str << std::endl;
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
            logfile << "Error (Line " << line_count << "): " << e.what() << " on value string -> " << value_str << std::endl;
            continue;
        }
    }
    // streams are autmatically closed after getting out of scope
    // explicit closing
    infile.close();
    logfile.close();
}


void validate_input_data(std::ifstream &input,std::map<std::string,double> &data_base)
{
    std::string line;
    const std::string sep = " | ";
    while(std::getline(input,line))
    {
        line = trim(line); 
        if (line.empty()) continue;
        size_t pos = line.find(sep); // maybe needs a .c_str() for c++98
        if (line.find_first_of("0123456789") == std::string::npos) continue; // this for text only we skip it
        if (pos != 10 || pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0,pos));
        std::string value = trim(line.substr(pos + 3));
        try
        {
            // validate the date format
            validate_date(date);
            // validate the value
            double number = 0;
            is_valid_input_value(value, number);
            double db_value;
            try 
            {
                db_value = get_db_value(data_base,date);
                std::cout << date << " => " << value << " = " << (db_value * number) << std::endl; //here we need to extract the value
            }
            catch(std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
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
        catch (const InvalidDateFormat &e)
        {
            std::cout << "Error: " << e.what() << " => " << line << std::endl;
        }
    }
}