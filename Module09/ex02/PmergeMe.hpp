/*
    # Merge Insertion (ford-Johnson)
*/
#pragma once 
#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <set>
#include <deque>
#include <cstdlib> // Required for std::strtol
#include <climits> // Required for INT_MAX


struct Pair
{
    // w : winner number
    // l : loser number 
    int a;
    int b;
    Pair(int w,int l) : a(w) ,  b(l){}
};

/*
    # TODO: we need a timer , and a comparison counter
    count_timer()
    count_comparison()
*/

void binary_insert(std::vector<int>& v, int value, size_t right);
std::vector<size_t> generateJacobsthal(size_t n);
std::vector<int> sort_vector(std::vector<int> & array);
bool is_valid_number(const std::string& num);

template <typename Containe>
void fill_container(char **av,Containe& container)
{
    std::set<int> dup_num;
    size_t i = 1;
    while(av[i])
    {   
        std::string arg = av[i];

        if (!is_valid_number(arg))
            throw std::runtime_error("Error: Invalid number format.");

        char *end;
        long val = std::strtol(arg.c_str(),&end,10);
        if (val < 0)
            throw std::invalid_argument("Error: Negative numbers not allowed.");
        if (val > INT_MAX)
            throw std::out_of_range("Error: Number too large for integer.");
        
        int num = static_cast<int>(val);
        if (dup_num.find(num) != dup_num.end())
        {
            i++;
            continue;
        }
        dup_num.insert(num);
        container.push_back(num);
        i++;
    }    
}

/*
    # HELPER FUNCTIONS
*/
void  PrintArray(std::vector<int>& array);
void  PrintArray(std::vector<size_t>& array);
