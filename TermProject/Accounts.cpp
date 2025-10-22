#include "Account.h"
#include<string>
#include <iomanip>
#include <iostream>

using namespace std;
Account::Account()
{
	accountCustomer = nullptr;
	ID = 0;
	withdrawlCounter = 0;
	depositsCounter = 0;
	balance=0;
}
Account::Account( Customer *_accountCustomer, int _id, int _withdrawlCounter, int _depositsCounter, double _balance)
{
	Account::setAll( _accountCustomer, _id, _withdrawlCounter, _depositsCounter, _balance);
}
void Account:: setAll(Customer* _accountCustomer, int _id, int _withdrawlCounter, int _depositsCounter, double _balance) 
{
	setAccountCustomer(_accountCustomer);

	setID(_id);

	setWithdrawlCounter(_withdrawlCounter);
	setDepositCounter(_depositsCounter);
	setBalance(_balance);
}
void Account::setAccountCustomer(Customer* _accountCustomer)
{
	accountCustomer = _accountCustomer;

}
void Account::setID(int _id)
{
	if (_id > 0)//maybe check val against other ids to prevent duplicates
		ID = _id;
	else
		ID = 0;
}
void Account:: setWithdrawlCounter(int _withdrawlCounter)
{
	if (_withdrawlCounter > 0)
		withdrawlCounter = _withdrawlCounter; //need to check back if we just update the value of the counter or completely over rides with new val...
	else
		withdrawlCounter = 0;
}
void Account::setDepositCounter(int _depositCounter)
{
	if (_depositCounter > 0)
		depositsCounter = _depositCounter; //need to check back if we just update the value of the counter or completely over rides with new val...
	else
		depositsCounter = 0;
}
void Account::setBalance(double _balance)
{
	if (_balance > 0)
		balance = _balance;
	else
		balance = 0; //to prevent negative balances, but need to come back to check if balance can actually be negative
}
Customer* Account::getAccountCustomer() const
{
	return accountCustomer;
}
int Account::getID() const
{
	return ID;
}
int Account::getWithdrawlCounter() const
{
	return withdrawlCounter;
}
int Account::getDepositsCounter() const
{
	return depositsCounter;
}
double Account::setBalance() const
{
	return balance;
}
