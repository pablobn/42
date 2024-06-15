#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void) {
	int arr[] = {1,2,3,4,5,6,7,8,9};
	size_t size = sizeof(arr) / sizeof(int);
	std::vector<int> vect(arr, arr + size);

	easyfind(vect, 4);
	easyfind(vect, 10);

	return (0);
}