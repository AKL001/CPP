#include "PmergeMe.hpp"
#include <ctime>
#include <vector>

/*
    # HELPER FUNTIONS
    # binary_insertion or we could use .lower_bound()
    # void  PrintArray(std::vector<int>& array)
    # generate the jacosthal sequence array generateJacobsthal
*/

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
        fill_container(av, myDeque);
        // generating the jacobsthal sequence depending on the number of elements we have 
        std::vector<size_t> jacob = generateJacobsthal(ac - 1);

        std::cout << "Befor: ";
        PrintArray(myVector);

        // calculating vector time in microseconds us
        std::clock_t start_vec = std::clock();
        myVector = sort_vector(myVector,jacob);
        std::clock_t end_vec = std::clock();
        double time_vec = static_cast<double>(end_vec - start_vec);

        // caulclating deque time in microseconds us
        std::clock_t start_deq = std::clock();
        myDeque = sort_deque(myDeque,jacob);
        std::clock_t end_deq = std::clock();
        double time_deq = static_cast<double>(end_deq - start_deq);



        std::cout << "After:  ";
        PrintArray(myVector);

        // adding precision instead of scientific notation 
        // printing the value in microseconds
        // std::cout << std::fixed << std::setprecision(5);

        std::cout << "Time to process a range of " << myVector.size() 
        << " elements with std::vector : "    
        << time_vec << " us" << std::endl;

        std::cout << "Time to process a range of " << myDeque.size() 
        << " elements with std::deque : "    
        << time_deq << " us" << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}