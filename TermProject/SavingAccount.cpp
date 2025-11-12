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
	if (_rate > 0)
		interestRate = _rate;
	else
		interestRate = 0;
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
	setDepositAmmounts(interest);
}
void SavingAccount::transfer(double _amount, SavingAccount& _destinationAccount)
{
	double prevSrc, prevDest;
	prevSrc = getBalance();
	prevDest = _destinationAccount.getBalance();
	if (_amount > 0 && _amount <= getBalance())
	{
		setBalance((getBalance() - _amount));
		(_destinationAccount).setBalance(_amount);
		setTransferCounter(1);
		settransferAmmounts(_amount);

		// success confirmation and updated balances
		cout << "+-----------------------------------------------------------+" << endl;
		cout << "+                  Transfer completed                        +" << endl;
		cout << "+-----------------------------------------------------------+" << endl;
		cout << "Source Account (ID " << getID() << ") Prevoius Balance: $" << fixed << setprecision(2) << prevSrc << endl;
		cout << "Source Account (ID " << getID() << ") New Balance: $" << fixed << setprecision(2) << getBalance() << endl;


		cout << "Destination Account (ID " << _destinationAccount.getID() << ") Previous Balance: $" << fixed << setprecision(2) << prevDest << endl;

		cout << "Destination Account (ID " << _destinationAccount.getID() << ") New Balance: $" << fixed << setprecision(2) << _destinationAccount.getBalance() << endl;
	
		
	}
	else
	{
		cout << "Transfer failed: Insufficient funds." << endl;
	}
}