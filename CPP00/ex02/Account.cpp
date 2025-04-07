/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:50:15 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/03 16:39:21 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

 // constructor
Account::Account(int initial_deposit) :
_accountIndex(_nbAccounts), _amount(initial_deposit),
_nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount <<";created" 
	<< std::endl; 
	_nbAccounts++;
}

// destructor
Account::~Account()
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";amount:"
 << _amount<< ";closed" << std::endl;
}

// Static Functions
int		Account::getNbAccounts(void) {return _nbAccounts;}
int		Account::getTotalAmount(void) {return _totalAmount;}
int		Account::getNbDeposits(void) {return _totalNbDeposits;}
int		Account::getNbWithdrawals(void) {return _totalNbWithdrawals;}
void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts << ";total:" << _totalAmount 
	<< ";deposits:" << _totalNbDeposits << ";withdrawals:" 
	<< _totalNbWithdrawals <<
	std::endl;}
void Account::_displayTimestamp(void) {
		std::time_t now = std::time(nullptr);
		std::tm* ltm = std::localtime(&now);
		std::cout 
		<< '[' << std::setfill('0') << std::setw(4) << 1900 + ltm->tm_year
		<< std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
		<< std::setfill('0') << std::setw(2) << ltm->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << ltm->tm_hour
		<< std::setfill('0') << std::setw(2) << ltm->tm_min
		<< std::setfill('0') << std::setw(2) << ltm->tm_sec << "] ";
}


// Other Functions
void	Account::makeDeposit(int deposit)
{
	if (deposit <= 0){
		std::cout << "error: deposit cant be minus" << std::endl;
		return;
	}
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex << ";p_amount:" << (_amount-deposit)
	<< ";deposit:" << deposit << ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal){
		_displayTimestamp();
		std::cout
		<< "index:" << _accountIndex << ";p_amount:"
	 << _amount << ";withdrawal:refused"
		<< std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex 
	<< ";p_amount:" <<(_amount + withdrawal)
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount 
	<< ";nb_withdrawals:" << _nbWithdrawals
	<< std::endl;

	return true;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex  << ";amount:" << _amount
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

int Account::checkAmount(void) const {return _amount;}