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

int main()
{

    // std::map<std::string, float>::iterator it;
    std::map<std::string, int> db;
    std::string fileName = "input.txt";
    std::ifstream infile(fileName.c_str());
    set_database_csv(db);
    validate_input_data(infile);
    // std::map<std::string, int>::iterator it;
    // std::map<std::string, int>::iterator ite = db.end();
    // out << "-------Printing map--------\n";
    // for (it = db.begin(); it != ite;++it)
    // {
    //     out << it->first << " " << it->second << '\n';
    // }
    // if (!infile.is_open())
    //     {
    //         std::perror("Cant open File");
    //         return 1;
    //     }
    // std::string line = "";
    
    // std::map<std::string, float> mmap;

    // while (std::getline(infile, line))
    // {

    //     out << line << '\n';
    // }
    infile.close();

    /*---------------testing the map container----------------*/
    // std::string key =  "2011-02-03";
    // it = mmap.find(key);
    
    // if (it != mmap.end())
    // {
    //     out << mmap.count(key) << std::endl; 
    //     out << key << " value = " << mmap.find(key)->second << std::endl; 
    // }

}