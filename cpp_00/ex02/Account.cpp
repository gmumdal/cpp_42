
#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
		<< _totalAmount << ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_nbDeposits = 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	_amount = _amount + deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< p_amount << ";deposit:" << deposit << ";amount:"
			<< _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:"
			<< _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	p_amount = _amount;
	_nbWithdrawals = 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	_amount = _amount - withdrawal;
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< p_amount << ";withdrawal:" << withdrawal << ";amount:"
			<< _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void	Account::_displayTimestamp(void)
{
	char		buf[20];
	std::time_t currentTime = std::time(NULL);
	std::tm 	*timeInfo = std::localtime(&currentTime);

	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", timeInfo);
	std::cout << "[" << buf << "] ";
}
