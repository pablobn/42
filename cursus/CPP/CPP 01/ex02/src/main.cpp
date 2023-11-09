#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout<<"Dirección de memoria de string = "<<&str<<std::endl;
	std::cout<<"Dirección de memoria de stringPTR = "<<&ptr<<std::endl;
	std::cout<<"Dirección de memoria de stringREF = "<<&ref<<std::endl;

	std::cout<<"\nValor de string = "<<str<<std::endl;
	std::cout<<"Valor de stringPTR = "<<ptr<<std::endl;
	std::cout<<"Valor de stringREF = "<<ref<<std::endl;
	return (0);
}