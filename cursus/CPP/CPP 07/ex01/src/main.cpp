#include "iter.hpp"
#include <iostream>

void printNum(int n)
{
	std::cout << "N = " << n << std::endl;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};

    ::iter(array, sizeof(array), printNum);
    
    return 0;
}