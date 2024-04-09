#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string.h>
#include <iostream>
#include <cstdlib>
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
		char convertChar(char *str);
		int convertInt(char *str);
		double convertDouble(char *str);
		float convertFloat();
		void print();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
		int	detectString()
	public:
		static void convert(char *string);

};

#endif