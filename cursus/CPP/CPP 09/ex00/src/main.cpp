#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if(argc != 2)
	{
		std::cerr<<"Error: bad input"<<std::endl;
		return(1);
	}
	try
	{
		BitcoinExchange exchange(argv[1]);
	}catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return(0);
}