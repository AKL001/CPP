#pragma once 
#include <stack>
#include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack& cp);
        MutantStack& operator=(const MutantStack& cp);
        ~MutantStack();

        /* member functions*/
        /*
            empty - size - top - push - emplace - pop - swap
        */
        // bool empty();
        // unsigned int size();
        // void push(const T val);
        // T& top() const; // calls the back member of underlying container
        // void pop(); // the value removed can be re called by (stack::top)
        // void swap(std::stack<T>);

        /* iterators */


};

#include "MutantStack.tpp"