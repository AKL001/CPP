template <class T, typename Container>
MutantStack<T,Container>::MutantStack() :  std::stack<T,Container>()
{
}

template <class T, typename Container>
MutantStack<T,Container>::MutantStack(const MutantStack& cp) : std::stack<T,Container>(cp) 
{
}
template <class T , typename Container>
MutantStack<T,Container>& MutantStack<T,Container>::operator=(const MutantStack& cp)
{
    std::stack<T, Container>::operator=(cp);
    return *this;
}

template <class T,typename Container>
MutantStack<T, Container>::~MutantStack()
{

}

template <class T,typename Container>
Container& MutantStack<T, Container>::get_container()
{
    return this->c;
}


template <class T,typename Container>
const Container& MutantStack<T, Container>::get_container() const
{
    return this->c;
}

template <class T,typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return (*this).get_container().begin();
}

template <class T,typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
    return (*this).get_container().begin();
}

template <class T,typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return (*this).get_container().end();
}

template <class T,typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const  
{
    return (*this).get_container().end();
}

/* random access iterator []*/

template <class T,typename Container>
typename MutantStack<T, Container>::reference MutantStack<T, Container>::operator[](std::size_t n)
{
    return this->get_container()[n];
}

template <class T,typename Container>
typename MutantStack<T, Container>::const_reference MutantStack<T, Container>::operator[](std::size_t n) const
{
    return this->get_container()[n];
}

template <class T,typename Container>
void MutantStack<T, Container>::swap(MutantStack<T, Container> &sp)
{
    std::swap((*this),sp);
}