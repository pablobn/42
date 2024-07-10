#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::list<int> list, std::vector<int> vector): list(list), vector(vector)
{}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe&   PmergeMe::operator=(const PmergeMe& other)
{
    (void) other;
    return *this;
}

template<typename T>
T PmergeMe::getMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template<typename T>
T PmergeMe::getMin(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<typename OutputContainer>
void PmergeMe::sortContainer(OutputContainer& sort) {
    bool swapped;
    typename OutputContainer::iterator it;
    typename OutputContainer::iterator itEnd = sort.end();
    do {
        swapped = false;
        it = sort.begin();
        typename OutputContainer::iterator prev = it;
        ++it;
        while (it != itEnd) {
            if (*prev > *it) {
                typename OutputContainer::value_type temp = *prev;
                *prev = *it;
                *it = temp;
                swapped = true;
            }
            prev = it;
            ++it;
        }
        --itEnd;
    } while (swapped);
}

template <typename OutputContainer, typename T>
typename OutputContainer::iterator PmergeMe::binarySearchInsertPosition(OutputContainer& container, const T& value) {
    typename OutputContainer::iterator begin = container.begin();
    typename OutputContainer::iterator end = container.end();

    while (begin != end) {
        typename OutputContainer::iterator middle = begin;
        std::advance(middle, std::distance(begin, end) / 2);

        if (*middle < value) {
            begin = middle;
            ++begin;
        } else {
            end = middle;
        }
    }
    return begin;
}

template<typename InputIterator, typename OutputContainer>
double PmergeMe::mergeInsertionSortContainer(InputIterator begin, InputIterator end, OutputContainer& sort) {
    clock_t start1 = clock();
    double time1 = 0;
    int n = std::distance(begin, end);
    OutputContainer minim;
    if (n < 2)
    {
        sort.push_back(*begin);
        return time1;
    }
    for (InputIterator it = begin; it != end; std::advance(it, 2)) {
        InputIterator next = std::next(it);
        if (next == end) {
            minim.push_back(*it);
            break;
        } else {
            sort.push_back(getMax(*it, *next));
            minim.push_back(getMin(*it, *next));
        }
    }
    sortContainer(sort);
    sortContainer(minim);
    for (typename OutputContainer::iterator it = minim.begin(); it != minim.end(); ++it) {
        typename OutputContainer::iterator pos = binarySearchInsertPosition(sort, *it);
        sort.insert(pos, *it);
    }
    clock_t end1 = clock();
    time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
    return time1;
}

template <typename Container>
void    PmergeMe::printContainer(const Container &container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int    PmergeMe::resolve()
{
    std::vector<int> vectRes;
    std::list<int> listRes;
    double firstTime;
    double secondTime;

    std::cout << "Before: ";
    printContainer(this->vector);
    firstTime = mergeInsertionSortContainer(this->vector.begin(), this->vector.end(), vectRes);
    secondTime = mergeInsertionSortContainer(this->list.begin(), this->list.end(), listRes);
    std::cout << "After: ";
    printContainer(vectRes);
    std::cout << "Time to process a range of " << this->vector.size() << " elements with std::vector container: " << firstTime << " us" << std::endl;
    std::cout << "Time to process a range of " << this->list.size() << " elements with std::list container: " << secondTime << " us" << std::endl;
    return (0);
}