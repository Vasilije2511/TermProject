#pragma once
#ifndef CHECKING_ACCOUNT
#define CHECKING_ACCOUNT
#include <string>
#include "Account.h"
using namespace std;

class CheckingAccount : public Account
{
	double overDraftLimit;
public:
	CheckingAccount();
	CheckingAccount(int _id, double _balance, double _overDraftLimit, Customer* _customerInfo);
	void setOverDraftLimit(double _overDraftLimit);
	double getOverDraftLimit()const;
	void setAll(int _id, double _balance, double _overDraftLimit, Customer* _customerInfo);
	void withdrawMoney(double _ammount);



};

#endif // !CHECKING_ACCOUNT
