#include <iostream>
#include "Array.hpp" 

template <typename T>
void printArray(const Array<T>& arr)
{
    std::cout << "[ ";
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}       

int main()
{
    std::cout << "--- 1. Default & Parameterized Constructor Test ---" << std::endl;
    // Test default constructor
    Array<int> empty;
    std::cout << "Default array size: " << empty.size() << std::endl;
    
    // Test parameterized constructor
    Array<int> numbers(10);
    std::cout << "Parameterized array size: " << numbers.size() << std::endl;
    
    // Test default initialization (should be 0)
    std::cout << "Initial value at numbers[5]: " << numbers[5] << std::endl;

    std::cout << "\n--- 2. Write & Read Test (operator[]) ---" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = i * 10;
    }
    std::cout << "After filling, numbers[9]: " << numbers[9] << std::endl;
    std::cout << "Full 'numbers' array: ";
    ::printArray(numbers);

    std::cout << "\n--- 3. Copy Constructor Test (Deep Copy) ---" << std::endl;
    Array<int> copy(numbers);
    std::cout << "Copied array size: " << copy.size() << std::endl;

    numbers[0] = -100;

    std::cout << "Original array 'numbers' at [0]: " << numbers[0] << std::endl;
    std::cout << "Copied array 'copy' at [0] (should be 0): " << copy[0] << std::endl;
    
    std::cout << "\n--- 4. Assignment Operator Test (Deep Copy) ---" << std::endl;
    Array<int> assigned(3); 
    assigned[0] = 123;
    std::cout << "Before assignment, 'assigned' size: " << assigned.size() << std::endl;
    
    assigned = copy;
    
    std::cout << "After assignment, 'assigned' size: " << assigned.size() << std::endl;

    copy[1] = 777;
    
    std::cout << "Modified 'copy' at [1]: " << copy[1] << std::endl;
    std::cout << "'assigned' at [1] (should be 10): " << assigned[1] << std::endl;


    std::cout << "\n--- 5. Template Test (std::string) ---" << std::endl;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "World";
    words[2] = "!";
    
    std::cout << "Full 'words' array: ";
    ::printArray(words);
    
    Array<std::string> wordsCopy = words;
    words[0] = "Goodbye";
    std::cout << "Original 'words[0]': " << words[0] << std::endl;
    std::cout << "Copied 'wordsCopy[0]': " << wordsCopy[0] << std::endl;


    std::cout << "\n--- 6. Exception Test (Out of Bounds) ---" << std::endl;
    try
    {
        std::cout << "Attempting to access numbers[99]..." << std::endl;
        numbers[99] = 123; 
        std::cout << "!!! TEST FAILED: Accessing [99] did not throw." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "SUCCESS: Caught exception: " << e.what() << std::endl;
    }
  
    try
    {
        std::cout << "Attempting to access empty[0]..." << std::endl;
        empty[0] = 1; 
        std::cout << "!!! TEST FAILED: Accessing [0] on empty did not throw." << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "SUCCESS: Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\nAll tests complete." << std::endl;
    
    return 0;
}