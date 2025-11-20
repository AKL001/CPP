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
#include <exception>
#include <iostream>
#include <ostream>
#include <vector>

std::ostream &out = std::cout;

int main () 
{
    MutantStack<int> mstack;
    // MutantStack<int , std::vector<int>> vcStack;
    // std::deque<int , std::allocator<int>> dq;

      mstack.push(5);
      mstack.push(17);
  
      std::cout << mstack.top() << std::endl; // 17
      // always check size or empty before poping user error 
      mstack.pop(); 
      mstack.pop(); 
  
      std::cout << "size() : " << mstack.size() << std::endl; // 1
  
      mstack.push(3);
      mstack.push(5);
      mstack.push(737);
  
      MutantStack<int>::iterator it = mstack.begin(); 
      MutantStack<int>::iterator ite = mstack.end();
  
      it++;
      --it;
      while (it != ite)
      {
        std::cout << *it << std::endl;
        ++it;
      }
      out << "-----testing for loop-------\n";
      MutantStack<int>::iterator itte = mstack.end();
      for (MutantStack<int>::iterator itt = mstack.begin(); itt != itte ;itt++)
      {
        std::cout << *itt << std::endl;
      }

      std::stack<int> s(mstack);

      MutantStack<int> mswap;
      mswap.push(666);
      mswap.swap(mstack);

      // out << s.top() << std::endl;
      out << "mswap.top() expected()= " << mswap.top() << std::endl;
      out << "mstack.top() = " << mstack.top() << std::endl;     

  return 0;
}
