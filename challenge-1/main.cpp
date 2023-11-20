#include <iostream>
#include <vector>
#include <numeric>

void divide_by(int, int, std::vector<int>&);

int main()
{
    std::cout << "This program prints the sum of natural numbers divisible by 3 and 5"
        << std::endl;
    unsigned int limit = 0;
    std::cout << "Enter a natural number limit: ";
    std::cin >> limit;

    std::vector<int> numbers;

    divide_by(limit, 3, numbers);
    divide_by(limit, 5, numbers);

    auto sum = std::accumulate(std::begin(numbers), std::end(numbers), 0);

    std::cout << "The sum of all numbers divisible by 3 and 5 upto " << limit << " is: " << sum << std::endl;
}

void divide_by(int limit, int divisor, std::vector<int>& store)
{
    if(limit < divisor)
    {
        return;
    }
    for(int i = divisor; i <= limit; ++i)
    {
        if(i % divisor == 0)
        {
            store.push_back(i);
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}
