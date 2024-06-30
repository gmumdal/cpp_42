
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : std::map<std::string, double>()
{
	std::cout << "* BitcoinExchange constructor called *" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "* BitcoinExchange destructor called *" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : std::map<std::string, double>(copy)
{
	std::cout << "* BitcoinExchange copy constructor called *" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator= (const BitcoinExchange &copy)
{
	if (this == &copy)
		return (*this);
	*this = copy;
	std::cout << "* BitcoinExchange copy operator called *" << std::endl;
	return (*this);
}

void BitcoinExchange::init(std::string data)
{
	std::ifstream db(data.c_str());
	if (!db.is_open())
		throw std::logic_error("Error: invalid datebase");
	std::string	buf;
	while (std::getline(db, buf)) {
		if (buf.size() == 0) {
			continue ;
		}
		std::istringstream iss(buf);
		std::string key;
		std::string value;
		std::getline(iss >> std::ws, key, ',');
		std::getline(iss >> std::ws, value, ' ');
		if (key == "date" && value == "exchange_rate") {
			break ;
		}
		throw std::logic_error("Error: invalid datebase");
	}
	while (std::getline(db, buf))
	{
		if (buf.size() == 0) {
			continue ;
		}
		std::istringstream iss(buf);
		std::string key;
		std::string value;
		std::getline(iss >> std::ws, key, ',');
		std::getline(iss >> std::ws, value, ' ');
		if (!isCorrectDate(key) || !isNumber(value))
			throw std::logic_error("Error: bad input => " + buf);
		std::pair<iterator, bool> ret = insert(std::make_pair(key, strtod(value.c_str(), NULL)));
		if (ret.second == 0)
			throw std::logic_error("dupulicate data : " + key);
	}
	db.close();
}

void BitcoinExchange::exchange(std::string file)
{
	std::ifstream input(file.c_str());
	if (!input.is_open())
		throw std::logic_error("Error : could not open file.");
	std::string	buf;
	while (std::getline(input, buf)) {
		if (buf.size() == 0) {
			continue ;
		}
		std::istringstream iss(buf);
		std::string key;
		std::string delimeter;
		std::string value;
		iss >> key >> delimeter >> value;
		if (key == "date" && delimeter == "|" && value == "value") {
			break ;
		}
		throw std::logic_error("Error: invalid input");
	}
	while (std::getline(input, buf))
	{
		try
		{
			if (buf.size() == 0) {
				continue ;
			}
			std::istringstream iss(buf);
			std::string key;
			std::string delimeter;
			std::string value;
			iss >> key >> delimeter >> value;
			if (key.size() != 10 || delimeter != "|") {
				throw std::logic_error("Error: bad input => " + buf);
			} if (!isCorrectDate(key)) {
				throw std::logic_error("Error: bad input => " + buf);
			} else if (!isNumber(value)) {
				throw std::logic_error("Error: bad input => " + buf);
			}
			iterator it = upper_bound(key);
			if (it == begin())
				throw std::logic_error("Error: bad input => " + buf);
			it--;
			double real_value = strtod(value.c_str(), NULL);
			if (real_value > 1000)
				throw std::logic_error("Error: too large a number.");
			std::cout << key << " => " << real_value << " = " << real_value * it->second << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	input.close();
}

bool BitcoinExchange::isNumber(std::string value)
{
	if (value.size() == 0)
		return false;
	size_t i;
	bool zom = false;
	for (i = 0; i < value.size(); i++)
	{
		if (value[i] >= '0' && value[i] <= '9')
			continue ;
		else if (value[i] == '.' && i != value.size() - 1 && i != 0 && zom == false)
			zom = true;
		else
			return false;
	}
	return true;
}

bool BitcoinExchange::isCorrectDate(std::string date)
{
	int	year;
	int	month;
	int	day;
	int	max_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (int i = 0; i < 10; i++) {
		if (date[i] < '0' || date[i] > '9') {
			if ((i == 4 || i == 7) && date[i] == '-') {
				continue ;
			}
			return false;
		}
	}
	year = strtod(date.substr(0, 4).c_str(), NULL);
	month = strtod(date.substr(5, 2).c_str(), NULL);
	day = strtod(date.substr(8, 2).c_str(), NULL);
	if (month == 2 && day == 29)
	{
		if (year % 400 == 0)
			return true;
		else if (year % 100 == 0)
			return false;
		else if (year % 4 == 0)
			return true;
		else
			return false;
	}
	else if (month > 0 && month <= 12 && day > 0 && day <= max_day[month])
		return true;
	return false;
}
