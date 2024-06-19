#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
class BitcoinExchange
{
private:
	std::map<std::string, float> dict;
public:
	BitcoinExchange();
	BitcoinExchange(char *file);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange operator=(const BitcoinExchange &other);
	~BitcoinExchange();
};

#endif