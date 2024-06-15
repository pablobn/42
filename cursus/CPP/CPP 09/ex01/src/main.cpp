#include "Span.hpp"
#include <time.h>

int main()
{
	try{
		Span sp = Span(20000);
		std::vector<int> vect;

		srand (time(NULL));
		for (int i = 0; i < 20000; i++)
		{
			vect.push_back(rand() % 100000);
		}
		sp.addNumbers(vect.begin(), vect.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}catch(const NotSpaceException& e)
	{
		std::cerr <<e.what()<<std::endl;
	}catch(const SpanNotFoundException& e)
	{
		std::cerr <<e.what()<<std::endl;
	}
	return 0;
}