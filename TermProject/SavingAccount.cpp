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
void SavingAccount:: setInterestRate(double rate)
{
	interestRate = rate;
}
void SavingAccount::setAll(int id, double balance, double interestRate, Customer* customerInfo)
{
	Account::setAll(customerInfo, id, 0, 0, balance);
	setInterestRate(interestRate);
}

void SavingAccount::payInterest()
{
	double interest = getBalance() * (interestRate / 100);
	depositMoney(interest);
}
void SavingAccount::transfer(double amount, SavingAccount& destinationAccount)
{
	if (amount > 0 && amount <= getBalance())
	{
		withdrawMoney(amount);
		destinationAccount.depositMoney(amount);
	}
	else
	{
		cout << "Transfer failed: Insufficient funds ." << endl;
	}
}