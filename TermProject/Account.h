#pragma once
#ifndef ACCOUNT
#define ACCOUNT
#include "Customer.h"
#include <vector>

class Account
{
	int ID, withdrawlCounter=0, depositsCounter=0;
	double balance;
	Customer *accountCustomer;
	// for transaction history 
	int transferCount = 0;

	double totalWitdrawl=0;
	double totalDeposits=0;
	double totaltransfers = 0;
	
	vector<double> transferAmmounts(50,0);
	vector<double> depositAmmounts(50, 0);
	vector<double> withdrawlAmmounts(50, 0);
	 


public:
	Account();
	Account(Customer* _accountCustomer, int _id, double _balance );
	void setAll(Customer* _accountCustomer, int _id, double _balance);
	void setAccountCustomer(Customer* _accountCustomer);
	void setID(int _id);
	void setWithdrawlCounter(int _withDrawlCounter);
	void setDepositCounter(int _depositCounter);
	void setTransferCounter(int _transferCounter);
	void setBalance(double _balance);
	void setTotalTransfers(double _transferAmmount);
	double getTotalTransfers() const;
	void setTotaldeposits(double _depositAmmount);
	double getTotaldeposits() const;
	void setTotalWithdrawls(double _withdrawlAmmount);
	double getTotalWithdrawls() const;




	Customer* getAccountCustomer()const;
	int getID() const;
	int getWithdrawlCounter() const;
	int getDepositsCounter() const;
	int getTransferCounter() const;

	double getBalance() const;
	void depositMoney(double _ammount);
	void withdrawMoney(double _ammount);
	void printInfo();

	void settransferAmmounts(double _transferAmmount);
	double recieveTransferAmmount(int i);

	void setwithdrawlAmmounts(double _withdrawlAmmount);
	double recievewithdrawlAmmount(int i);

	void setDepositAmmounts(double _depositAmmount);
	double recieveDepositAmmount(int i);

	void displayAllTransactions();

	void displayDeposits();

	void displayWithdrawls();
	void displaytransfers();

};




#endif // !ACCOUNT

