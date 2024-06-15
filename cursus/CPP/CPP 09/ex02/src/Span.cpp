#include "Span.hpp"

Span::Span(unsigned int size): size(size)
{}

Span::~Span(){}

Span::Span(const Span& other) : size(other.size), nums(other.nums){}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        size = other.size;
        nums = other.nums;
    }
    return *this;
}

void    Span::addNumber(int n)
{
    if (nums.size() >= size)
        throw NotSpaceException();
    nums.push_back(n);
}

void    Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    size_t newSize = std::distance(begin, end);
    std::cout << newSize << " vs " << size << std::endl;
    if (newSize > size)
        throw NotSpaceException();
    nums.insert(nums.end(), begin, end);
}

int Span::shortestSpan()
{
    if (nums.size() <= 1)
        throw NotSpaceException();
    
    int shortest = std::abs(nums[0] - nums[1]);
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (j != i)
            {
                if (std::abs(nums[j] - nums[i]) < shortest)
                {
                    shortest = std::abs(nums[j] - nums[i]);
                }
            }
        }
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (nums.size() <= 1)
        throw NotSpaceException();
    
    int longest = std::abs(nums[0] - nums[1]);
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (j != i)
            {
                if (std::abs(nums[j] - nums[i]) > longest)
                {
                    longest = std::abs(nums[j] - nums[i]);
                }
            }
        }
    }
    return (longest);
}