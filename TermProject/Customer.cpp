#include "Account.h"
#include<string>
#include <iomanip>
#include <iostream>
using namespace std;

	Customer::Customer()
	{
		fname = "";
		lname = "";
		address = "";
		phone = "";
		email = "";
	}
	Customer::Customer(string _fname, string _lname, string _address, string _phone, string _email)
	{
		setAll(_fname, _lname, _address, _phone, _email);
	}
	void Customer:: setFname(string _fname) //maybe find a way to validate the strings
	{
		fname = _fname;
	}
	void Customer::setLname(string _lname)
	{
		lname = _lname;

	}
	void Customer::setAddress(string _address)
	{
		address + _address;

	}
	void Customer::setPhone(string _phone)
	{
		phone = _phone;
	}
	void Customer::setemail(string _email)
	{
		email = _email;
	}
	string Customer::getFname() const
	{
		return fname;
	}
	string Customer::getLname() const
	{
		return lname;
	}
	string Customer::getAddress() const
	{
		return address;
	}
	string Customer::getPhone() const
	{
		return phone;
	}
	string Customer::getEmail() const
	{
		return email;
	}
	void Customer::setAll(string _fname, string _lname, string _address, string _phone, string _email)
	{
		fname = _fname;
		lname = _lname;
		address = _address;
		phone = _phone;
		email = _email;
	}
	void Customer:: printInfo()
	{

		cout << setw(15) << "First Name:" << setw(15) << "Last Name" << setw(25) << "Address" << setw(25) << "Phone #" << setw(25) << "Email" << endl;
		cout << setw(15) << fname << setw(15) << lname << setw(25) << address << setw(25) << phone << setw(25) << email<<endl;
	}

