#include "Account.h"
#include"Customer.h"
#include "SavingAccount.h"
#include<string>
#include <iomanip>
#include <iostream>
using namespace std;

SavingAccount::SavingAccount ()
{
	interestRate = 0.0;
}
SavingAccount::SavingAccount(int _id, double _balance, double _interestRate, Customer* _customerInfo): Account(_customerInfo, _id, _balance)
{
	setInterestRate(_interestRate);
}

double SavingAccount:: getInterestRate() const
{
	return interestRate;
}
void SavingAccount:: setInterestRate(double _rate)
{
	interestRate = _rate;
}
void SavingAccount::setAll(int _id, double _balance, double _interestRate, Customer* _customerInfo)
{
	Account::setAll(_customerInfo, _id, _balance);
	setInterestRate(_interestRate);
}

void SavingAccount::payInterest()
{
	double interest = getBalance() * (interestRate / 100);
	depositMoney(interest);
}
void SavingAccount::transfer(double _amount, SavingAccount& _destinationAccount)
{
	if (_amount > 0 && _amount <= getBalance())
	{
		withdrawMoney(_amount);
		_destinationAccount.depositMoney(_amount);
	}
	else
	{
		cout << "Transfer failed: Insufficient funds ." << endl;
	}
}