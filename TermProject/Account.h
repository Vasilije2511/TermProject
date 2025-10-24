#pragma once
#ifndef ACCOUNT
#define ACCOUNT
#include "Customer.h"


class Account
{
	int ID, withdrawlCounter=0, depositsCounter=0;
	double balance;
	Customer *accountCustomer;

public:
	Account();
	Account(Customer* _accountCustomer, int _id, int _withdrawlCounter=0,int _depositsCounter=0, double _balance );
	void setAll(Customer* _accountCustomer, int _id, int _withdrawlCounter=0, int _depositsCounter=0, double _balance);
	void setAccountCustomer(Customer* _accountCustomer);
	void setID(int _id);
	void setWithdrawlCounter(int _withDrawlCounter);
	void setDepositCounter(int _depositCounter);
	void setBalance(double _balance);
	Customer* getAccountCustomer()const;
	int getID() const;
	int getWithdrawlCounter() const;
	int getDepositsCounter() const;
	double getBalance() const;
	void depositMoney(double _ammount);
	void withdrawMoney(double _ammount);
	void printInfo();




};




#endif // !ACCOUNT

