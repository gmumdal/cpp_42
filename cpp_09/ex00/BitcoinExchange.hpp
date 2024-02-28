
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange : public std::map<std::string, double>
{
	private:
		bool	is_number(std::string value);
		bool	is_correct_date(std::string date);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator= (const BitcoinExchange &copy);

		void	init(std::string data);
		void	exchange(std::string file);
};

#endif
