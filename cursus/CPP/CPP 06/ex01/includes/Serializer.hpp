#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string.h>
#include <iostream>
#include <stdint.h>

typedef struct s_data
{
	std::string name;
	int	age;
} Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif