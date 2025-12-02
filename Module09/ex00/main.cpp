#include <cerrno>
#include <cstdio>
#include <fstream>
#include <istream>
#include <iterator>
#include <map>
#include <ostream>
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

/*
    - validate the .csv data firt (database)
    - validate the input.txt file , check if the file end up with .txt? the formate is correct (date | value)

*/

std::ostream &out = std::cout;

// void validate_database(std::ifstream &infile)
// void validate_inputfile(std::string &infile)
// {
//     /* check all the data is writing in the same format 
//         2009-01-02,0 
//         date,value
//         - we can use regex for validating the date
//         - and slit the data with ','??
//         - check if the year isLeap 
//         bool isLeap(int year) {
//         return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//         }
//         */
//     // line check that  check the date, and value also it should not be more than 
    
// }

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Usage: ./btc <inputfile.txt>\n";
        return 1;
    }
    std::map<std::string, double> db;
    std::string fileName = av[1];
    std::ifstream infile(fileName.c_str());
    if (!infile) {perror("");return 1;}
    set_database_csv(db);
    validate_input_data(infile,db);
    infile.close();
}