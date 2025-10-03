#include <iostream>
#include <fstream>
#include "Replace.hpp"
/* File Handling:
    read file -> fstream filein("file.txt",  ios::in)
    ifstream filein("file.txt");
    ofstream fileout("file.txt");

    file.close(); to close the file.

*/

/*
    File handling:
        std::ifstream -> readfile.
        std::ofstream -> writeFile.
        getline(<filename> , line) -> read line by line
    
    String manipulation:
        std::string::find(S1, pos) -> ???
        std::string::append  or (+=) 
        std::sting::length() or (.size())   
*/

/*  edge  cases :
    ./replace <filename> s1 s2
    - if S1 empty;
    - if S1 == S2; 
    - if more than 3 agruments
    - if we can open the file permesion , if the file exist
*/

int main(int ac,char **av)
{

    if (ac != 4)
    {
        std::cout << "Usage: ./program <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    if (std::string (av[2]).empty() || !av[3] || std::string(av[2]) == std::string(av[3]))
    {
        std::cout << "Error: invalid arguments" << std::endl;
        return 1;
    }
    // opening the file we need to check if the file exist
    if (!file_redable(av[1]))
    {
        std::cout << "failed to open file" << std::endl;
        return 1;
    }

    Replace replace(av[1], av[2], av[3]); 

    replace.replace_content();

    return 0;
}