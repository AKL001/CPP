#include "Span.hpp"
#include <iterator>
#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm> // for std::generate
#include <vector>
#include <cstdlib>

struct RandomNumberGenerator {
    int operator()() const {
        return std::rand();
    }
};

template <typename IT>
void print_container(IT begin,IT end)
{
    int dis = std::distance(begin , end);
    std::cout << "Dis is : " << dis << '\n';
    while (begin != end)
    {
        std::cout << *begin << '\n';
        begin++;
    }
}


int main()
{
    std::vector<int>v (10);

    std::srand(time(NULL)); 
    std::generate(v.begin(),v.end(),RandomNumberGenerator());

    ::print_container(v.begin(), v.end());

    Span sp(10);
    sp.addNumber(v.begin(),v.end());
    std::cout << "short :" << sp.shortestSpan() << std::endl;
    std::cout << "logest :  " << sp.longestSpan() << std::endl;  

}

// void printTestName(std::string name) {
//     std::cout << "\n=== " << name << " ===" << std::endl;
// }

// int main() {
//     try {
//         // ==========================================
//         // TEST 1: Crossing Zero
//         // ==========================================
//         printTestName("Test 1: Crossing Zero");
//         Span sp1 = Span(5);
//         // Adding -10 and 10. 
//         // Distance should be: 10 - (-10) = 20
//         sp1.addNumber(-10);
//         sp1.addNumber(10); 
//         sp1.addNumber(0); // Adding 0 to check distance to -10 and 10

//         // Sorted: -10, 0, 10
//         // Shortest: 0 - (-10) = 10 OR 10 - 0 = 10. Result: 10
//         // Longest:  10 - (-10) = 20
        
//         std::cout << "Numbers: {-10, 0, 10}" << std::endl;
//         std::cout << "Shortest Span (Expected 10): " << sp1.shortestSpan() << std::endl;
//         std::cout << "Longest Span  (Expected 20): " << sp1.longestSpan() << std::endl;


//         // ==========================================
//         // TEST 2: All Negative Numbers
//         // ==========================================
//         printTestName("Test 2: All Negatives");
//         Span sp2 = Span(5);
//         // Adding: -100, -50, -55
//         // Sorted: -100, -55, -50
//         sp2.addNumber(-100);
//         sp2.addNumber(-50);
//         sp2.addNumber(-55);

//         // Diffs:
//         // -55 - (-100) = 45
//         // -50 - (-55)  = 5  <-- Shortest
//         // Longest: -50 - (-100) = 50

//         std::cout << "Numbers: {-100, -50, -55}" << std::endl;
//         std::cout << "Shortest Span (Expected 5):  " << sp2.shortestSpan() << std::endl;
//         std::cout << "Longest Span  (Expected 50): " << sp2.longestSpan() << std::endl;


//         // ==========================================
//         // TEST 3: Mixed Large Range
//         // ==========================================
//         printTestName("Test 3: Mixed Large Range");
//         Span sp3 = Span(10);
        
//         // Cluster 1 (Negatives): -2000, -1990 (Diff 10)
//         // Cluster 2 (Positives): 100, 105 (Diff 5)
//         // Gap between clusters: 100 - (-1990) = 2090
        
//         sp3.addNumber(-2000);
//         sp3.addNumber(100);
//         sp3.addNumber(-1990);
//         sp3.addNumber(105);

//         // Sorted: -2000, -1990, 100, 105
        
//         std::cout << "Numbers: {-2000, 100, -1990, 105}" << std::endl;
//         std::cout << "Shortest Span (Expected 5):    " << sp3.shortestSpan() << std::endl;
//         std::cout << "Longest Span  (Expected 2105): " << sp3.longestSpan() << std::endl;

//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <climits> // Required for INT_MAX and INT_MIN
// #include "Span.hpp"

// int main() {
//     std::cout << "--- Testing Integer Overflow Edge Case ---" << std::endl;

//     try {
//         // 1. Create a Span with space for 2 numbers
//         Span sp = Span(5);

//         // 2. Add the Minimum and Maximum possible integers
//         // INT_MAX =  2147483647
//         // INT_MIN = -2147483648
//         sp.addNumber(INT_MAX);
//         sp.addNumber(INT_MIN);

//         std::cout << "Added numbers: " << INT_MAX << " and " << INT_MIN << std::endl;

//         // 3. Calculate Spans
//         // The distance should be: 2147483647 - (-2147483648) = 4294967295
//         unsigned int shortest = sp.shortestSpan();
//         unsigned int longest = sp.longestSpan();

//         std::cout << "Shortest Span: " << shortest << std::endl;
//         std::cout << "Longest Span:  " << longest << std::endl;

//         // Check expected value (UINT_MAX is typically 4294967295)
//         if (longest == 4294967295U) {
//             std::cout << "\n[SUCCESS] Overflow handled correctly." << std::endl;
//         } else {
//             std::cout << "\n[FAIL] Overflow occurred! Result likely corrupted." << std::endl;
//         }

//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }