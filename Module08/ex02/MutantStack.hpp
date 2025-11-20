#pragma once 
#include <cstddef>
#include <stack>
#include <deque>
#include <iostream>

template <class T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
    public:
        /* alias */
        typedef typename std::stack<T, Container>::value_type value_type;
        typedef typename std::stack<T, Container>::container_type container_type ;
        // using our container iterator to iterate using stack
        typedef typename container_type::iterator iterator;
        typedef typename container_type::const_iterator const_iterator;
        // for random access iterator
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;

    public:
        MutantStack();
        MutantStack(const MutantStack& cp);
        MutantStack& operator=(const MutantStack& cp);
        ~MutantStack();
        /* protected c is an object instance of the container stack is using 
            - its an actual reference to the actual object .
        */
        // for interators 
        Container& get_container();
        const Container& get_container() const;

        iterator begin();
        const_iterator begin() const;

        iterator end();
        const_iterator end() const;  
        /* random access iterator []*/
        reference operator[](std::size_t n);
        const_reference operator[](std::size_t n) const;
};

#include "MutantStack.tpp"