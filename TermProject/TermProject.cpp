#include<iostream>
#include<string>
#include "Account.h"
#include"Customer.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <vector>
#include <iomanip>
using namespace std;



int main()
{
	vector<CheckingAccount*> checkingAccounts;
	vector<SavingAccount*> savingAccounts;
	int choice;
	int accountCounter = 1;

	cout << "1: creating a checking account\n2: create a saving account\n3: view account information\n4: Modify Account \n5: Delete an account\n6: transferring money between accounts\n7: Exit Program";
	cout << "Select an option: ";
	cin >> choice;
	while (choice != 7)
	{
		switch (choice)//create a checking account
		{
		case 1:
		{

			string fname, lname, address, phone, email;
			double balance, overdraftLimit;

			cout << "Enter customer details:"<<endl;
			cout << "First Name: ";
			cin >> fname;
			cout << "Last Name: ";
			cin >> lname;
			cout << "Address: ";
			cin.ignore();
			getline(cin, address);
			cout << "Phone: ";
			cin >> phone;
			cout << "Email: ";
			cin >> email;
			cout << "Initial Balance: ";
			cin >> balance;
			cout << "Overdraft Limit: ";
			cin >> overdraftLimit;

			Customer* newCustomer = new Customer(fname, lname, address, phone, email);
			CheckingAccount* newAccount = new CheckingAccount(accountCounter++, balance, overdraftLimit, newCustomer);
			checkingAccounts.push_back(newAccount);

			cout << "Checking account created successfully! Account ID: " << accountCounter - 1 << endl;
			break;
		}
		case 2: //create a saving account
		{

			string fname, lname, address, phone, email;
			double balance, interestRate;

			cout << "Enter customer details:"<<endl;
			cout << "First Name: ";
			cin >> fname;
			cout << "Last Name: ";
			cin >> lname;
			cout << "Address: ";
			cin.ignore();
			getline(cin, address);
			cout << "Phone: ";
			cin >> phone;
			cout << "Email: ";
			cin >> email;
			cout << "Initial Balance: ";
			cin >> balance;
			cout << "Interest Rate (%): ";
			cin >> interestRate;

			Customer* newCustomer = new Customer(fname, lname, address, phone, email);
			SavingAccount* newAccount = new SavingAccount(accountCounter++, balance, interestRate, newCustomer);
			savingAccounts.push_back(newAccount);

			cout << "Saving account created successfully! Account ID: " << accountCounter - 1 << endl;
			break;
		}

		case 3: //view account information
		{
			int accountId;
			cout << "\nEnter account ID: ";
			cin >> accountId;

			bool found = false;
			for (int i = 0; i < checkingAccounts.size(); i++) {
				if (checkingAccounts[i]->getID() == accountId) {
					cout << "Checking Account Information:"<<endl;
					cout << "Account ID: " << checkingAccounts[i]->getID() << endl;
					cout << "Balance: $" << fixed << setprecision(2) << checkingAccounts[i]->getBalance() << endl;
					cout << "Overdraft Limit: $" << checkingAccounts[i]->getOverDraftLimit() << endl;
					checkingAccounts[i]->getAccountCustomer()->printInfo();
					found = true;
					break;
				}
			}

			if (!found) {
				for (int i = 0; i < savingAccounts.size(); i++) {
					if (savingAccounts[i]->getID() == accountId) {
						cout << "Saving Account Information:"<<endl;
						cout << "Account ID: " << savingAccounts[i]->getID() << endl;
						cout << "Balance: $" << fixed << setprecision(2) << savingAccounts[i]->getBalance() << endl;
						cout << "Interest Rate: " << savingAccounts[i]->getInterestRate() << "%" << endl;
						savingAccounts[i]->getAccountCustomer()->printInfo();
						found = true;
						break;
					}
				}
			}

			if (!found) {
				cout << "Account not found!"<<endl;
			}
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
