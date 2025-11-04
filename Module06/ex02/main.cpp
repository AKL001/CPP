#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *base = generate();

    std::cout << "Identifying using pointer: \n";
    identify(base);

    std::cout << "Identifying using reference: \n";
    identify(*base);

    delete base;

    std::cout << "\n====Testing explicit types:====" << std::endl;

    Base *a = new A();
    std::cout << "Type A - Pointer identification: ";
    identify(a);
    std::cout << "Type A - Reference identification: ";
    identify(*a);
    delete a;

    Base *b = new B();
    std::cout << "Type B - Pointer identification: ";
    identify(b);
    std::cout << "Type B - Reference identification: ";
    identify(*b);
    delete b;

    Base *c = new C();
    std::cout << "Type C - Pointer identification: ";
    identify(c);
    std::cout << "Type C - Reference identification: ";
    identify(*c);
    delete c;

    std::cout << "\n====Testing invalid types:====" << std::endl;
    Base *invalid = new Base();
    std::cout << "Invalid type - Pointer identification: ";
    identify(invalid);
    std::cout << "Invalid type - Reference identification: ";
    identify(*invalid);
    delete invalid;

    return 0;
}