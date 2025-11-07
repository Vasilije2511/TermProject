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
void displayAccountInfo(string fname, string lname, const vector<CheckingAccount>& checkingAccounts, const vector<SavingAccount>& savingAccounts);


int main()
{
	


	vector<CheckingAccount> checkingAccounts;
	vector<SavingAccount> savingAccounts;
	vector<Customer*> customers;
	//vector<unique_ptr<Customer>>customers;
	int choice;
	int accountCounter = 1;
	char userType;
	bool flagIntialAccount = false;
	string fname, lname, address, phone, email;
	double balance, overdraftLimit;
	int interestRate;


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
			system("cls");
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

				bool foundname = false;
				cout << "Enter customer details:" << endl;
				cout << "First Name: ";
				cin >> fname;
				cout << "Last Name: ";
				cin >> lname;
				for (int i = 0; i < customers.size(); i++)
				{
					if (customers[i]->getFname() == fname && customers[i]->getLname() == lname) {

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
			cout << "  -----Creating checking account-----" << endl;
			if (tolower(userType) == 'y') //i found the error here you had n instead of y so i fixed it 
			{
				// New user - create new customer and account

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
				
				Customer* newCustomer = new Customer(fname, lname, address, phone, email);
				//newCustomer.setAll(fname, lname, address, phone, email);
				//customers.push_back(newCustomer);
				customers.push_back(newCustomer);
				//newAccount.setAll(accountCounter, balance, overdraftLimit, &newCustomer);//back just gets last user form customers
				CheckingAccount* checkingAccount = new CheckingAccount(accountCounter++, balance, overdraftLimit, *&newCustomer);

				checkingAccounts.push_back(*checkingAccount);

				cout << "Checking account created successfully! Account ID: " << accountCounter - 1 << endl;
				userType = 'n'; // Convert to existing user
				system("pause");
				system("cls");
			}
			else {
				system("cls");
				Customer* existingCustomer = nullptr;

				/*string fname, lname;
				cout << "Enter First Name: ";
				cin >> fname;
				cout << "Enter Last Name: ";
				cin >> lname;*/

				for (int i = 0; i < customers.size(); i++) {
					if (customers[i]->getFname() == fname && customers[i]->getLname() == lname) {
						existingCustomer = customers[i];
						//cout << "Existing customer found!"<<endl<<endl;
						cout << "Customer Information:"<<endl;
						existingCustomer->printInfo();
						cout << "\nCreating new checking account for existing customer...\n";

						cout << "Initial Balance for new account: ";
						cin >> balance;
						cout << "Overdraft Limit for new account: ";
						cin >> overdraftLimit;

						CheckingAccount* checkingAccount = new CheckingAccount(accountCounter++, balance, overdraftLimit, existingCustomer);
						checkingAccounts.push_back(*checkingAccount);

						
						cout << "\nAdditional checking account created successfully!\n";
						cout << "Account ID: " << accountCounter - 1 << endl;
						system("pause");
						system("cls");
						break;
					}
				}
				if (existingCustomer == nullptr) {
					cout << "Customer not found! Please try again or create a new customer profile." << endl;
				}
			}
			break;
		}
		case 2://create saving acc
		{
			if (tolower(userType) == 'y') {


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

				Customer* newCustomer = new Customer(fname, lname, address, phone, email);
				customers.push_back(newCustomer);

				//customers.push_back(newCustomer);
				 //SavingAccount newAccount(accountCounter++, balance, interestRate, &customers.back());
				SavingAccount* savingsAccount = new SavingAccount(accountCounter++, balance, interestRate, *&newCustomer);
				savingAccounts.push_back(*savingsAccount);

				cout << "Saving account created successfully! Account ID: " << accountCounter - 1 << endl;
				userType = 'n';
				system("pause");
				system("cls");
			}
			else {
				/*string fname, lname;
				cout << "Enter first name: ";
				cin >> fname;
				cout << "Enter last name: ";
				cin >> lname;*/

				Customer* existingCustomer = nullptr;
				for (int i = 0; i < customers.size(); i++) {
					if (customers[i]->getFname() == fname && customers[i]->getLname() == lname) {
						existingCustomer = customers[i];
					//	cout << "\nExisting customer found!\n";
						cout << "Customer Information:\n";
						existingCustomer->printInfo();
						cout << "\nCreating new savings account for existing customer...\n";

						cout << "Initial Balance for new account: ";
						cin >> balance;
						cout << "Interest Rate (%): ";
						cin >> interestRate;

						SavingAccount* savingsAccount = new SavingAccount(accountCounter++, balance, interestRate, existingCustomer);
						savingAccounts.push_back(*savingsAccount);

						cout << "\nAdditional savings account created successfully!\n";
						cout << "Account ID: " << accountCounter - 1 << endl;
						system("pause");
						system("cls");
						break;
					}
				}
				if (existingCustomer == nullptr) {
					cout << "Customer not found! Please create a new account as a new user." << endl;
					system("pause");
					system("cls");
				}
			}
			break;

		}
		case 3://view account information
		{
			/*string fname, lname;
			cout << "Enter first name: ";
			cin >> fname;
			cout << "Enter last name: ";
			cin >> lname;*/
			int size = checkingAccounts.size();
			
			displayAccountInfo(fname, lname, checkingAccounts, savingAccounts, size);

			

			

			
			break;
		}
		case 4://modify acc    
		{
			/*string fname, lname;
			cout << "Enter first name: ";
			cin >> fname;
			cout << "Enter last name: ";
			cin >> lname;*/
			bool found = false;
			for (int i = 0; i < customers.size(); i++)
			{
				if (fname == customers[i]->getFname() && lname == customers[i]->getLname())
				{
					string newAddress, newPhone, newEmail;
					cout << "Enter new address: ";
					cin.ignore();
					getline(cin, newAddress);
					cout << "Enter new phone: ";
					cin >> newPhone;
					cout << "Enter new email: ";
					cin >> newEmail;
					customers[i]->setAll(fname,lname, newAddress, newPhone, newEmail);

					cout << "Customer information updated successfully!" << endl;
					found = true;
					system("pause");
					system("cls");
					break;
				}
			}

			if (!found) {
				cout << "Customer not found!" << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 5: //delete acc
		{
			int opt;

			displayAccountInfo(fname, lname, checkingAccounts, savingAccounts);
			cout << endl;

			if(checkingAccounts.size() == 0 && savingAccounts.size() == 0)
			{
				cout << "No accounts to delete for this customer." << endl;
				system("pause");
				system("cls");
				break;
			}	
			else if(checkingAccounts.size() == 0&& savingAccounts.size() > 0)
			{
				cout << "Only saving accounts available to delete." << endl;
				opt = 2; // Directly set to delete saving account
			}
			else if(savingAccounts.size() == 0&& checkingAccounts.size()>0)
			{
				cout << "Only checking accounts available to delete." << endl;
				opt = 1; // Directly set to delete checking account
			}
			else
			{
				cout << "error has occured"<<endl;
			}
			


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
					cout << "All accounts have been deleted!" << endl;
					system("pause");
					system("cls");
					break; //need to exit the loop since all accounts are deleted
				}
			} while (opt < 4 && opt>0);
		}
		case 6: //transfer money
		{
			int sourceAccountId, destAccountId;
			double transferAmount;
			bool accountsFound = false;

			// Display all accounts for the customer using existing function
			displayAccountInfo(fname, lname, checkingAccounts, savingAccounts, checkingAccounts.size());

			// Check if customer has at least one account
			for (int i = 0; i < checkingAccounts.size(); i++) {
				if (checkingAccounts[i].getAccountCustomer()->getFname() == fname &&
					checkingAccounts[i].getAccountCustomer()->getLname() == lname) {
					accountsFound = true;
					break;
				}
			}
			if (!accountsFound) {
				for (int i = 0; i < savingAccounts.size(); i++) {
					if (savingAccounts[i].getAccountCustomer()->getFname() == fname &&
						savingAccounts[i].getAccountCustomer()->getLname() == lname) {
						accountsFound = true;
						break;
					}
				}
			}
		}
		
		return 0;
		}
	}
}
void displayAccountInfo(string fname, string lname, const vector<CheckingAccount>& checkingAccounts, const vector<SavingAccount>& savingAccounts)
{

	bool found = false;
	cout << "Accounts for " << fname << " " << lname << ": " << endl;
	for (int i = 0; i < checkingAccounts.size() + savingAccounts.size(); i++)
	{
		

		if (i < checkingAccounts.size() && checkingAccounts[i].getAccountCustomer()->getFname() == fname &&
			checkingAccounts[i].getAccountCustomer()->getLname() == lname) {
			if (!found)
			{
				checkingAccounts[i].getAccountCustomer()->printInfo();
				found = true;
			}
			cout << "_____________________________________________________________________________________________________________________\n";
			cout << "Checking Account Information:" << endl;
			cout << left<<setw(15) << "Account ID: " << setw(5) << checkingAccounts[i].getID() << setw(10);
			cout << "Balance: $" << fixed << setprecision(2) <<left<<setw(10) << checkingAccounts[i].getBalance() << setw(17);
			cout << "Overdraft Limit: $" <<left<< setw(5) << checkingAccounts[i].getOverDraftLimit() << endl;

		}
		if (i < savingAccounts.size() && savingAccounts[i].getAccountCustomer()->getFname() == fname &&
			savingAccounts[i].getAccountCustomer()->getLname() == lname)
		{
			cout << "_____________________________________________________________________________________________________________________\n";
			if (!found)
			{
				savingAccounts[i].getAccountCustomer()->printInfo();
				found = true;
			}
			cout << "Saving Account Information:" << endl;
			cout <<left<< setw(15) << "Account ID: "<< left<< setw(5) << savingAccounts[i].getID() << setw(10);
			cout << "Balance: $" << fixed << setprecision(2) << left<<setw(10) << savingAccounts[i].getBalance() << setw(17);
			cout << "Interest Rate: " << left<<setw(5) << savingAccounts[i].getInterestRate() << "%" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "No accounts found for this customer." << endl;
	}
}


void showNewUserMenu() 
{
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