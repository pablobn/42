#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(char *string)
{
	this->str = string;
}

void	ScalarConverter::printChar(void)
{
		if (this->in >= 0 && this->in <= 127)
		{
			if (this->c >= 33 && this-> c <= 126)
				std::cout << "char: '"<< this->c <<"'"<<std::endl;
			else
				std::cout << "char: Non dislayable"<<std::endl;
		}
		else
			std::cout << "char: impossible"<<std::endl;
}

void	ScalarConverter::print(void)
{

    std::cout << std::fixed << std::setprecision(1);
	printChar();
	if (std::isnan(this->db) || (this->in == -2147483648 && this->fl != -2147483648))
		std::cout << "int: impossible"<< std::endl;
	else
		std::cout << "int: " << this->in << std::endl;
	std::cout << "float: " << this->fl << "f" << std::endl;
	std::cout << "double: " << this->db << std::endl;
}

int ScalarConverter::isNumber(void)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return -1;
	}
	return std::atoi(str.c_str());
}

int	ScalarConverter::detectString(void)
{
	if (isNumber() != -1)
	{
		this->in = isNumber();
		return (2);
	}
	if (str == "0.0f"|| (std::atof(str.c_str()) != 0 && str[str.length() - 1] == 'f'))
	{
		this->fl = static_cast<float>(std::atof(str.c_str()));
		return (3);
	}
	if (str == "0.0" || std::atof(str.c_str()) != 0)
	{
		this->db = std::atof(str.c_str());
		return (4);
	}
	if (str.length() == 1 && (str.c_str()[0] >= 33 && str.c_str()[0] <= 126))
	{
		this->c = static_cast<int>(str.c_str()[0]);
		return (1);
	}
	return (0);
}

void	ScalarConverter::convertChar()
{
	this->db = static_cast<double>(this->c);
	this->in = static_cast<int>(this->c);
	this->fl = static_cast<float>(this->c);
}

void	ScalarConverter::convertInt()
{
	this->db = static_cast<double>(this->in);
	this->c = static_cast<char>(this->in);
	this->fl = static_cast<float>(this->in);
}

void	ScalarConverter::convertFloat()
{
	this->db = static_cast<double>(this->fl);
	this->c = static_cast<char>(this->fl);
	this->in = static_cast<int>(this->fl);
}

void	ScalarConverter::convertDouble()
{
	this->fl = static_cast<float>(this->db);
	this->c = static_cast<char>(this->db);
	this->in = static_cast<int>(this->db);
}

//PASO 3 CON LA VARIABLE DETECTADA CONVERTIR LAS OTRAS VARIABLES
//ÚLTIMO PASO IMPRIMIR TODO
void ScalarConverter::convert(char *string)
{
	ScalarConverter conv(string);
	switch (conv.detectString())
	{
		case 1:
			conv.convertChar();
			break;
		case 2:
			conv.convertInt();
			break;
		case 3:
			conv.convertFloat();
			break;
		case 4:
			conv.convertDouble();
			break;
	}
	conv.print();
}
