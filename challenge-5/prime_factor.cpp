#include <iostream>

bool is_prime(int);

int main()
{
    std::cout << "This program prints the prime factors of a number N" << std::endl << std::endl;
    int n = 0;
    std::cout << "Enter a number: ";
    std::cin >> n;
    bool found = false;
    for(int i = 2; i < n; ++i)
    {
        if(is_prime(i) && (n % i == 0))
        {
            found = true;
            std::cout << i << " is a prime factor of " << n << std::endl;
        }
    }
    
    if(!found)
    {
        std::cout << n << " does not have prime factors\n";
    }
    
}

bool is_prime(int v)
{
    if(v <= 1) 
    {
        return false;
    }
    if(v == 2 || v == 3)
    {
        return true;
    }
    if(v % 2 == 0 || v % 3 == 0)
    {
        return false;
    }
    for(int i = 5; i < v; ++i)
    {
        if(v % i == 0)
        {
            return false;
        }
    }
    return true;
}
