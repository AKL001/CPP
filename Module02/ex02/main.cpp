// #include <iostream>
// #include <cmath>
// #include "Fixed.hpp"

// #define EPSILON 0.01f // tolerance for float comparisons

// bool checkFloat(const Fixed& value, float expected, const std::string& msg) {
//     if (std::fabs(value.toFloat() - expected) < EPSILON) {
//         std::cout << msg << " PASS\n";
//         return true;
//     } else {
//         std::cout << msg << " FAIL: got " << value.toFloat() << ", expected " << expected << "\n";
//         return false;
//     }
// }

// bool checkInt(const Fixed& value, int expected, const std::string& msg) {
//     if (value.toInt() == expected) {
//         std::cout << msg << " PASS\n";
//         return true;
//     } else {
//         std::cout << msg << " FAIL: got " << value.toInt() << ", expected " << expected << "\n";
//         return false;
//     }
// }

// int main() {
//     int total = 0;

//     std::cout << "----- Constructors & output -----" << std::endl;
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));
//     Fixed c(10);
//     Fixed d(c);

//     total++;
//     checkFloat(a, 0.0f, "Default constructor a");

//     total++;
//     checkFloat(b, 10.10f, "b = 5.05 * 2");

//     total++;
//     checkInt(c, 10, "Int constructor c");

//     total++;
//     checkInt(d, 10, "Copy constructor d");

//     std::cout << "\n----- Assignment -----" << std::endl;
//     a = Fixed(3.14f);
//     total++;
//     checkFloat(a, 3.14f, "Assignment a = 3.14f");

//     std::cout << "\n----- Arithmetic operators -----" << std::endl;
//     Fixed sum = a + c;
//     Fixed diff = c - a;
//     Fixed prod = a * Fixed(2);
//     Fixed divi = c / Fixed(2);

//     total++;
//     checkFloat(sum, 13.14f, "a + c");

//     total++;
//     checkFloat(diff, 6.86f, "c - a");

//     total++;
//     checkFloat(prod, 6.28f, "a * 2");

//     total++;
//     checkFloat(divi, 5.0f, "c / 2");

//     std::cout << "\n----- Increment/Decrement -----" << std::endl;
//     total++;
//     checkFloat(++a, 4.14f, "Prefix ++a");

//     total++;
//     checkFloat(a++, 4.14f, "Postfix a++");

//     total++;
//     checkFloat(a, 5.14f, "Value after a++");

//     total++;
//     checkFloat(--a, 4.14f, "Prefix --a");

//     total++;
//     checkFloat(a--, 4.14f, "Postfix a--");

//     total++;
//     checkFloat(a, 3.14f, "Value after a--");

//     std::cout << "\n----- Min/Max functions -----" << std::endl;
//     Fixed e(2);
//     Fixed f(4);
//     const Fixed g(3);
//     const Fixed h(5);

//     total++;
//     checkFloat(Fixed::min(e, f), 2.0f, "min(e,f)");

//     total++;
//     checkFloat(Fixed::min(g, h), 3.0f, "min(g,h)");

//     total++;
//     checkFloat(Fixed::max(e, f), 4.0f, "max(e,f)");

//     total++;
//     checkFloat(Fixed::max(g, h), 5.0f, "max(g,h)");

//     std::cout << "\n----- toInt / toFloat -----" << std::endl;
//     total++;
//     checkInt(a, 3, "a.toInt()");

//     total++;
//     checkFloat(a, 3.14f, "a.toFloat()");

//     std::cout << "\nTotal tests run: " << total << std::endl;

//     return 0;
// }
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    // 10.1016
    std::cout << b << std::endl;
    // 10.1016
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}