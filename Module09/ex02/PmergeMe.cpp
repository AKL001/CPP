#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>

/*
    # we could use generic function , but the subject ask not too
*/
std::vector<int> sort_vector(std::vector<int> & array,std::vector<size_t>& jacob)
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
    mainChain = sort_vector(mainChain,jacob);
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
    // after we organaised pending  to be aligned with there pairs we can just insert b1
    mainChain.insert(mainChain.begin(), pend[0]);    
    /* TODO: here we use the jacobsthal numbers for insertion  
        through the remaining losers in "pairs" at each recursion kN
        # using jacobsthal we insert the number excluding the b1 (prend [0]) cuz already inserted
        # inserting the stranged number, time complexity (log2​(n+1)
    */
    // 3. we generate the jacob sthal indices based on the size of the pending elements
    // PrintArray(jacob);
    // 4. the insertion loop jacobsthal 
    // we start from k = 3 , cuz k = 1 is already inserted 
    size_t k = 3;
    size_t ins_count = 1;
    // # last_jacob_index so we dont insert the number already inserted
    size_t last_jacob_index = 1;

    while (k < jacob.size() || ins_count < pend.size())
    {
        // # in case if we ran out of jacob numbers
        size_t current_jacob_idx = (k < jacob.size()) ? jacob[k] : pend.size();
        // but we also need to still check if jacob number bigger than the size
        if (current_jacob_idx > pend.size())
            current_jacob_idx = pend.size();
        // # limit is 1, is k - 1 in the generated list 
        size_t limit = last_jacob_index;
        
        // inserting reversed 
        for (size_t i = current_jacob_idx; i > limit ; --i)
        {
            size_t value_to_insert = pend[i - 1];
            // we insert from  a1 to aN, what define N is the pending 
            // what if we get 11 out of the pending range then we just the pending length 
            // we add the ins_count cuz we insert numbers dont forget  
            size_t range_end = i + ins_count;
            if (range_end > mainChain.size()) range_end = mainChain.size();

            binary_insert(mainChain, value_to_insert, range_end);
            
            ins_count++;
        }
        last_jacob_index = current_jacob_idx;
        k++;
    }
    if (has_strangled)
        binary_insert(mainChain, strangled, mainChain.size());

    return mainChain;
}

std::deque<int> sort_deque(std::deque<int>& array, std::vector<size_t>& jacob)
{
    if (array.size() <= 1)
        return array;

    std::deque<Pair> pairs;
    int strangled = -1;
    bool has_strangled = false;

    if (array.size() % 2 != 0)
    {
        strangled = array.back();
        has_strangled = true;
        array.pop_back();
    }

    for (size_t i = 0; i < array.size(); i += 2)
    {
        if (array[i] < array[i + 1])
            pairs.push_back(Pair(array[i+1], array[i]));
        else
            pairs.push_back(Pair(array[i], array[i+1]));
    }
    
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].a);

    mainChain = sort_deque(mainChain, jacob);

    std::deque<int> pend;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
            if (pairs[j].a == mainChain[i])
            {
                pend.push_back(pairs[j].b);
                break;
            }
    }

    mainChain.insert(mainChain.begin(), pend[0]);
    
    size_t k = 3;
    size_t ins_count = 1;
    size_t last_jacob_index = 1;

    while (k < jacob.size() || ins_count < pend.size())
    {
        size_t current_jacob_idx = (k < jacob.size()) ? jacob[k] : pend.size();
        
        if (current_jacob_idx > pend.size())
            current_jacob_idx = pend.size();

        size_t limit = last_jacob_index;
        
        for (size_t i = current_jacob_idx; i > limit ; --i)
        {
            size_t value_to_insert = pend[i - 1]; // standard indexing works on deque
            
            size_t range_end = i + ins_count;
            if (range_end > mainChain.size()) range_end = mainChain.size();

            binary_insert(mainChain, value_to_insert, range_end);
            
            ins_count++;
        }
        last_jacob_index = current_jacob_idx;
        k++;
    }

    if (has_strangled)
        binary_insert(mainChain, strangled, mainChain.size());

    return mainChain;
}

std::vector<size_t> generateJacobsthal(size_t n) 
{
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    
    size_t last = 1;
    size_t prev = 0;
    while (true) {
        size_t next = 2 * prev + last;
        jacob.push_back(next);
        if (next >= n) break;
        prev = last;
        last = next;
    }
    return jacob;
}

bool is_valid_number(const std::string& num)
{
    if (num.empty()) return false;
    size_t sign = (num[0] == '+') ? 1 : 0;
    if (sign == num.length()) return false;

    for (size_t i = sign; i < num.length();++i)
    {
        if (!isdigit(num[i])) return false;
    }
    return true;
}