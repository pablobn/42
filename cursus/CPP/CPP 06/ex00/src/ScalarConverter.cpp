#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(char *string)
{
	this->str = string;
}

// char	ScalarConverter::convertChar(char *str)
// {
// 	char res;
// 	long i = std::strtol(str, nullptr, 10);


// 	if (i < 0 || i > 127)
// 		res = -1;
// 	else
// 		res = static_cast<char>(i);
// 	return (res);
// }

// int	ScalarConverter::convertInt(char *str)
// {
// 	int res;
// 	long i = std::strtol(str, nullptr, 10);


// 	if (i > 2147483647 || i<-2147483648)
// 		res = 0;
// 	else
// 		res = static_cast<int>(i);
// 	return (res);
// }

// float	ScalarConverter::convertFloat()
// {
// 	float res = static_cast<float>(this->db);

// 	return (res);
// }

// double	ScalarConverter::convertDouble(char *str)
// {
// 	double res;

// 	res = atof(str);
// 	return (res);
// }

// void	ScalarConverter::printChar(void)
// {
// 	if (this->c == 0)
// 	{
// 		if (!isNumber(this->value) || !isZero(this->value))
// 			std::cout << "char: impossible" << std::endl;
// 		else
// 			std::cout << "char: Non dislayable"<< this->c <<std::endl;
// 	}
// 	else if (this->c >= 0 && this->c <= 127)
// 	{
// 		if (this->c >= 33 && this-> c <= 126)
// 			std::cout << "char: '"<< this->c <<"'"<<std::endl;
// 		else
// 			std::cout << "char: Non dislayable"<<std::endl;
// 	}
// 	else
// 		std::cout << "char: impossible"<<std::endl;
	
// }

// void	ScalarConverter::print(void)
// {
// 	printChar();
// 	printInt();
// 	printFloat();
// 	printDouble();
// }

//PASO 1 DETECTAR QUE TIPO DE VARIABLE ESTAN ENVIANDO
int	detectString(void)
{
	//DETECTAR STRING SEA UN CHAR (1)
	//DETECTAR STRING SEA UN INT (2)
	//DETECTAR STRING SEA UN FLOAT (3)
	//DETECTAR STRING SEA UN DOUBLE (4)
}

//PASO 2 CONVERTIR EL STRING A LA VARIABLE DETECTADA
//PASO 3 CON LA VARIABLE DETECTADA CONVERTIR LAS OTRAS VARIABLES
//ÚLTIMO PASO IMPRIMIR TODO

void ScalarConverter::convert(char *string)
{
	ScalarConverter conv(string);

	// conv.print();
}
