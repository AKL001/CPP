template <class T>
Array<T>::Array() : _array(nullptr) , _size(0)
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
    for (int i = 0;i < n;i++)
        _array[i] = T();
}


template <class T>
Array<T>::Array(const Array<T>& cp){*this = cp}

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
        {
            this->_array = NULL;
        }
    }
    return *this;
}

template <class T>
Array<T>::~Array()
{
    delete[] this->_array;
}
