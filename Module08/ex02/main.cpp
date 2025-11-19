/*
    // calling .back which calles .end() calling this on empty container cause undefined behavior 
    // we need to check always if the container is empty before .back() 

    -member functions of stack
        - .top -> return reference to the  top element in the stack
        - .push -> to push elements 
        - .pop -> remove top element
        - .swap -> to swap stacks 

*/

#include "MutantStack.hpp"
#include <iostream>       // std::cout
#include <ostream>

std::ostream &out = std::cout;

int main ()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    out << mstack.size() << std::endl;

    
  return 0;
}
