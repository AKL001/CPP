/*
    # Merge Insertion (ford-Johnson)
    # 

*/

#pragma once 
#include <cstddef>

template <typename Container>
class PmergeMe
{
    private:
        size_t _comparison;
        double _timer;

        // a for biggers numbers b for smaller one for each pair
        struct Pair
        {
            int a;
            int b;
            // w : winner number
            // l : loser number 
            Pair(int w,int l) : a(w) ,  b(l){}
        };
        // comparison counter , is a less than b 
        bool is_a_Less_b(int a,int b);
        /*
            _comparison++;
            return a < b;
        */
        

    public:
        PmergeMe(); 
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

};