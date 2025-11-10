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

//Admin username: admin
// Admin password: admin123


// Function declarations
void customerPortal();
void adminPortal();
int findCheckingAccount(const vector<CheckingAccount>& accounts, int id);
int findSavingAccount(const vector<SavingAccount>& accounts, int id);
int findCustomer(const vector<Customer>& customers, string fname, string lname);
void createAccount(int customerIndex);

// Global variables
vector<CheckingAccount> checkingAccounts;
vector<SavingAccount> savingAccounts;
vector<Customer> customers;
int nextAccountId = 1000;

int main() {
    int mainChoice;
    customers.reserve(1000);


    do { //display menu an introduction
        system("cls");

        cout << "+===========================================================+" << endl;
        cout << "+                    Bank Information                       +" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ Nicole & Vasilije Savings was established in 2025.        +" << endl;
        cout << "+ Our mission is to provide secure and easy banking         +" << endl;
        cout << "+ for everyone.                                             +" << endl;
        cout << "+===========================================================+" << endl;


        system("pause");
        system("cls");

        cout << "+===========================================================+" << endl;
        cout << "+            Welcome to Bank - Main Menu                    +" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ Press 1 - For Customer Portal                             +" << endl;
        cout << "+ Press 2 - For Administrator Portal                        +" << endl;
        cout << "+ Press 3 - Exit the Banking System                         +" << endl;
        cout << "+===========================================================+" << endl;
        cout << "Enter an option: ";
        cin >> mainChoice;
		while (mainChoice != 1 && mainChoice != 2 && mainChoice != 3) //error handling for invalid menu option
        {
			system("cls");
            cin.clear();
            cin.ignore();
            cout << "+===========================================================+" << endl;
            cout << "+                       Error                               +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Invalid option. Please try again.                         +" << endl;
            cout << "+===========================================================+" << endl;

            system("pause");
            system("cls");
            cout << "+===========================================================+" << endl;
            cout << "+            Welcome to Bank - Main Menu                    +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Press 1 - For Customer Portal                             +" << endl;
            cout << "+ Press 2 - For Administrator Portal                        +" << endl;
            cout << "+ Press 3 - Exit the Banking System                         +" << endl;
            cout << "+===========================================================+" << endl;

            cout << "Enter an option: ";
            cin >> mainChoice;
        }

        system("cls");
        switch (mainChoice) {
        case 1://Press 1 - For Customer Portal 
            customerPortal();
            break;
        case 2: 
            //Press 2 - For Administrator Portal 
        {
			string adminUser, adminPass;
			cout << "+===========================================================+" << endl;
			cout << "+                Administrator Login                        +" << endl;
			cout << "+-----------------------------------------------------------+" << endl;
			cout << "Enter Admin Username: ";
			cin >> adminUser;
			cout << "Enter Admin Password: ";
			cin >> adminPass;
			if (adminUser != "admin" || adminPass != "admin123") 
			{
                system("cls");
				cout << "+===========================================================+" << endl;
				cout << "+                       Error                               +" << endl;
				cout << "+-----------------------------------------------------------+" << endl;
				cout << "+ Invalid admin credentials!                                +" << endl;
				cout << "+===========================================================+" << endl;
				system("pause");
				break;
			}
        adminPortal();
            break;

        }
           
		case 3: //Press 3 - Exit the Banking System
            cout << "+===========================================================+" << endl;
            cout << "+                System Exit                                +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Thank you for using our banking system. Goodbye!          +" << endl;
            cout << "+===========================================================+" << endl;
            system("pause");
            break;
        
        }
    } while (mainChoice != 3);

    return 0;
}

void createAccount(int customerIndex)
{
    int accountType;
    double initialBalance;
    system("cls");
    cout << "+===========================================================+" << endl;
    cout << "+                   Create New Account                      +" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "+ Select Account Type:                                      +" << endl;
    cout << "+ 1 - Checking Account                                      +" << endl;
    cout << "+ 2 - Savings Account                                       +" << endl;
    cout << "+ 3 - Quit                                                  +" << endl;
    cout << "+===========================================================+" << endl;
    cout << "Enter choice: ";
    cin >> accountType;


    while ((accountType != 1 && accountType != 2 && accountType != 3) )
    {
        system("cls");
        cin.clear();
        cin.ignore();
        cout << "+===========================================================+" << endl;
        cout << "+                       Error                               +" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ Invalid account type selected please re-enter information +" << endl;
        cout << "+ or 3 to quit!                                             +" << endl;
        cout << "+===========================================================+" << endl;
        system("pause"); //display menu again to the user and option to quit;
        system("cls");
        cout << "+===========================================================+" << endl;
        cout << "+                   Create New Account                      +" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ Select Account Type:                                      +" << endl;
        cout << "+ 1 - Checking Account                                      +" << endl;
        cout << "+ 2 - Savings Account                                       +" << endl;
        cout << "+ 3 - Quit                                                  +" << endl;
        cout << "+===========================================================+" << endl;
        cout << "Enter choice: ";
        cin >> accountType;
        if (accountType == 3)
        {
            return;
        }
    }

    system("cls");
    cout << "+===========================================================+" << endl;
    cout << "+                   Account Creation                        +" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "Enter initial balance: $";
    cin >> initialBalance;
    while (initialBalance < 0 ||cin.fail())
    {
        cin.clear();
        cin.ignore();
        system("cls");

        cout << "+===========================================================+" << endl;
        cout << "+                       Error                               +" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ Invalid ammount entered please re-enter initial balance   +" << endl;
        cout << "+ or 0 to quit                                           +" << endl;
        cout << "+===========================================================+" << endl;
        cout << "Enter initial balance: $";
        cin >> initialBalance;
        if (initialBalance == 0)
        {
            return;
        }

    }
    if (accountType == 1)
    {
        double overdraftLimit;
        cout << "Enter overdraft limit: $";
        cin >> overdraftLimit;
        while (overdraftLimit < 0||cin.fail())
        {
            cin.clear();
            cin.ignore();
            system("cls");

            cout << "+===========================================================+" << endl;
            cout << "+                       Error                               +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Invalid ammount entered please re-enter overdraft limit   +" << endl;
            cout << "+ or 0 to quit                                           +" << endl;
            cout << "+===========================================================+" << endl;
            cout << "Enter overdraft limit: $";
            cin >> overdraftLimit;
            if (overdraftLimit == 0)
            {
                return;
            }

        }
        CheckingAccount newAccount(nextAccountId, initialBalance, overdraftLimit, &customers[customerIndex]);
        checkingAccounts.push_back(newAccount);
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ Checking Account created successfully!                    +" << endl;
        cout << "+ Your Account ID is: " << nextAccountId << "               +" << endl;
        cout << "+===========================================================+" << endl;
        nextAccountId++;
    }
    else if (accountType == 2)
    {
        double interestRate;
        cout << "Enter interest rate: ";
        cin >> interestRate;
        while (interestRate < 0 || interestRate>100 ||cin.fail())
        {
            system("cls");
            cin.clear();
            cin.ignore();
            cout << "+===========================================================+" << endl;
            cout << "+                       Error                               +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Invalid ammount entered please re-enter interest rate     +" << endl;
            cout << "+ or 0 to quit                                              +" << endl;
            cout << "+===========================================================+" << endl;
            cout << "Enter interest rate: ";
            cin >> interestRate;
            if (interestRate == 0)
            {
                return;
            }

        }

        SavingAccount newAccount(nextAccountId, initialBalance, interestRate, &customers[customerIndex]);
        savingAccounts.push_back(newAccount);
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ Savings Account created successfully!                      +" << endl;
        cout << "+ Your Account ID is: " << nextAccountId << "                               +" << endl;
        cout << "+===========================================================+" << endl;
        nextAccountId++;
    }
    system("pause");
}

void customerPortal() 
{
    int choice;
    do {
        system("cls");
        cout << "+===========================================================+" << endl;
        cout << "+                     Customer Portal                       +" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ 1 - Open a New Account                                    +" << endl;
        cout << "+ 2 - Access an Existing Account                            +" << endl;
        cout << "+ 3 - Return to Main Menu                                   +" << endl;
        cout << "+===========================================================+" << endl;
        cout << "Enter an option: ";
        cin >> choice;

     

        while (choice != 1 && choice != 2 && choice != 3) //error handling for invalid menu option
        {
            system("cls");
            cin.clear();
            cin.ignore();
            cout << "+===========================================================+" << endl;
            cout << "+                       Error                               +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Invalid option. Please try again.                         +" << endl;
            cout << "+===========================================================+" << endl;
            system("pause");

            system("cls");

            cout << "+===========================================================+" << endl;
            cout << "+                     Customer Portal                       +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ 1 - Open a New Account                                    +" << endl;
            cout << "+ 2 - Access an Existing Account                            +" << endl;
            cout << "+ 3 - Return to Main Menu                                   +" << endl;
            cout << "+===========================================================+" << endl;
            cout << "Enter an option: ";
            cin >> choice;
        }

        system("cls");
        switch (choice)
        {
		case 1: //Open a New Account
        {
            string fname, lname, address, phone, email;
            int customerIndex;
            cout << "+===========================================================+" << endl;
            cout << "+                  New Account Creation                     +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Enter customer details:                                   +" << endl;
            cout << "+===========================================================+" << endl;

            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";
            cin >> lname;

            customerIndex = findCustomer(customers, fname, lname);
            if (customerIndex != -1)
            {
                cout << "+===========================================================+" << endl;
                cout << "+                 Existing Customer Found                   +" << endl;
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Name: " << fname << " " << lname << endl;
                cout << "+===========================================================+" << endl;
                system("pause");
                createAccount(customerIndex);
            }
            else
            {
                cin.ignore();
                cout << "Address: ";
                getline(cin, address);
                cout << "Phone: ";
                getline(cin, phone);
                cout << "Email: ";
                getline(cin, email);

                Customer newCustomer(fname, lname, address, phone, email);
                customers.push_back(newCustomer);
                createAccount(customers.size() - 1);
            }
            break;
        }
		case 2: //Access an Existing Account
        {
            int accountId;
            int checkingIndex;
            int savingIndex;
            int subChoice;

            cout << "+===========================================================+" << endl;
            cout << "+                   Account Access                          +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "Enter your Account ID: ";
            cin >> accountId;

            checkingIndex = findCheckingAccount(checkingAccounts, accountId);
            savingIndex = findSavingAccount(savingAccounts, accountId);

            while (checkingIndex == -1 && savingIndex == -1)
            {
                system("cls");
                cout << "+===========================================================+" << endl;
                cout << "+                       Error                               +" << endl;
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Account not found!                                        +" << endl;
                cout << "+===========================================================+" << endl;

                system("pause");
                system("cls");
                cout << "+===========================================================+" << endl;
                cout << "+                   Account Access                          +" << endl;
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "Enter your Account ID or 0 to quit: ";
                cin >> accountId;
                if (accountId == 0)
                {
                    return;
                }
                checkingIndex = findCheckingAccount(checkingAccounts, accountId);
                savingIndex = findSavingAccount(savingAccounts, accountId);


            }
            

            do
            {
                system("cls");
                cout << "+===========================================================+" << endl;
                cout << "+            Customer Portal -  Existing Account Menu       +" << endl;
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ 1 - View Balance                                          +" << endl;
                cout << "+ 2 - Deposit Money                                         +" << endl;
                cout << "+ 3 - Withdraw Money                                        +" << endl;
                cout << "+ 4 - View Transaction History                              +" << endl;
                cout << "+ 5 - Return to Customer Portal                             +" << endl;
                cout << "+===========================================================+" << endl;
                cout << "Enter an option: ";
                cin >> subChoice;

                while (subChoice != 1 && subChoice != 2 && subChoice != 3 && subChoice != 4 && subChoice != 5 ||cin.fail()) //error handling for invalid menu option
                {
                    system("cls");
                    cin.clear();
                    cin.ignore();
                    cout << "+===========================================================+" << endl;
                    cout << "+                       Error                               +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
                    cout << "+ Invalid option. Please try again.                         +" << endl;
                    cout << "+===========================================================+" << endl;
                    system("pause");
                    system("cls");

                    cout << "+===========================================================+" << endl;
                    cout << "+            Customer Portal - Account Menu                 +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
                    cout << "+ 1 - View Balance                                          +" << endl;
                    cout << "+ 2 - Deposit Money                                         +" << endl;
                    cout << "+ 3 - Withdraw Money                                        +" << endl;
                    cout << "+ 4 - View Transaction History                              +" << endl;
                    cout << "+ 5 - Return to Customer Portal                             +" << endl;
                    cout << "+===========================================================+" << endl;
                    cout << "Enter an option: ";
                    cin >> subChoice;

                }

                system("cls");
                switch (subChoice) {
                case 1: {
                    cout << "+===========================================================+" << endl;
                    cout << "+                   Account Balance                         +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
                    if (checkingIndex != -1)
                    {
                        cout << "+ Checking Account Balance: $" << fixed << setprecision(2)
                            << checkingAccounts[checkingIndex].getBalance() << endl;
                    }
                    else if (savingIndex != -1)
                    {
                        cout << "+ Savings Account Balance: $" << fixed << setprecision(2)
                            << savingAccounts[savingIndex].getBalance() << endl;
                    }
                    else
                    {
                        cout << "+===========================================================+" << endl;
                        cout << "+                       Error                               +" << endl;
                        cout << "+-----------------------------------------------------------+" << endl;
                        cout << "+ Account not found!                                        +" << endl;
                        cout << "+===========================================================+" << endl;
                        return;
                    }
                    cout << "+===========================================================+" << endl;
                    system("pause");
                    break;
                }
                case 2:
                {
                    double amount;
                    system("cls");
                    cout << "+===========================================================+" << endl;
                    cout << "+                     Deposit Money                         +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
                    cout << "Enter amount to deposit: $";
					cin >> amount;  
                    while (amount <= 0)
                    {
                        cout << "+===========================================================+" << endl;
                        cout << "+                       Error                               +" << endl;
                        cout << "+-----------------------------------------------------------+" << endl;
                        cout << "+ Invalid amount! Please re-enter amount to deposit         +" <<
                            "+ or 0 to quit                                              + " << endl;
                        cout << "+===========================================================+" << endl;
                        cout << "Enter amount to deposit: $";
                        cin >> amount;
                        if (amount == 0)
                        {
                            return;
                        }
                    }
                    if (amount > 0)
                    {
                        if (checkingIndex != -1)
                        {
                            checkingAccounts[checkingIndex].depositMoney(amount);
                        }
                        else if (savingIndex != -1)
                        {
                            savingAccounts[savingIndex].depositMoney(amount);
                        }
                        cout << "+-----------------------------------------------------------+" << endl;
                        cout << "+ Deposit successful!                                       +" << endl;
                        cout << "+===========================================================+" << endl;
                    }

                    system("pause");
                    break;
                } //ALSO NEED TO FIX if user enters someting that cuases cin to fail like a letter.
				case 3: //wothdraw money ***NEED TO FIX TO SHOWERROR IF INSUFFICIENT FUNDS and the over draft limit/fees
                {
                    double amount;
                    system("cls");
                    cout << "+===========================================================+" << endl;
                    cout << "+                    Withdraw Money                         +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
                    cout << "Enter amount to withdraw: $";
                    cin >> amount;

                    while (amount < 0)
                    {
                        cout << "+===========================================================+" << endl;
                        cout << "+                       Error                               +" << endl;
                        cout << "+-----------------------------------------------------------+" << endl;
                        cout << "+ Invalid amount! Please re-enter amount to withdraw        +" <<
                            "+ or 0 to quit                                              + " << endl;
                        cout << "+===========================================================+" << endl;
                        cout << "Enter amount to withdraw: $";
                        cin >> amount;
                        if (amount == 0)
                        {
                            return;
                        }
                    }
					if (amount > 0) //need to add check for sufficient funds and overdraft limit
                    {
                        if (checkingIndex != -1)
                        {
                            checkingAccounts[checkingIndex].withdrawMoney(amount);
                        }
                        else if (savingIndex != -1)
                        {
                            savingAccounts[savingIndex].withdrawMoney(amount);
                        }
                        cout << "+-----------------------------------------------------------+" << endl;
                        cout << "+ Withdrawal successful!                                    +" << endl;
                        cout << "+===========================================================+" << endl;
                    }

                    system("pause");
                    break;
                }
                case 4: //need to add the time stamps also need to ask user if they want to see a specific tansaction // dislay the individual info addresss 
                {
                    string fname;
					fname= customers[accountId].getFname();
                    string lname;
                    lname = customers[accountId].getLname();
                    system("cls");
                    cout << "+===========================================================+" << endl;
                    cout << "+                 Transaction History                       +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
					cout << "+  Transaction History for Account ID#: " << accountId<<"          +" << endl;
                    cout << "+ Name: " <<fname << " "<<lname  << endl;
                    cout << "+===========================================================+" << endl;

                    if (checkingIndex != -1)
                    {
                        checkingAccounts[checkingIndex].displayAllTransactions();
                        cout << "+===========================================================+" << endl;

                    }
                    else if (savingIndex != -1)
                    {
                        savingAccounts[savingIndex].displayAllTransactions();
                        cout << "+===========================================================+" << endl;

                    }
                    else
                    {
                        cout << "+===========================================================+" << endl;
                        cout << "+                       Error                               +" << endl;
                        cout << "+-----------------------------------------------------------+" << endl;
                        cout << "+ Account not found!                                        +" << endl;
                        cout << "+===========================================================+" << endl;
                        return;
                    }
                    system("pause");
                    break;
                }
                case 5:
                {
                    system("cls");
                    cout << "+===========================================================+" << endl;
                    cout << "+                 Returning to Portal                       +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
                    cout << "+ Thank you for using our services!                         +" << endl;
                    cout << "+===========================================================+" << endl;
                    system("pause");
                    break;
                }
                default:
                {
                    system("cls");
                    cout << "+===========================================================+" << endl;
                    cout << "+                       Error                               +" << endl;
                    cout << "+-----------------------------------------------------------+" << endl;
                    cout << "+ Invalid option!                                           +" << endl;
                    cout << "+===========================================================+" << endl;
                    system("pause");
                }
                }
            } while (subChoice != 5);
            break;
        }
        case 3: //Return to Main Menu
        {
            system("cls");
            cout << "+===========================================================+" << endl;
            cout << "+                 Returning to Main Menu                    +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Thank you for visiting our bank!                          +" << endl;
            cout << "+===========================================================+" << endl;
            system("pause");
            break;
        }
        default:
        {
            system("cls");
            cout << "+===========================================================+" << endl;
            cout << "+                       Error                               +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Invalid option. Please try again.                         +" << endl;
            cout << "+===========================================================+" << endl;
            system("pause");
        }
        }
    } while (choice != 3);
}





void adminPortal()
{
    int choice;
    do
    {
        system("cls");
        cout << "+===========================================================+" << endl;
        cout << "+                      Admin Portal                         +" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "+ 1 - Create an Account                                     +" << endl;
        cout << "+ 2 - Modify an Account                                     +" << endl;
        cout << "+ 3 - Delete an Account                                     +" << endl;
        cout << "+ 4 - List ALL Accounts                                     +" << endl;
        cout << "+ 5 - Look Up Account By ID#                                +" << endl;
        cout << "+ 6 - Add Interest to Account                               +" << endl;
        cout << "+ 7 - View Transaction History of Account                   +" << endl;
        cout << "+ 8 - Return to Main Menu                                   +" << endl;
        cout << "+===========================================================+" << endl;
        cout << "Enter an option: ";
        cin >> choice;

        system("cls");
        switch (choice)
        {
        case 1:

        {
            cout << "+===========================================================+" << endl;
            cout << "+                  Create New Account                       +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            string fname, lname;
            cout << "Enter customer first name: ";
            cin >> fname;
            cout << "Enter customer last name: ";
            cin >> lname;

            int customerIndex = findCustomer(customers, fname, lname);
            if (customerIndex != -1) {
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Existing customer found!                                  +" << endl;
                cout << "+===========================================================+" << endl;
                system("pause");
                createAccount(customerIndex);
            }
            else {
                string address, phone, email;
                cin.ignore();
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter email: ";
                getline(cin, email);

                Customer newCustomer(fname, lname, address, phone, email);
                customers.push_back(newCustomer);
                createAccount(customers.size() - 1);
            }
            break;
        }
        case 2:
        {
            cout << "+===========================================================+" << endl;
            cout << "+                   Modify Account                          +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "Enter Account ID: ";
            int accountId;
            cin >> accountId;

            int checkingIndex = findCheckingAccount(checkingAccounts, accountId);
            int savingIndex = findSavingAccount(savingAccounts, accountId);

            if (checkingIndex == -1 && savingIndex == -1) {
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Account not found!                                        +" << endl;
                cout << "+===========================================================+" << endl;
                system("pause");
                break;
            }

            if (checkingIndex != -1) 
            {
				string newfname, newlname, newaddress, newphone, newemail;
				cout << "Enter new first name: ";
				cin >> newfname;
				cout << "Enter new last name: ";
				cin >> newlname;
				cin.ignore();
				cout << "Enter new address: ";
				getline(cin, newaddress);
                cout << "Enter new phone: ";
				cin >> newphone;
				cout << "Enter new email: ";
				cin >> newemail;
				checkingAccounts[checkingIndex].getAccountCustomer()->setAll(newfname, newlname, newaddress, newphone, newemail);
            }
            else 
            {
				string newfname, newlname, newaddress, newphone, newemail;
				cout << "Enter new first name: ";
				cin >> newfname;
				cout << "Enter new last name: ";
				cin >> newlname;
				cin.ignore();
				cout << "Enter new address: ";
                getline(cin, newaddress);
				cout << "Enter new phone: ";
				cin >> newphone;
				cout << "Enter new email: ";
				cin >> newemail;
				savingAccounts[savingIndex].getAccountCustomer()->setAll(newfname, newlname, newaddress, newphone, newemail);
                    
            }
        }
        case 3:
        {
            cout << "+===========================================================+" << endl;
            cout << "+                   Delete Account                          +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "Enter Account ID: ";
            int accountId;
            cin >> accountId;

            int checkingIndex = findCheckingAccount(checkingAccounts, accountId);
            int savingIndex = findSavingAccount(savingAccounts, accountId);

            if (checkingIndex != -1) {
                checkingAccounts.erase(checkingAccounts.begin() + checkingIndex);
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Account deleted successfully!                             +" << endl;
                cout << "+===========================================================+" << endl;
            }
            else if (savingIndex != -1) {
                savingAccounts.erase(savingAccounts.begin() + savingIndex);
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Account deleted successfully!                             +" << endl;
                cout << "+===========================================================+" << endl;
            }
            else {
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Account not found!                                        +" << endl;
                cout << "+===========================================================+" << endl;
            }
            system("pause");
            break;
        }
        case 4:
        {
            cout << "+===========================================================+" << endl;
            cout << "+                    All Accounts                          +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "Checking Accounts:" << endl;
            for (int i = 0; i < checkingAccounts.size(); i++) {
                Customer* cust = checkingAccounts[i].getAccountCustomer();
                checkingAccounts[i].printInfo();
                cout << "Overdraft Limit: $" << checkingAccounts[i].getOverDraftLimit() << endl;
                cout << "-----------------------------------------------------------" << endl;
            }

            cout << "\nSavings Accounts:" << endl;
            for (int i = 0; i < savingAccounts.size(); i++) {
                Customer* cust = savingAccounts[i].getAccountCustomer();
                savingAccounts[i].printInfo();
                cout << "Interest Rate: " << (savingAccounts[i].getInterestRate() * 100) << "%" << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
            system("pause");
            break;
        }//
        case 5:
        {
            cout << "+===========================================================+" << endl;
            cout << "+                   Account Lookup                          +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "Enter Account ID: ";
            int accountId;
            cin >> accountId;

            int checkingIndex = findCheckingAccount(checkingAccounts, accountId);
            int savingIndex = findSavingAccount(savingAccounts, accountId);

            if (checkingIndex != -1) {
                checkingAccounts[checkingIndex].printInfo();
                cout << "Overdraft Limit: $" << checkingAccounts[checkingIndex].getOverDraftLimit() << endl;
            }
            else if (savingIndex != -1) {
                savingAccounts[savingIndex].printInfo();
                cout << "Interest Rate: " << (savingAccounts[savingIndex].getInterestRate() * 100) << "%" << endl;
            }
            else {
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Account not found!                                        +" << endl;
                cout << "+===========================================================+" << endl;
            }
            system("pause");
            break;
        }
        case 6:
        {
            cout << "+===========================================================+" << endl;
            cout << "+                   Add Interest                            +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "Enter Savings Account ID: ";
            int accountId;
            cin >> accountId;

            int savingIndex = findSavingAccount(savingAccounts, accountId);
            if (savingIndex != -1) {
                savingAccounts[savingIndex].payInterest();
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Interest added successfully!                              +" << endl;
                cout << "+===========================================================+" << endl;
            }
            else {
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Savings account not found!                                +" << endl;
                cout << "+===========================================================+" << endl;
            }
            system("pause");
            break;
        }
        case 7:
        {
            cout << "+===========================================================+" << endl;
            cout << "+               Transaction History                         +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "Enter Account ID: ";
            int accountId;
            cin >> accountId;

            int checkingIndex = findCheckingAccount(checkingAccounts, accountId);
            int savingIndex = findSavingAccount(savingAccounts, accountId);

            if (checkingIndex != -1) {
                checkingAccounts[checkingIndex].displayAllTransactions();
            }
            else if (savingIndex != -1) {
                savingAccounts[savingIndex].displayAllTransactions();
            }
            else {
                cout << "+-----------------------------------------------------------+" << endl;
                cout << "+ Account not found!                                        +" << endl;
                cout << "+===========================================================+" << endl;
            }
            system("pause");
            break;
        }
        case 8: {
            cout << "+===========================================================+" << endl;
            cout << "+              Returning to Main Menu                       +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Thank you for using the admin portal!                     +" << endl;
            cout << "+===========================================================+" << endl;
            system("pause");
            break;
        }
        default: {
            cout << "+===========================================================+" << endl;
            cout << "+                       Error                               +" << endl;
            cout << "+-----------------------------------------------------------+" << endl;
            cout << "+ Invalid option. Please try again.                         +" << endl;
            cout << "+===========================================================+" << endl;
            system("pause");
        }
        }
    } while (choice != 8);
}

int findCheckingAccount(const vector<CheckingAccount>& accounts, int id) //use the id to find the checking account
{
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getID() == id) {
            return i; //returns the id if found
        }
    }
    return -1; //returns -1 if not found
}

int findSavingAccount(const vector<SavingAccount>& accounts, int id)//use the id to find the saving account 
{
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].getID() == id)
        {
            return i;
        }
    }
    return -1;
}

int findCustomer(const vector<Customer>& customers, string fname, string lname) //uses the cuustomers name to find their account info
{
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getFname() == fname && customers[i].getLname() == lname)
        {
            return i; //returns the customer index 
        }
    }
    return -1; //if not found return -1
}