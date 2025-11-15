// #include "easyfind.hpp"
#include <iostream>
#include <array>

std::ostream& out = std::cout;

template <typename T>
size_t easyfind(T& x,int a)
{
    for (size_t i = 0; i < x.size();i++)
    {
        if(x[i] == a)
            return i;
    }
    return 0;
    // throw exception
}

int main()
{
    std::string str = "Helloooo";
    // int array[4] = {1,2 ,3 ,4};
    std::array<int, 4> array = {1, 2, 3, 4};
    out << array[0] << std::endl; 
    std::cout << "Found [ " << easyfind(array, 'o') << " ]\n";

}