
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
	//yes
};
