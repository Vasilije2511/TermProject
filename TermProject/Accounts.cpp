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
	totalDeposits = 0;
	totalWitdrawl = 0;
}
Account::Account( Customer *_accountCustomer, int _id, double _balance)
{
	Account::setAll( _accountCustomer, _id, _balance);


}
void Account:: setAll(Customer* _accountCustomer, int _id, double _balance) 
{
	setAccountCustomer(_accountCustomer);

	setID(_id);

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
		withdrawlCounter = withdrawlCounter+ _withdrawlCounter; //need to check back if we just update the value of the counter or completely over rides with new val...
	
}
void Account::setDepositCounter(int _depositCounter)
{
	if (_depositCounter > 0)
		depositsCounter = depositsCounter +_depositCounter; 

}
void Account::setBalance(double _balance)
{
	if (_balance > 0)
		balance =  _balance;
	else
		balance = 0; //to prevent negative balances
}
void Account::setTotalTransfers(double _transferAmmount)
{
	if (_transferAmmount > 0)
		totaltransfers = totaltransfers + _transferAmmount;
}
double Account::getTotalTransfers() const
{
	return totaltransfers;
}

void Account::setTotaldeposits(double _depositAmmount)
{
	if (_depositAmmount > 0)
		totalDeposits = totalDeposits + _depositAmmount;
}
double Account::getTotaldeposits() const
{
	return totalDeposits;
}


void Account::setTotalWithdrawls(double _withdrawlAmmount)
{
	if (_withdrawlAmmount > 0)
		totalWitdrawl = totalWitdrawl + _withdrawlAmmount;
}
double Account::getTotalWithdrawls() const
{
	return totalWitdrawl;
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
void Account::setTransferCounter(int _transferCounter)
{
	if (_transferCounter > 0)
		transferCount = _transferCounter;

}
int Account:: getTransferCounter() const
{
	return transferCount;
}
double Account::getBalance() const
{
	return balance;
}
void Account ::depositMoney(double _ammount)
{
	if (_ammount > 0)
	{
		balance = balance + _ammount;
		setDepositCounter(1); // this might be slow instead we can also write depositsCounter = depositsCounter +1
		setTotaldeposits( _ammount);
	}
	
	else
		cout << "Invalid Amount" << endl;
}
void Account::withdrawMoney(double _ammount)
{
	if(balance>0&& balance>=_ammount&& _ammount >0)
	{
			balance = balance - _ammount;
			setWithdrawlCounter(1); // this might be slow instead we can also write depositsCounter = depositsCounter +1 
			setWithdrawlCounter( _ammount);
	}
	else
		cout << "An Error has occured with the balance or ammount" << endl;
}
void Account::printInfo()
{
	cout << "____________________________________________________________________________________________________________________________________________\n";
	(*accountCustomer).printInfo();
	cout << endl << setw(15) << "ID" << setw(25) << "Number of Withdrawls" << setw(22)<<"Number of Deposits"<<endl;
	cout << setw(15) << ID << setw(25) << withdrawlCounter << setw(22) << depositsCounter << endl;
}