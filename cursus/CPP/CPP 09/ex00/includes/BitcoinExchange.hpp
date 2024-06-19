#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <map>
#include <cstdlib>

class NotFoundFileException : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return "Couldn't open that file";
		}
};

class BitcoinExchange
{
private:
	std::map<std::string, double> dict;
public:
	BitcoinExchange();
	BitcoinExchange(char *file);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	void	parseBaseData(std::ifstream &fd);
	void	addEntry(const std::string &line, double value);
};

#endif