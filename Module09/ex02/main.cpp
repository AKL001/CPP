#include <algorithm>
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
    for(size_t i=0; i< array.size();++i)
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


// static void print_pairs(const std::vector<Pair>& v)
// {
//     for (size_t i = 0; i < v.size(); ++i)
//         std::cout << "[ "<< v[i].a << " , " << v[i].b << " ]" ;
//     std::cout << std::endl;
// }

vector<int> sort_winners(std::vector<int> & array)
{
    if (array.size() <= 1)
        return array;
    std::vector<Pair> pairs;
    // reserve memory so vector wont reallocate memory each time 
    pairs.reserve(array.size()/ 2);

    int strangled = -1;
    bool has_strangled = false;
    // we have a strangled number
    if (array.size() % 2 != 0)
    {
        strangled = array.back();
        has_strangled = true; // we could remove this since we are using possitive numbers only
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
    mainChain.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].a);
    /*  
        Main recursion 
    */
    mainChain = sort_winners(mainChain);
    /*
        # we can start to insert the numbers here.
        # insert the number b1 , before a1. to minimal the comparison. 
        # using the jacobshal 
        # we insert b1 before a1 , since b1 < a1. 
        # finding the a1 pair b1 
    */
    // we arange the pending list, for the pairs , meaning bN with aN
    std::vector<int> pend;
    pend.reserve(mainChain.size());
    
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
            if (pairs[j].a == mainChain[i])
            {
                pend.push_back(pairs[j].b);
                break;
            }
    }
    cout << "----main chain-----\n";
    PrintArray(mainChain);
    // cout << "----pending chain-----\n";
    // PrintArray(pend);

    // after we organaised pending  to be aligned with there pairs we can just insert b1
    mainChain.insert(mainChain.begin(), pend[0]);
    
    /* TODO: here we use the jacobsthal numbers for insertion  
        through the remaining losers in "pairs" at each recursion kN
        # using jacobsthal we insert the number excluding the b1 (prend [0]) cuz already inserted
        # inserting the stranged number, time complexity (log2​(n+1)
    */
    // cout << "------- Chain after inserting b1 -------\n";
    // PrintArray(mainChain);  
    if (has_strangled)
        binary_insert(mainChain, strangled, mainChain.size());

    return mainChain;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int main()
{
    // std::srand(std::time(0)); // seed RNG
    // [3 , 7] [0 , 5] [10 , 2] [8 , 1] 6 ->  
    // [0 , 5, 7, 10]
    // [       3 , 2 ]
    //  [0 , 5, 7, 10]
    //  [0 , 3 , 2 , 1]
    // [7 , 5 ] [10 , 8] -> [5, 7, 10]
    // [7 , 10 ] -> [5 , 7 , 10]

    std::vector<int> data;
    data.push_back(3);
    data.push_back(8);

    data.push_back(1);
    data.push_back(9);
    
    data.push_back(4);
    data.push_back(0);
    
    data.push_back(5);
    data.push_back(2);
    
    data.push_back(7);


    // const int N = 5; // try even/odd values: 10, 11, 15, 32

    // for (int i = 0; i < N; ++i)
    //     data.push_back(std::rand() % 100); // values [0..99]

    std::cout << "Before sort:" << std::endl;
    PrintArray(data);

    std::vector<int> sorted = sort_winners(data);

    std::cout << "After sort:" << std::endl;
    PrintArray(sorted);

    return 0;
}