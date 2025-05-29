#pragma once

#include <iostream>
#include <string>
using namespace std;

const unsigned MIN_CODE = 1000, MAX_CODE = 9999;
const int CREDIT_LIMIT = -6000;
const unsigned MAX_WITHDRAWL = 2500, MAX_DEPOSIT = 10000;

extern const char* ACC_NUM_EX;     
extern const char* ACC_CODE_EX;     
extern const char* EMAIL_AT_EX;       
extern const char* DOMAIN_EX;    
extern const char* WITHDRAW_LIMIT_EX;
extern const char* DEPOSIT_LIMIT_EX;
extern const char* CREDIT_LIMIT_EX;

class Account
{
private:
    int accountNumber;
    int code;
    float balance;
    string email;

    // Static summaries
    static unsigned sumWithdraw;
    static unsigned sumDeposit;

public:
    // Default ctor
    Account() : accountNumber(0), code(0), balance(0.0), email("") {}
    // Assignment ctor
    Account(int, int, float, string);
    // Copy ctor
    Account(const Account&);
    // Move ctor
    Account(Account&&);

    // Methods
    // Getters
    unsigned getAccountNumber() const  { return this->accountNumber; }
    unsigned getCode() const    { return this->code;          }
    float    getBalance() const { return this->balance;       }
    string   getEmail() const   { return this->email;         }

    // Function to withdraw money from account
    void  withdraw(const int&);
    // Function to deposit money to account
    void deposit(const int&);

    // Getters for static withdrawls and deposits summaries
    static unsigned getSumWithdraw() { return sumWithdraw; }
    static unsigned getSumDeposit()  { return sumDeposit;  }


    // Input >> operator
    friend istream& operator>>(istream&, Account&);
};