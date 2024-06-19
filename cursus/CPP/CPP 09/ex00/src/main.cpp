#include "BitcoinExchange.hpp"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	if(argc != 2)
	{
		std::cerr<<"Error: bad input"<<std::endl;
		return(1);
	}
	BitcoinExchange exchange(argv[1]);
	return(0);
}