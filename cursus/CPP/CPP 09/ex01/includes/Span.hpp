#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

class NotSpaceException : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return "Array is full";
		}
};

class SpanNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return "Only one or zero span allocated";
		}
};

class Span
{
	private:
		unsigned int size;
		std::vector<int> nums;
	public:
		Span(unsigned int size);
		Span(const Span& other);
		~Span();
		Span &operator=(const Span& other);
		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};
#endif