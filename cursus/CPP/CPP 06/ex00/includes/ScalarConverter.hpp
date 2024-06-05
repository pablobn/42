#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "utils.hpp"
class ScalarConverter
{
	private:
		int in;
		float fl;
		double db;
		char c;
		std::string str;
		ScalarConverter();
		ScalarConverter(char *str);
		int isNumber();
		void convertDouble();
		void convertFloat();
		void convertChar();
		void convertInt();
		void print();
		void printChar(void);
		int	detectString();
	public:
		static void convert(char *string);

};

#endif