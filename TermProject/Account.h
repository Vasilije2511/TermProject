#pragma once
#ifndef ACCOUNT
#define ACCOUNT
#include "Customer.h"
#include <vector>
using namespace std;

class Account
{
	int ID, withdrawlCounter=0, depositsCounter=0, transferCount = 0;
	double balance;
	Customer *accountCustomer;
	// for transaction history 
	

	
	int wDatecount = 0;
	int tDatecount = 0;
	int dDatecount = 0;
	vector<double> transferAmmounts;
	vector<double> depositAmmounts;
	vector<double> withdrawlAmmounts;
	vector<string> withdrawlDates;
	vector<string>transferDates;
	vector<string>depositDates;



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
	
	void setwithdrawlDates();
	void setTransferDates();
	void setdepositDates();
	string getTransferDates(int index);
	string getDepositDates(int index);
	string getWithdrawlDates(int index);





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

	void displaySavingTransactions();
	void displayCheckingTransactions();

	void displayDeposits();

	void displayWithdrawls();
	void displaytransfers();

};




#endif // !ACCOUNT

