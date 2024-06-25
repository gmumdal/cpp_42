
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
		throw std::logic_error("Error : The database doesn't exist.");
	std::string	buf;
	std::getline(db, buf);
	while (std::getline(db, buf))
	{
		if (buf.find(',', 0) == std::string::npos)
			throw std::logic_error("Error: The data is incorrect => " + buf);
		std::string	tmp_key = buf.substr(0, buf.find(',', 0));
		std::string	tmp_value = buf.substr(buf.find(',', 0) + 1, buf.size() - buf.find(',', 0));
		if (!isCorrectDate(tmp_key) || !isNumber(tmp_value))
				throw std::logic_error("Error: The data is incorrect => " + buf);
		insert(std::make_pair(tmp_key, strtod(tmp_value.c_str(), NULL)));
	}
	db.close();
}

void BitcoinExchange::exchange(std::string file)
{
	std::ifstream input(file.c_str());
	if (!input.is_open())
		throw std::logic_error("Error : could not open file.");
	std::string	buf;
	std::getline(input, buf);
	while (std::getline(input, buf))
	{
		try
		{
			if (buf.size() == 0)
				continue ;
			if (buf.find('|', 0) == std::string::npos)
				throw std::logic_error("Error: bad input => " + buf);
			std::string find_key = buf.substr(0, buf.find('|', 0) - 1);
			std::string check_value = buf.substr(buf.find('|', 0) + 2, buf.size());
			if (!isCorrectDate(find_key)) {
				throw std::logic_error("Error: incorrect date => " + find_key);
			} else if (!isNumber(check_value) && !isPositive(check_value)) {
				throw std::logic_error("Error: not a positive number.");
			} else if (!isNumber(check_value)) {
				throw std::logic_error("Error: incorrect value => " + check_value);
			}
			iterator it = find(find_key);
			if (it == end())
			{
				it = lower_bound(find_key);
				if (it == begin())
					throw std::logic_error("Error: incorrect date => " + find_key);
				it--;
			}
			double value = strtod(check_value.c_str(), NULL);
			if (value > 1000)
				throw std::logic_error("Error: too large a number.");
			std::cout << find_key << " => " << check_value << " = " << value * it->second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	input.close();
}

bool BitcoinExchange::isNumber(std::string value)
{
	size_t i;
	bool zom = false;
	for (i = 0; i < value.size(); i++)
	{
		if (value[i] >= '0' && value[i] <= '9')
			continue ;
		else if (value[i] == '.' && i != value.size() - 1 && i != 0 && zom == false)
			zom = true;
		else
			return (false);
	}
	return (true);
}

bool BitcoinExchange::isPositive(std::string value)
{
	double test = strtod(value.c_str(), NULL);
	return test >= 0;
}

bool BitcoinExchange::isCorrectDate(std::string date)
{
	int	year;
	int	month;
	int	day;
	int	max_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.size() != 10)
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if ((i == 4 || i == 7) && date[i] == '-')
			continue ;
		else if (i == 4 || i == 7)
			return (false);
		else if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	year = strtod(date.substr(0, 4).c_str(), NULL);
	month = strtod(date.substr(5, 2).c_str(), NULL);
	day = strtod(date.substr(8, 2).c_str(), NULL);
	if (month == 2 && day == 29)
	{
		if (year % 400 == 0)
			return (true);
		else if (year % 100 == 0)
			return (false);
		else if (year % 4 == 0)
			return (true);
		else
			return (false);
	}
	else if (day > max_day[month])
		return (false);
	return (true);
}
