#pragma once

#include <iostream>
#include <string>
using namespace std;

const unsigned MIN_CODE = 1000, MAX_CODE = 9999;
const int CREDIT_LIMIT = -600;
const unsigned MAX_WITHDRAWL = 2500, MAX_DEPOSIT = 10000;

const char* ACC_NUM_EX        = "ERROR: account number must be positive";
const char* ACC_CODE_EX       = "ERROR: code must be of 4 digits";
const char* EMAIL_AT_EX       = "ERROR: email must contain @";
const char* DOMAIN_EX         = "ERROR: email must end with .com or .co.il";
const char* WITHDRAW_LIMIT_EX = "ERROR: cannot withdraw more than 2500 NIS";
const char* DEPOSIT_LIMIT_EX  = "ERROR: cannot deposit more than 10000 NIS";
const char* CREDIT_LIMIT_EX   = "ERROR: cannot have less than 6000 NIS";

class Account
{
public:
    // Default ctor
    Account() : accountNumber(0), code(0), balance(0.0), email("") {}
    // Assignment ctor
    Account(int, int, float, string);

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

    // Getters for static withdrawls and deposits counters
    static unsigned getSumWithdraw() { return sumWithdraw; }
    static unsigned getSumDeposit()  { return sumDeposit;  }


    // Input >> operator
    friend istream& operator>>(istream&, Account&);

private:
    unsigned accountNumber;
    unsigned code;
    float balance;
    string email;

    // Static counters
    static unsigned sumWithdraw;
    static unsigned sumDeposit;
};