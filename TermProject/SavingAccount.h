#pragma once
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account
{
private:
    double interestRate; 

public:
    SavingAccount();
    SavingAccount(int _id, double _balance, double _interestRate, Customer* _customerInfo);
    double getInterestRate() const;
    void setInterestRate(double _rate);
    void setAll(int _id, double _balance, double _interestRate, Customer* _customerInfo);
    void payInterest();
    void transfer(double _amount, SavingAccount& _destinationAccount);
};

#endif