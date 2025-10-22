#pragma once
#ifndef ACCOUNT
#define ACCOUNT
#include <string>
using namespace std;

class Customer
{
	string fname, lname, address, phone, email;
public:
	Customer();
	Customer(string _fname, string _lname, string _address, string _phone, string _email);
	void setFname(string _fname);
	void setLname(string _lname);
	void setAddress(string _address);
	void setPhone(string _phone);
	void setemail(string _email);
	string getFname() const;
	string getLname() const;
	string getAddress() const;
	string getPhone() const;
	string getEmail() const;
	void setAll(string _fname, string _lname, string _address, string _phone, string _email);
	void printInfo();
	
};

class Account
{
	int ID, withdrawlCounter=0, depositsCounter=0;
	double balance;
	Customer *accountCustomer;

public:
	Account();
	Account(Customer* _accountCustomer, int _id, int _withdrawlCounter,int _depositsCounter, double _balance );
	void setAll(Customer* _accountCustomer, int _id, int _withdrawlCounter, int _depositsCounter, double _balance);
	void setAccountCustomer(Customer* _accountCustomer);
	void setID(int _id);
	void setWithdrawlCounter(int _withDrawlCounter);
	void setDepositCounter(int _depositCounter);
	void setBalance(double _balance);
	Customer* getAccountCustomer()const;
	int getID() const;
	int getWithdrawlCounter() const;
	int getDepositsCounter() const;
	double setBalance() const;




};




#endif // !ACCOUNT

