#include <iostream>
#include "Contact.hpp"
// #include "PhoneBook.hpp"




int main(int ac,char **av)
{
    (void)ac;
    (void)av;
    
    Contact cnt = Contact("karim","hamid", "NICK","idk","0123123");

    std::cout << cnt.getFirstName() << '\n';
    cnt.setFirstName("not karim");
    std::cout << cnt.getFirstName()<< '\n';
    std::cout << cnt.getLastName()<< '\n';


}