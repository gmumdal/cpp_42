
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cctype>

class BitcoinExchange : public std::map<std::string, double>
{
	private:
		bool isNumber(std::string value);
		bool isPositive(std::string value);
		bool isCorrectDate(std::string date);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator= (const BitcoinExchange &copy);

		void init(std::string data);
		void exchange(std::string file);
};

#endif
