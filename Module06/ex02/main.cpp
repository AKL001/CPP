#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base* generate(void)
{
    int r = std::rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A is being Instantiated Using Pointer" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B is being Instantiated Using Pointer" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C is being Instantiated Using Pointer" << std::endl;
    else
        std::cout << "Nothing" << std::endl;
}

void identify(Base& p)
{
    try
    { 
        Base& ref = dynamic_cast<A&>(p);
        (void)ref;
        std::cout << "Class A is being Instantiated Using Reff" << std::endl;
        return ;
    }
    catch(std::exception& e)
    { 
        std::cout << e.what() << std::endl;
    }

    try
    { 
        Base& ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout << "Class A is being Instantiated Using Reff" << std::endl;
        return ;
    }
    catch(std::exception& e)
    { 
        std::cout << e.what() << std::endl;
    }

    try
    { 
        Base& ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout << "Class A is being Instantiated Using Reff" << std::endl;
        return;
    }
    catch(std::exception& e)
    { 
        std::cout << e.what() << std::endl;
    }
    std::cout << "Nothing" << std::endl;
}



int main()
{
    Base *base = generate();

    std::cout << "Identifying using pointer: ";
    identify(base);

    std::cout << "Identifying using reference: ";
    identify(*base);

    delete base;

    std::cout << "\nTesting explicit types:" << std::endl;

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

    std::cout << "\nTesting invalid types:" << std::endl;
    Base *invalid = new Base();
    std::cout << "Invalid type - Pointer identification: ";
    identify(invalid);
    std::cout << "Invalid type - Reference identification: ";
    identify(*invalid);
    delete invalid;

    return 0;
}