#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
template <typename T>
void easyfind(T& arr, int n){
	if ( std::find (arr.begin(), arr.end(), n) != arr.end())
		std::cout << "Found the number" << std::endl;
	else
		std::cout << "Number not found :C." << std::endl;
}
#endif