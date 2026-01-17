#include "PmergeMe.hpp"
#include <algorithm>

/*
    # HELPER FUNTIONS
    # binary_insertion or we could use .lower_bound()
    # void  PrintArray(std::vector<int>& array)
    # generate the jacosthal sequence array generateJacobsthal
*/

void  PrintArray(std::vector<int>& array)
{
    // std::cout << "[ ";
    for(size_t i=0; i< array.size();++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// void  PrintArray(std::vector<size_t>& array)
// {
//     cout << "-----jacobstal list n = [ " << array.size() << "-----\n";
//     cout << "[ ";
//     for(size_t i=0; i< array.size();++i)
//     {
//         cout << array[i] << " ";
//     }
//     cout << "] " << endl;
//     cout << "\n---------------------\n";
// }

// [7 2] [8 4] [1 9] 2  
//  0 1   2 3   4 5 

int main(int ac,char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./Pmergeme <random numbers>" << std::endl;
        return 1;
    }
    std::vector<int> myVector;
    std::deque<int>  myDeque;
    try
    {   
        fill_container(av, myVector);
        std::cout << "Befor: ";
        PrintArray(myVector);
        
        std::clock_t start_vec = std::clock();
        
        myVector = sort_vector(myVector); // Or sort_vector if you renamed it
        std::clock_t end_vec = std::clock();
        double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

        std::cout << "After:  ";
        PrintArray(myVector);

        // 4. Print Timing Results
        std::cout << "Time to process a range of " << myVector.size() 
                  << " elements with std::vector : " << time_vec << " us" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}