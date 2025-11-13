#pragma once 

template <typename T>
void swap(T &x,T &y)
{
    T z = x;
    x = y;
    y = z;
}

template <typename T>
T min(T &x,T &y)
{
    if(x == y)
        return y;
    T res = x < y ? x : y;
    return res;
}

template <typename T>
T max(T &x,T &y)
{
    if(x == y)
        return y;
    T res = x > y ? x : y;
    return res;
}
