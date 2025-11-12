#include "CheckingAccount.h"
#include<cmath>
#include <iostream>
#include <string>
using namespace std;


CheckingAccount::CheckingAccount(): Account()
{
	overDraftLimit = 0;
}

CheckingAccount::CheckingAccount(int _id, double _balance, double _overDraftLimit, Customer* _customerInfo) :Account(_customerInfo, _id, _balance)
{
	setOverDraftLimit(_overDraftLimit);
}

void CheckingAccount::setAll(int _id, double _balance, double _overDraftLimit, Customer* _customerInfo)
{
	setOverDraftLimit(_overDraftLimit);
	Account::setAll(_customerInfo, _id, _balance);
}

void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
{
	if (_overDraftLimit > 0)
		overDraftLimit = _overDraftLimit;
	else
	{
		overDraftLimit = 0;
	}
}
double CheckingAccount::getOverDraftLimit()const
{
	return overDraftLimit;

}
void CheckingAccount::withdrawMoney(double _wAmmount)
{
	if (_wAmmount > 0)
	{
		if ( getBalance() >= _wAmmount)
		{
			double newbal = getBalance() - _wAmmount;
			setBalance(newbal);
			setWithdrawlCounter(1);
			setwithdrawlAmmounts(_wAmmount);
		}
		else
		{
			if (abs(getBalance() - _wAmmount) <= overDraftLimit)
			{
				double newbal = getBalance() - _wAmmount - 20;
				setBalance(newbal);
				setWithdrawlCounter(1);
				setwithdrawlAmmounts(_wAmmount);
				setOverDraftLimit(_wAmmount - overDraftLimit);
			}
			else
			{
				cout << "Cannot allow withdrawl. Overdraft limit exceeded" << endl;
			}
		}
	}
}
