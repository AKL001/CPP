#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base* generate(void)
{
    int r = clock() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A is being Identified Using Pointer" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B is being Identified Using Pointer" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C is being Identified Using Pointer" << std::endl;
    else
        std::cout << "Nothing is Identified" << std::endl;
}

void identify(Base& p)
{
    try
    { 
        Base& ref = dynamic_cast<A&>(p);
        (void)ref;
        std::cout << "Class A is being Identified Using Reff" << std::endl;
        return ;
    }
    catch(std::exception& e)
    { 
        std::cout << "Catch Class A: " << e.what() << std::endl;
    }

    try
    { 
        Base& ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout << "Class B is being Identified Using Reff" << std::endl;
        return ;
    }
    catch(std::exception& e)
    {
        std::cout << "Catch Class B: " <<  e.what() << std::endl;
    }

    try
    { 
        Base& ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout << "Class C is being Identified Using Reff" << std::endl;
        return;
    }
    catch(std::exception& e)
    { 
        std::cout << "Catch Class C: " << e.what() << std::endl;
    }
    std::cout << "Nothing is Identified" << std::endl;
}

