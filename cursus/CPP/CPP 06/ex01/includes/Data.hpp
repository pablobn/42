#ifndef DATA_HPP
#define DATA_HPP
#include <string.h>
#include <iostream>
class Data
{
	private:
		std::string name;
        int age;
	public:
        Data();
        Data(std::string name, int age);
};

#endif