#include "Account.h"
#include<string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>
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
void Account::setID(int _id) //set the id value 
{
	if (_id > 0)//maybe check val against other ids to prevent duplicates
		ID = _id;
	else
		ID = 0;
}
void Account:: setWithdrawlCounter(int _withdrawlCounter)//increment the withdrawl counter
{
	if (_withdrawlCounter > 0)
		withdrawlCounter = withdrawlCounter+ _withdrawlCounter; 
}
void Account::setDepositCounter(int _depositCounter) //increment the deposit counter
{
	if (_depositCounter > 0)
		depositsCounter = depositsCounter +_depositCounter; 

}
void Account::setBalance(double _balance) //set the total balance for the account
{
	if (_balance > 0)
		balance =  _balance;
	else
		balance = 0; //to prevent negative balances
}
void Account::setTotalTransfers(double _transferAmmount) //increment the transfer ammount counter
{
	if (_transferAmmount > 0)
		totaltransfers = totaltransfers + _transferAmmount;
}
double Account::getTotalTransfers() const //return the total ammount transfered
{
	return totaltransfers;
}

void Account::setTotaldeposits(double _depositAmmount) //increment the total deposits counter
{
	if (_depositAmmount > 0)
		totalDeposits = totalDeposits + _depositAmmount;
}
double Account::getTotaldeposits() const //returnt he total deposits ammount
{
	return totalDeposits;
}


void Account::setTotalWithdrawls(double _withdrawlAmmount) //increment the withdrawl counter
{
	if (_withdrawlAmmount > 0)
		totalWitdrawl = totalWitdrawl + _withdrawlAmmount;
}
double Account::getTotalWithdrawls() const //return the total ammount withdrawn 
{
	return totalWitdrawl;
}

Customer* Account::getAccountCustomer() const //return the account customer object
{
	return accountCustomer;
}
int Account::getID() const //return the ID
{
	return ID;
}
int Account::getWithdrawlCounter() const //return the withdrawl counter
{
	return withdrawlCounter;
}
int Account::getDepositsCounter() const //return the deposit counter
{
	return depositsCounter;
}
void Account::setTransferCounter(int _transferCounter) //increment the counter
{
	if (_transferCounter > 0)
		transferCount = transferCount + _transferCounter;

}
int Account:: getTransferCounter() const //return the transfer count
{
	return transferCount;
}
double Account::getBalance() const //return the balance
{
	return balance;
}

void Account::settransferAmmounts(double _transferAmmount) //add ammount to vector
{
	transferAmmounts.push_back(_transferAmmount);  
}

double Account::recieveTransferAmmount(int i) //get an individual ammount from the vector
{
	return transferAmmounts[i-1];
}


void Account::setwithdrawlAmmounts(double _withdrawlAmmount) //add ammount to vector
{
	withdrawlAmmounts.push_back(_withdrawlAmmount);
}

double Account::recievewithdrawlAmmount(int i) //get an individual ammount from the vector
{
	return withdrawlAmmounts[i-1];
}
void Account::setDepositAmmounts(double _depositAmmount) //add ammount to vector
{
	depositAmmounts.push_back(_depositAmmount); 
}

double Account::recieveDepositAmmount(int i) //get an individual ammount from the vector
{
	return depositAmmounts[i-1];
}
//Add additional array setter and getters

void Account ::depositMoney(double _ammount)
{
	if (_ammount > 0)
	{
		balance = balance + _ammount;
		setDepositCounter(1); // this might be slow instead we can also write depositsCounter = depositsCounter +1
		setTotaldeposits( _ammount);
		setDepositAmmounts(_ammount);
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
			setTotalWithdrawls(_ammount);
			setwithdrawlAmmounts(_ammount);
	}
	else
		cout << "An Error has occured with the balance or ammount" << endl;
}
void Account::printInfo()
{
	cout << "+===========================================================+\n";
	(*accountCustomer).printInfo();
	cout << endl << setw(15) << "ID" << setw(25) << "Number of Withdrawls" << setw(22)<<"Number of Deposits"<<endl;
	cout << setw(15) << ID << setw(25) << withdrawlCounter << setw(22) << depositsCounter << endl;
}
void Account::displayDeposits()
{
	cout << "+===========================================================+\n";
	cout << setw(40) << "Deposits";
	cout << endl << "Number of Deposits" << setw(22) << depositsCounter<< endl;
	for( int i = 0; i< depositAmmounts.size();i++)
	{
		cout << "Deposit #" << i + 1 << setw(20) << "Ammount Deposited $" << depositAmmounts[i];
	
	}
	
}
void Account::displayWithdrawls()
{
	cout << "+===========================================================+\n";
	cout << endl << "Number of withdrawls" << setw(22) << withdrawlCounter << endl;
	for (int i = 0; i < withdrawlAmmounts.size(); i++)
	{
		cout << "Withdrawl #" << i + 1 << setw(20) << "Ammount withdrawn $" << withdrawlAmmounts[i];

	}
}

void Account::displaytransfers()
{
	
	cout << "+===========================================================+\n";
	cout << endl << "Number of transfers" << setw(22) << transferCount << endl;
	for (int i = 0; i < transferAmmounts.size(); i++)
	{
		cout << "Transfer #" << i + 1 << setw(20) << "Ammount Transfered $" << transferAmmounts[i];

	}
}

void Account::displayAllTransactions()
{

	displayDeposits();
	displayWithdrawls();
	displaytransfers();
}
