template <class T>
Array<T>::Array() : _array(NULL) , _size(0)
{

}

template <class T>
Array<T>::Array(const unsigned int  n) :_size(n)
{
    if (n == 0)
    {
        this->_array = NULL;
        return;
    }
    _array = new T[n];
    for (unsigned int i = 0;i < n;i++)
        _array[i] = T();
}


template <class T>
Array<T>::Array(const Array<T>& cp) : _size(cp._size)
{
    if (cp._size > 0)
    {
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = cp._array[i];
    }
    else
        this->_array = NULL;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& cp)
{
    if (this !=  &cp)
    {
        delete[] this->_array;
        this->_size = cp._size;
        if (cp._size > 0)
        {
            this->_array = new T[cp._size];
            for (unsigned int i = 0; i < cp._size; i++)
                this->_array[i] = cp._array[i];
        }
        else
            this->_array = NULL;
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw CantAccessElementOutBound();
    return _array[index];
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw CantAccessElementOutBound();
    return _array[index];
}


template <class T>
Array<T>::~Array()
{
    delete[] this->_array;
}

template <class T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <class T>
const char * Array<T>::CantAccessElementOutBound::what() const throw()
{
    return "Error: Index is out of bounds.";
}