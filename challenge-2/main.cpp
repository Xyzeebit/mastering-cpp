#include <algorithm>
#include <iostream>
#include <set>

std::set<int> get_divisors(int);
int find_greatest_common(std::set<int>, std::set<int>);

void log(std::set<int>& list) 
{
    for(auto v : list)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "This program prints the greatest common divisor of two numbers" << std::endl;
    unsigned int first = 0;
    unsigned int second = 0;
    std::cout << "Enter you first number: ";
    std::cin >> first;
    std::cout << "Enter your second number: ";
    std::cin >> second;
    std::cout << "Finding common divisors..." << std::endl;
    std::set<int> first_divs = get_divisors(first);
    std::set<int> second_divs = get_divisors(second);

    for(auto &a : first_divs)
    {
        std::cout << a << " ";
    }
    std::cout << '\n';
    for(auto &a : second_divs)
    {
        std::cout << a << " ";
    }
    std::cout << '\n';

    auto common = find_greatest_common(first_divs, second_divs);

    std::cout << "The greatest common divisor of " << first << " and " << second << " is " << common << std::endl;

}

std::set<int> get_divisors(int number)
{
    std::set<int> divisors;
    for(int i = 2; i < number; ++i)
    {
        if(number % i == 0)
        {
            divisors.insert(i);
        }
    }
    return divisors;
}

int find_greatest_common(std::set<int> first, std::set<int> second)
{
    if(first.empty() || second.empty())
    {
        return 0;
    }
    
    for(auto a = first.rbegin(); a != first.rend(); ++a)
    {
        for(auto b = second.rbegin(); b != second.rend(); ++b)
        {
            if(*a == *b)
            {
                return *a;
            }
        }
    }
    return 0;
}
