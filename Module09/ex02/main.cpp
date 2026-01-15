#include <cstddef>
#include <iostream>
#include <vector>

template <typename T>
int binary_search_rec(const T& array, int value, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (array[mid] == value)
        return mid;
    if (value < array[mid])
        return binary_search_rec(array, value, low, mid - 1);
    return binary_search_rec(array, value, mid + 1, high);
}


static void binary_insert(std::vector<int>& v, int value, size_t right)
{
    size_t left = 0;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (value < v[mid])
            right = mid;
        else
            left = mid + 1;
    }
    v.insert(v.begin() + left, value);
}


using namespace std;

void  PrintArray(std::vector<int>& array)
{
    cout << "[ ";
    for(int i=0; i< array.size();++i)
    {
        cout << array[i] << " ";
    }
    cout << "] " << endl;
}

// [7 2] [8 4] [1 9] 2  
//  0 1   2 3   4 5 

typedef struct Pair
        {
            int a;
            int b;
            // w : winner number
            // l : loser number 
            Pair(int w,int l) : a(w) ,  b(l){}
} Pair;

vector<int> sort_winners(std::vector<int> & array)
{

    // lest sort the array using winners i want a recursive visualisation 
    if (array.size() <= 1)
        return array;
    std::vector<Pair> pairs;
    int strangled = -1;
    // we have a strangled number
    if (array.size() % 2 != 0)
    {
        strangled = array.back();
        array.pop_back();
    }   
    for (size_t i = 0; i < array.size(); i += 2)
    {
        
        if (array[i] < array[i + 1])
            pairs.push_back(Pair(array[i+1],array[i]));
        else
            pairs.push_back(Pair(array[i],array[i+1]));
    }
    
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].a);

    mainChain = sort_winners(mainChain);

    // for (size_t i = 0; i < pairs.size(); ++i)
    // {
    //     size_t pos = 0;
    //     while (mainChain[pos] != pairs[i].a)
    //         ++pos;

    //     binary_insert(mainChain, pairs[i].b, pos);
    // }

    // if (strangled != -1)
    //     binary_insert(mainChain, strangled, mainChain.size());

    return mainChain;
}



static void print_array(const std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int main()
{
    // std::srand(std::time(0)); // seed RNG

    std::vector<int> data;
    data.push_back(2);
    data.push_back(7);
    data.push_back(0);
    data.push_back(8);
    data.push_back(5);

    // const int N = 5; // try even/odd values: 10, 11, 15, 32

    // for (int i = 0; i < N; ++i)
    //     data.push_back(std::rand() % 100); // values [0..99]

    std::cout << "Before sort:" << std::endl;
    print_array(data);

    std::vector<int> sorted = sort_winners(data);

    std::cout << "After sort:" << std::endl;
    print_array(sorted);

    return 0;
}