template <class T>
MutantStack<T>::MutantStack() :  std::stack<T>()
{
}

template <class T>
MutantStack<T>::MutantStack(const MutantStack& cp) : std::stack<T>(cp) 
{
}
template <class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& cp)
{
    std::stack<T>::operator=(cp);
    return *this;
}

template <class T>
MutantStack<T>::~MutantStack()
{

}
