/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:42:15 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/18 19:42:16 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << " index:" << Account::_nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
}

Account::Account( void )
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << " index:" << Account::_nbAccounts << ";amount:" << 0 << ";created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += 0;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts -= 1;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount - withdrawal >= 0)
	{
		Account::_totalNbWithdrawals += 1;
		this->_nbWithdrawals += 1;
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << 
		withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << 
	deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << 
	this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << 
	Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	char		curTime[128];

	std::time_t t = std::time(0);
    std::strftime(curTime, sizeof(curTime), "[%Y%m%d_%I%M%S]", std::localtime(&t));
    std::cout << curTime;
}

int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
