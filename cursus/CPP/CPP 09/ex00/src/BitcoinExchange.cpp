#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->readBaseData();
}

BitcoinExchange::BitcoinExchange(char *file)
{
   std::ifstream fd;
    fd.open(file);
    if (!fd)
        throw NotFoundFileException();
    this->readBaseData();
    this->convertBitcoin(fd);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange()
{}

//CAMBIAR ESTO
BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void) other;
    return *this;
}

void    BitcoinExchange::addEntry(const std::string &line, double value)
{
    this->dict.insert(std::make_pair(line, value));
}

void    BitcoinExchange::readBaseData()
{
    std::string line;
    std::string strValue;
    char *convert;
    double value;
    std::ifstream fd;

    fd.open("../data.csv");
    if (!fd)
        throw NotFoundFileException();
    
    while (std::getline(fd, line, ',')){
        std::getline(fd, strValue);
        value = std::strtod(strValue.c_str(), &convert);
        addEntry(line, value);
    }
    fd.close();
}

int BitcoinExchange::checkDate(std::string firstDate, std::string date)
{
    std::stringstream   str(date);
    std::string         year, month, day;
    int flag = 0;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: Bad input => " << firstDate << std::endl;
        return (-1);
    }
    getline(str, year, '-');
    getline(str, month, '-');
    getline(str, day);
    if (atoi(year.c_str()) > 2022 || atoi(year.c_str()) < 2009)
        flag = 1;
    if (atoi(month.c_str()) > 12 || atoi(month.c_str()) < 1)
        flag = 1;
    if (atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1)
        flag = 1;
    if (flag)
    {
        std::cout << "Error: Bad input => " << firstDate << std::endl;
        return (-1);
    }
    return (0);

}

int    BitcoinExchange::checkValue(std::string value)
{
	float   val = atof(value.c_str());
	if (val < 0)
	{
		std::cout << "Error: Not a positive number." << std::endl;
		return (-1);
	}
	if (val > 1000)
	{
		std::cout << "Error: Too large a number." << std::endl;
		return (-1);
	}
	return (val);
}

std::string BitcoinExchange::decreaseDate(std::string date)
{
    std::stringstream dateStream(date);
    std::string yearStr, monthStr, dayStr, newDateStr;

    getline(dateStream, yearStr, '-');
    getline(dateStream, monthStr, '-');
    getline(dateStream, dayStr);

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (day > 1) {
        day--;
    } else if (month > 1) {
        day = 31;
        month--;
    } else if (year > 2008) {
        day = 31;
        month = 12;
        year--;
    }

    std::stringstream newDateStream;
    newDateStream << year << '-' << std::setw(2) << std::setfill('0') << month << '-' << std::setw(2) << std::setfill('0') << day;
    newDateStr = newDateStream.str();
    return (newDateStr);
}

void    BitcoinExchange::findDate(std::string firstDate, std::string date, float value)
{
    float result = 0;
    if (this->dict.find(date) != this->dict.end())
	{
		result = value * this->dict[date];
		std::cout << firstDate << " => " << value << " = " << result << std::endl;
	}
    else
    {
        date = decreaseDate(date);
        if (checkDate(firstDate, date) != -1)
            findDate(firstDate, date, value);
    }   
}

void    BitcoinExchange::checkValues(std::string line)
{
    std::stringstream   s(line);
    std::string date, del, value, finalDate;
    s >> date >> del >> value;
    float val;
    if (checkDate(date, date) != -1)
    {
        val = checkValue(value);
        if (val != -1)
            findDate(date, date, val);

    }
}

void    BitcoinExchange::convertBitcoin(std::ifstream &fd)
{
    std::string line;
    std::string strValue;
    while (std::getline(fd, line)){
        checkValues(line);
    }
    fd.close();
}