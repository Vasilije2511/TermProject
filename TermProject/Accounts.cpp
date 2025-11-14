#include "Account.h"
#include<string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
Account::Account()
{
	accountCustomer = nullptr;
	ID = 0;
	withdrawlCounter = 0;
	depositsCounter = 0;
	balance=0;
	
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
	//if (_balance > 0)
	//	balance =  _balance;
	//else
	//	balance = 0; //to prevent negative balances
	balance = _balance;
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
		setDepositAmmounts(_ammount);
		setdepositDates();
	
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
			setwithdrawlAmmounts(_ammount);
			setwithdrawlDates();
	}
	else
		cout << "An Error has occured with the balance or ammount" << endl;
}
void Account::printInfo()
{
	cout << "+======================================================================================================================+" << endl;
	(*accountCustomer).printInfo();
	cout << endl  << setw(15) << "ID" << setw(25) << "Number of Withdrawls" << setw(22) << "Number of Deposits" <<setw(22) << "Number of Transfers" << setw(15) << "balance" << endl;
	cout << setw(15) << ID << setw(25) << withdrawlCounter << setw(22) << depositsCounter << setw(22) << transferCount << "$" << setw(15) <<balance << endl;
}
void Account::displayDeposits()
{
	cout << "+----------------------------------------------------------------------------------------+" << endl;

	cout << setw(15) << " "<<left<<setw(22) <<"Deposit #" << left << setw(10) << "Date"<< right<<setw(25) << "Ammount Deposited " << endl;

	for( int i = 0; i< depositAmmounts.size()&& i < depositDates.size();i++)
	{
		cout << setw(15) << " "<<left <<setw(22)<<i + 1 << right << setw(10) << depositDates[i] << right<<  "$"<< setw(15) << depositAmmounts[i] << endl;
	
	}
	
}
void Account::displayWithdrawls()
{
	cout << "+----------------------------------------------------------------------------------------+" << endl;
	cout << setw(15) << " "<<left << setw(22) << "Withdrawl #" << left << setw(10) << "Date" << right << setw(25) << "Ammount Withdrawn " << endl;

	for (int i = 0; i < withdrawlCounter  && i < wDatecount; i++)
	{
		cout << setw(15) << " "<< left << setw(22) << i + 1 << right << setw(10) << withdrawlDates[i] << right  << "$" << setw(15) << withdrawlAmmounts[i] << endl;

	}
}

void Account::displaytransfers()
{
	
	cout << "+----------------------------------------------------------------------------------------+" << endl;
	cout << setw(15) << " " << left << setw(22) << "Transfer #" << left << setw(10) << "Date" << right << setw(25) << "Ammount Transfered " << endl;

	for (int i = 0; i < transferAmmounts.size()&&i<transferDates.size(); i++)
	{
		cout << setw(15) << " " << left << setw(22) << i + 1 << right << setw(10) << transferDates[i] << right << setw(15) << "$" << transferAmmounts[i] << endl;


	}
}

void Account::displaySavingTransactions()
{
	printInfo();
	displayDeposits();
	displayWithdrawls();
	displaytransfers();
}
void Account::displayCheckingTransactions()
{
	cout << "+========================================================================================+" << endl;
	(*accountCustomer).printInfo();
	cout <<  endl << setw(15) << "ID" << setw(25) << "Number of Withdrawls" << setw(22) << "Number of Deposits" << setw(15)<<"Balance" << endl;
	cout << setw(15) << ID << setw(25) << withdrawlCounter << setw(22) << depositsCounter << setw(15) << balance << endl;
	displayDeposits();
	displayWithdrawls();
}

void Account:: setwithdrawlDates()
{
	time_t now = time(0);
	string datetime;
	tm localtime;
	localtime_s(&localtime, &now);
	datetime = to_string(localtime.tm_mon + 1) + "/" + to_string(localtime.tm_mday) + "/" + to_string(localtime.tm_year + 1900);
	withdrawlDates.push_back(datetime);
	wDatecount++;
}
void Account::setTransferDates()
{
	time_t now = time(0);
	string datetime;
	tm localtime;
	localtime_s(&localtime, &now);
	datetime = to_string(localtime.tm_mon + 1) + "/" + to_string(localtime.tm_mday) + "/" + to_string(localtime.tm_year + 1900);
	transferDates.push_back(datetime);
	tDatecount++;
}
void Account::setdepositDates()
{
	time_t now = time(0);
	string datetime;
	tm localtime;
	localtime_s(&localtime, &now);
	datetime = to_string(localtime.tm_mon + 1) + "/" + to_string(localtime.tm_mday) + "/" + to_string(localtime.tm_year + 1900);
	depositDates.push_back(datetime);
	dDatecount++;
}
