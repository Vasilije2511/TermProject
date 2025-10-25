#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <iostream>
#include <string>
using namespace std;

class TransactionHistory:public SavingAccount,CheckingAccount
{
	double totalWitdrawl;
	double totalDeposits;
	double totalTranfer;
public:

	TransactionHistory():SavingAccount(),CheckingAccount()
	{
		
	
	}
	TransactionHistory() :SavingAccount(), CheckingAccount()
	{

	}
};