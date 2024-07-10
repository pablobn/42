#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>

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
	void	readBaseData();
	std::string	decreaseDate(std::string date);
	void	findDate(std::string firstDate, std::string date, float value);
	int		checkDate(std::string firstDate, std::string date);
	int		checkValue(std::string value);
	void	checkValues(std::string line);
	void    convertBitcoin(std::ifstream &fd);
	void	addEntry(const std::string &line, double value);
};

#endif