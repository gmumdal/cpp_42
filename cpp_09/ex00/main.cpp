
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::logic_error("Error : could not open file.");
		BitcoinExchange	btc;
		btc.init("data.csv");
		btc.exchange(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return (0);
}

/* 예외 처리 사항 체크 */
// 1. csv 파일 체크
// 2. date | value format 체크
// 3. date : year-month-day -> 10자 체크, 달 최대, 달에 따른 날짜 최대 체크, 윤년 체크
// 4. value : positive number 0 ~ 1000
// 5. not exist in DB -> lower date value
// 6. DB 보다 오래된 input -> 표시 불가 예외 처리 