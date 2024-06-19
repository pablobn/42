#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(char *file)
{
   std::ifstream fd;
    fd.open(file);
    if (!fd)
        throw NotFoundFileException();
    this->parseBaseData(fd);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &other)
{
    return other;
}

void    BitcoinExchange::addEntry(const std::string &line, double value)
{
    this->dict.insert(std::make_pair(line, value));
}

void    BitcoinExchange::parseBaseData(std::ifstream &fd)
{
    std::string line;
    std::string strValue;
    char *convert;
    double value;
    
    while (std::getline(fd, line, ',')){
        std::getline(fd, strValue);
        value = std::strtod(strValue.c_str(), &convert);
        addEntry(line, value);
    }
    fd.close();
}