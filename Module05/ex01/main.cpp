#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

int main()
{
    std::cout << BLUE << "=== TESTING Bureaucrat and Form ===" << RESET << std::endl;

    try {
        Bureaucrat b1("Alice", 50);
        Form f1("TopSecret", false, 30, 50);

        std::cout << GREEN << "Created Bureaucrat: " << b1 << RESET << std::endl;
        std::cout << GREEN << "Created Form: " << f1 << RESET << std::endl;

        Form f2(f1);
        std::cout << YELLOW << "Copy of Form: " << f2 << RESET << std::endl;

        Form f3;
        f3 = f1;
        std::cout << YELLOW << "Assigned Form: " << f3 << RESET << std::endl;

    } catch (const std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== TESTING edge cases ===" << RESET << std::endl;

    try {
        Bureaucrat b2("Bob", 0); 
    } catch (const std::exception &e) {
        std::cout << RED << "Expected exception (grade too high): " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 151); 
    } catch (const std::exception &e) {
        std::cout << RED << "Expected exception (grade too low): " << e.what() << RESET << std::endl;
    }

    try {
        Form f4("ImpossibleForm", false, 0, 50); 
    } catch (const std::exception &e) {
        std::cout << RED << "Expected exception (Form grade too high): " << e.what() << RESET << std::endl;
    }

    try {
        Form f5("ImpossibleForm2", false, 151, 50); 
    } catch (const std::exception &e) {
        std::cout << RED << "Expected exception (Form grade too low): " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== TESTING signing forms ===" << RESET << std::endl;

    try {
        Bureaucrat b4("Diana", 25);
        Bureaucrat b5("Eve", 100);

        Form f6("Confidential", false, 50, 50);
        Form f7("TopSecret", false, 20, 30);

        std::cout << f6 << std::endl;
        std::cout << f7 << std::endl;

        b4.signForm(f6);
        std::cout << GREEN << "After signing f6: " << f6 << RESET << std::endl;

        b5.signForm(f7);
        std::cout << GREEN << "After signing f7: " << f7 << RESET << std::endl;

        b4.signForm(f7);
        std::cout << GREEN << "After signing f7: " << f7 << RESET << std::endl;

    } catch (const std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n=== TESTING increment/decrement edge cases ===" << RESET << std::endl;

    try {
        Bureaucrat b6("Frank", 1);
        b6.incrementGrade();
    } catch (const std::exception &e) {
        std::cout << RED << "Expected exception on increment: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b7("Grace", 150);
        b7.decrementGrade(); 
    } catch (const std::exception &e) {
        std::cout << RED << "Expected exception on decrement: " << e.what() << RESET << std::endl;
    }

    return 0;
}
