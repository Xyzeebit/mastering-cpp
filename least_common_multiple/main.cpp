#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main()
{
    std::cout << "This program prints the least common multiple of two or more numbers" << std::endl;
    std::unordered_set<int> numbers;
    int n = 1;
    do
    {
        std::cout << "Enter a positive number or 0 to stop: ";
        std::cin >> n;
        if(n > 0)
        {
            numbers.insert(n);
        }
    }
    while(n > 0);
    auto product = [](auto& n)
    {
        int total = 1;
        for(int a : n)
        {
            total *= a;
        }
        return total;
    };
    const int iter_count = product(numbers);
    std::unordered_map<int, std::unordered_set<int>> map;
    for(const int& n : numbers)
    {
        int total = 0;
        for(int i = 0; i < iter_count; ++i)
        {
            total += n;
            map[n].insert(total);
        }
    }
    int common = 0;
    for(int i = 1; i <= iter_count; ++i)
    {
        int counter = 0;
        for(auto& [k, v] : map)
        {
            if(v.contains(i))
            {
                ++counter;
            }
        }
        
        if(counter == numbers.size())
        {
            common = i;
            break;
        }
    }

    if(common != 0)
    {
        std::cout << "The LCM of ";
        for(const auto& a : numbers)
        {
            std::cout << a << ", ";
        }
        std::cout << "is " << common << '\n';
    }
    else
    {
        std::cout << "No LCM found" << '\n';
    }
}
