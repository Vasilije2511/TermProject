#pragma once
#ifndef CUSTOMER
#define CUSTOMER
#include <string>
class Customer
{
	string fname, lname, address, phone, email;
public:
	Customer();
	Customer(string _fname, string _lname, string _address, string _phone, string _email);
	void setFname(string _fname);
	void setLname(string _lname);
	void setAddress(string _address);
	void setPhone(string _phone);
	void setemail(string _email);
	string getFname() const;
	string getLname() const;
	string getAddress() const;
	string getPhone() const;
	string getEmail() const;
	void setAll(string _fname, string _lname, string _address, string _phone, string _email);
	void printInfo();

};

#endif
