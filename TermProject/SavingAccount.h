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
    SavingAccount(int id, double balance, double interestRate, Customer* customerInfo);
    double getInterestRate() const;
    void setInterestRate(double rate);
    void setAll(int id, double balance, double interestRate, Customer* customerInfo);
    void payInterest();
    void transfer(double amount, SavingAccount& destinationAccount);
};

#endif