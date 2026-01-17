/*
    # Merge Insertion (ford-Johnson)
*/
#pragma once 
#include <cerrno>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <iostream> 
#include <stdexcept>
#include <vector>
#include <set>
#include <deque>
#include <cstdlib>
#include <climits>


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

std::vector<int> sort_vector(std::vector<int> & array,std::vector<size_t>& jacob); 
std::deque<int> sort_deque(std::deque<int>& array, std::vector<size_t>& jacob);

std::vector<size_t> generateJacobsthal(size_t n);
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

template <typename Container>
void binary_insert(Container& c, int value, size_t right)
{
    size_t left = 0;
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (value < c[mid])
            right = mid;
        else
            left = mid + 1;
    }
    c.insert(c.begin() + left, value);
}

template <typename Container>
void  PrintArray(Container& array)
{
    for(size_t i=0; i< array.size();++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
