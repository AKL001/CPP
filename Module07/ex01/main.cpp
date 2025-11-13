#include "iter.hpp"

void increment(int &x) {
    ++x;
}

void printInt(const int &x) {
    std::cout << x << " ";
}

int main() {
    int numbers[] = {1, 2, 3};
    const int constNumbers[] = {7, 8, 9};

    ::iter(constNumbers, 3, ::printInt);
    std::cout << std::endl;

    ::iter(numbers, 3, ::printInt);
    std::cout << std::endl;

    ::iter(numbers, 3, ::increment);
    std::cout << "After increment: ";
    ::iter(numbers, 3, ::printInt);
    std::cout << std::endl;

    return 0;
}
