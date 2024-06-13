#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
template <typename A>
void iter(A *array, size_t length, void (*func)(A&)) {
	if (array == NULL || func == NULL)
		return ;
	for(size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif