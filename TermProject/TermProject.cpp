#include<iostream>
#include<string>
#include "Account.h"
#include"Customer.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

void showNewUserMenu();
void showExistingUserMenu();


int main()
{
	vector<CheckingAccount> checkingAccounts;
	vector<SavingAccount> savingAccounts;
	vector<Customer> customers;	
	//vector<unique_ptr<Customer>>customers;
	int choice;
	int accountCounter = 1;
	char userType;
	bool flagIntialAccount = false;

	while (true)
	{
		// first we need to create an account upon first running the code if not we will get an error
		//check the flag to decide if we need to creat an initial account to avoid users enter n as the very first option
		if (flagIntialAccount == false)
		{
			showNewUserMenu();
			cout << "Select an option: " << endl;
			cin >> choice;
			while ((choice > 2 && choice != 7) || choice < 0)
			{
				cout << "Error processing request\n";
				showNewUserMenu();
				cout << "Select an option: " << endl;
				cin >> choice;
			}
			userType = 'y';
			flagIntialAccount = true;
		}
		else //if there was an inital account made then the user can pick to either be a new user or act as a returning one
		{
			cout << "Are you a new user? (y/n): ";
			cin >> userType;
			if (tolower(userType) == 'y')
			{
				showNewUserMenu();
				cout << "Select an option: " << endl;
				cin >> choice;
				while ((choice > 2 && choice != 7) || choice < 0)
				{
					cout << "Error processing request\n";
					showNewUserMenu();
					cout << "Select an option: " << endl;
					cin >> choice;
				}
			}
			else if (tolower(userType) == 'n')
			{
				string fname, lname;
				bool foundname = false;
				cout << "Enter customer details:" << endl;
				cout << "First Name: ";
				cin >> fname;
				cout << "Last Name: ";
				cin >> lname;
				for (int i = 0; i < customers.size(); i++)
				{
					if (customers[i].getFname() == fname && customers[i].getLname() == lname) {

						foundname = true;
					}
				}
				if (foundname == true)
				{
					showExistingUserMenu();
					cout << "Select an option: " << endl;
					cin >> choice;
				}
				else
					cout << "No existing user found\n";

			}
		}

		if (choice == 7) //breaks the while true loop to exit the program
			break;
		switch (choice)
		{
		case 1: // creating checking account
		{
			system("cls");
			cout << "  -----Creating checking account-----"<<endl;
			if (tolower(userType) == 'y') //i found the error here you had n instead of y so i fixed it 
			{
				// New user - create new customer and account
				string fname, lname, address, phone, email;
				double balance, overdraftLimit;

				cout << "Enter customer details:" << endl;
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

				Customer newCustomer(fname, lname, address, phone, email);
				customers.push_back(newCustomer);
				CheckingAccount newAccount(accountCounter++, balance, overdraftLimit, &customers.back());//back just gets last user form customers
				checkingAccounts.push_back(newAccount);

				cout << "Checking account created successfully! Account ID: " << accountCounter - 1 << endl;
				userType = 'n'; // Convert to existing user
				system("pause");
				system("cls");
			}
			else {

				system("cls");

				Customer* existingCustomer = nullptr;

				string fname, lname;
				cout << "Enter First Name: ";
				cin >> fname;
				cout << "Enter Last Name: ";
				cin >> lname;

				for (int i = 0; i < customers.size(); i++)
				{
					if (customers[i].getFname() == fname && customers[i].getLname() == lname) {
						existingCustomer = &customers[i];
						break;
					}
				}
				if (existingCustomer) {//so if it is nullptr still this wont execute
					// Create additional account for existing customer
					double balance, overdraftLimit;
					cout << "  -----Creating new checking account-----" << endl;

					cout << "Initial Balance for new account: ";
					cin >> balance;
					cout << "Overdraft Limit for new account: ";
					cin >> overdraftLimit;

					CheckingAccount newAccount(accountCounter++, balance, overdraftLimit, existingCustomer);
					checkingAccounts.push_back(newAccount);

					cout << "Additional checking account created successfully! Account ID: " << accountCounter - 1 << endl;
					cout << "Account linked to customer: " << existingCustomer->getFname() << " "
						<< existingCustomer->getLname() << endl;
				}
				else {
					cout << "Customer not found! Please try again or create a new customer profile." << endl;
				}
			}
			break;
		}
		case 2://create saving acc
		{
			if (tolower(userType) == 'y') {
				string fname, lname, address, phone, email;
				double balance, interestRate;

				cout << "Enter customer details:" << endl;
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

				Customer newCustomer(fname, lname, address, phone, email);
				customers.push_back(newCustomer);
				SavingAccount newAccount(accountCounter++, balance, interestRate, &customers.back());
				savingAccounts.push_back(newAccount);

				cout << "Saving account created successfully! Account ID: " << accountCounter - 1 << endl;
				userType = 'n';
			}
			else {
				string fname, lname;
				cout << "Enter first name: ";
				cin >> fname;
				cout << "Enter last name: ";
				cin >> lname;
				Customer* existingCustomer = nullptr;
				for (int i = 0; i < customers.size(); i++)
				{
					if (fname == customers[i].getFname() && lname == customers[i].getLname())
						existingCustomer = &customers[i];
				}
				if (existingCustomer) {
					double balance, interestRate;
					cout << "Initial Balance for new account: ";
					cin >> balance;
					cout << "Interest Rate (%): ";
					cin >> interestRate;
					SavingAccount newAccount(accountCounter++, balance, interestRate, existingCustomer);
					savingAccounts.push_back(newAccount);

					cout << "Additional savings account created successfully! Account ID: " << accountCounter - 1 << endl;
				}
				else {
					cout << "Customer not found! Please create a new account as a new user." << endl;
				}
			}
			break;

		}
		case 3://view account information
		{
			string fname, lname;
			cout << "Enter first name: ";
			cin >> fname;
			cout << "Enter last name: ";
			cin >> lname;
			bool found = false;
			cout << "Accounts for " << fname << " " << lname << ": " << endl;
			for (int i = 0; i < checkingAccounts.size(); i++)
			{
				if (checkingAccounts[i].getAccountCustomer()->getFname() == fname &&
					checkingAccounts[i].getAccountCustomer()->getLname() == lname) {
					cout << "_____________________________________________________________________________________________________________________\n";
					cout << "Checking Account Information:" << endl;
					cout << "Account ID: " << checkingAccounts[i].getID() << endl;
					cout << "Balance: $" << fixed << setprecision(2) << checkingAccounts[i].getBalance() << endl;
					cout << "Overdraft Limit: $" << checkingAccounts[i].getOverDraftLimit() << endl;
					checkingAccounts[i].getAccountCustomer()->printInfo();
					found = true;
				}
			}

			// Check savings accounts
			for (int i = 0; i < savingAccounts.size(); i++) {
				if (savingAccounts[i].getAccountCustomer()->getFname() == fname &&
					savingAccounts[i].getAccountCustomer()->getLname() == lname) {
					cout << "_____________________________________________________________________________________________________________________\n";

					cout << "Saving Account Information:" << endl;
					cout << "Account ID: " << savingAccounts[i].getID() << endl;
					cout << "Balance: $" << fixed << setprecision(2) << savingAccounts[i].getBalance() << endl;
					cout << "Interest Rate: " << savingAccounts[i].getInterestRate() << "%" << endl;
					savingAccounts[i].getAccountCustomer()->printInfo();
					found = true;
				}
			}

			if (!found) {
				cout << "No accounts found for this customer." << endl;
			}
			break;
		}
		case 4://modify acc
		{
			string fname, lname;
			cout << "Enter first name: ";
			cin >> fname;
			cout << "Enter last name: ";
			cin >> lname;
			bool found = false;
			for (int i = 0; i < customers.size(); i++)
			{
				if (fname == customers[i].getFname() && lname == customers[i].getLname())
				{
					string newAddress, newPhone, newEmail;
					cout << "Enter new address: ";
					cin.ignore();
					getline(cin, newAddress);
					cout << "Enter new phone: ";
					cin >> newPhone;
					cout << "Enter new email: ";
					cin >> newEmail;

					customers[i].setAll(fname, lname, newAddress, newPhone, newEmail);
					cout << "Customer information updated successfully!" << endl;
					found = true;
					break;
				}
			}

			if (!found) {
				cout << "Customer not found!" << endl;
			}
			break;
		}
		case 5: //delete acc
		{
			string fname, lname;
			int opt;

			cout << "Enter first name: ";
			cin >> fname;
			cout << "Enter last name: ";
			cin >> lname;
			bool found = false;
			cout << "Do you want to delete checking account(1), saving acount(2) or all of them(3)? " << endl;
			do {
				cout << "Enter your option (1 or 2 or 3): ";
				cin >> opt;
				if (opt == 1)
				{
					for (int i = 0; i < checkingAccounts.size(); i++)
					{
						if (checkingAccounts[i].getAccountCustomer()->getFname() == fname &&
							checkingAccounts[i].getAccountCustomer()->getLname() == lname) {
							checkingAccounts.erase(checkingAccounts.begin() + i);//this is erase function and it needs v.begin()+index
							cout << "Checking account deleted!" << endl;
							cout << "Do you want to delete saving acount(2) or exit (4)" << endl;
							cout << "Enter your option (2 or 4): ";
							cin >> opt;

						}
					}
				}
				else if (opt == 2)
					for (int i = 0; i < savingAccounts.size(); i++) {
						if (savingAccounts[i].getAccountCustomer()->getFname() == fname &&
							savingAccounts[i].getAccountCustomer()->getLname() == lname) {
							savingAccounts.erase(savingAccounts.begin() + i);
							cout << "Saving account deleted! " << endl;
							cout << "Do you want to delete checking account(1) or exit (4)" << endl;
							cout << "Enter your option (1 or 4): ";
							cin >> opt;
						}
					}
				else if (opt == 3)
				{

					for (int i = 0; i < checkingAccounts.size(); i++)
					{
						if (checkingAccounts[i].getAccountCustomer()->getFname() == fname &&
							checkingAccounts[i].getAccountCustomer()->getLname() == lname) {
							checkingAccounts.erase(checkingAccounts.begin() + i);
							cout << "Checking account deleted!" << endl;
						}
					}
					for (int i = 0; i < savingAccounts.size(); i++) {
						if (savingAccounts[i].getAccountCustomer()->getFname() == fname &&
							savingAccounts[i].getAccountCustomer()->getLname() == lname) {
							savingAccounts.erase(savingAccounts.begin() + i);
							cout << "Saving account deleted! " << endl;
						}
					}
					break; //need to exit the loop since all accounts are deleted
				}
			} while (opt < 4 && opt>0);
		}
		case 6: //transfer money
		{
			string fname, lname;
			cout << "Enter account owner's First Name: ";
			cin >> fname;
			cout << "Enter account owner's Last Name: ";
			cin >> lname;
		}
		return 0;
		}
	}
}

void showNewUserMenu() {
	cout << endl << "=== New User Menu ===" << endl;
	cout << "1: Create a checking account" << endl;
	cout << "2: Create a saving account" << endl;
	cout << "7: Exit Program" << endl;
}

void showExistingUserMenu() {
	cout << endl << "=== Banking System Menu ===" << endl;
	cout << "1: Create a checking account\n";
	cout << "2: Create a saving account\n";
	cout << "3: View account information\n";
	cout << "4: Modify Account\n";
	cout << "5: Delete an account\n";
	cout << "6: Transfer money between accounts\n";
	cout << "7: Exit Program\n";
}