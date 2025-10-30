#include "Account.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <iostream>
#include <string>
using namespace std;

class TransactionHistory:public SavingAccount,CheckingAccount
{
	//no instance variables at this time 
	
public:
	void DisplayTansactions()
	{
		cout << "Total Balance:" << SavingAccount::getBalance() << SavingAccount::getDepositsCounter();

	} //not sure may need to say balance for each account then depending on account type display the deatils for # of each type of transaction and the total balance of the transactions


};