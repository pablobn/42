#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <list>
#include <vector>
#include <cstring>
#include <ctime>
#include <cctype>
class PmergeMe
{
	private:
		std::list<int> list;
		std::vector<int> vector;
	public:
		PmergeMe(std::list<int> list, std::vector<int> vector);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe& other);
		template<typename InputIterator, typename OutputContainer>
		double mergeInsertionSortContainer(InputIterator begin, InputIterator end, OutputContainer& sort);
		template <typename Container>
    	void printContainer(const Container &container);
		template<typename OutputContainer>
		void sortContainer(OutputContainer& sort);
		template<typename T>
		T getMax(const T& a, const T& b);
		template<typename T>
		T getMin(const T& a, const T& b);
		template <typename OutputContainer, typename T>
   		typename OutputContainer::iterator binarySearchInsertPosition(OutputContainer& container, const T& value);
		int resolve();
};
#endif