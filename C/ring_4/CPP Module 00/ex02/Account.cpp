/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoropeza <aoropeza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:31:34 by aoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 12:31:41 by aoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){

	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->getNbAccounts();
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	Account::_nbAccounts++;

}

Account::~Account(void){

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;

}

int	Account::getNbAccounts(void){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void){
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void){
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::_displayTimestamp(void){

	time_t	t_now;

	t_now = time(NULL);
	std::cout << std::put_time(localtime(&t_now), "[%Y%m%d_%H%M%S] ");

}

void	Account::makeDeposit(int deposit){

	int	p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;

}

bool	Account::makeWithdrawal(int withdrawal){

	int	p_amount = this->_amount;

	if (withdrawal <= p_amount) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else {
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

}

void	Account::displayAccountsInfos(void){

	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits() << ";withdrawals:";
	std::cout << Account::getNbWithdrawals() << std::endl;

}
