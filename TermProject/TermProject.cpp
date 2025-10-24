#include<iostream>
#include<string>
#include "Account.h"
#include"Customer.h"
#include "CheckingAccount.h"
using namespace std;



int main()
{
	int choice;
	CheckingAccount s1;

	cout << "1: creating a checking account\n2: create a saving account\n3: view account information\n4: Modify Account \n5: Delete an account\n6: transferring money between accounts\n7: Exit Program";
	cout << "Select an option: ";
	cin >> choice;
	while (choice != 7)
	{
		switch (choice)//create a checking account
		{
		case 1:
		{
			
			break;
		}
		case 2: //create a saving account
		{
			break;
		}

		case 3: //view account information
		{
			break;
		}
		case 4: //Modify Account
		{
			break;
		}
		case 5://Delete an account
		{

			break;
		}
		case 6://transferring money between accounts
		{

			break;
		}

		}

		cout << "1: creating a checking account\n2: create a saving account\n3: view account information\n4: Modify Account \n5: Delete an account\n6: transferring money between accounts\n7: Exit Program";
		cout << "Select an option: ";
		cin >> choice;
	}

	return 0;
}
