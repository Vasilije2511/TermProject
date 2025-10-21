#include<iostream>
#include<string>


using namespace std;

class Customer
{
	string fname, lname, address, phone, email;

public:
	void setFname(string _fname) //maybe find a way to validate the strings
	{
		fname = _fname;
	}
	void setLname(string _lname)
	{
		lname = _lname;

	}
	void setAddress(string _address)
	{
		address + _address;

	}
	void setPhone(string _phone)
	{
		phone = _phone;
	}
	void setemail(string _email)
	{
		email = _email;
	}
	string getFname() const
	{
		return fname;
	}
	string getLname() const
	{
		return lname;
	}
	string getAddress() const
	{
		return address;
	}
	string getPhone() const
	{
		return phone;
	}
	string getEmail() const
	{
		return email;
	}
	
	//did it work
};





int main()
{
	int choice;
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
