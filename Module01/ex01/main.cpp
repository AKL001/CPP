#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie  *zombies = zombieHorde(N, "ZombieHorde");

    for (int i = 0; i < N ; i++)
    {   
        std::cout << "[" << i << "] ";
        zombies[i].annonce();
    }
    // free all the memory allocated [] cuz we allocated an array 
    delete[] zombies;
    return 0;
}