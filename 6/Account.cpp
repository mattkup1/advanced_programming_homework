#include "Account.h"


// Initialize static counters
unsigned Account::sumWithdraw = 0;
unsigned Account::sumDeposit = 0;

Account::Account(int accNum, int code, float balance_, string email_)
{
    // Convert email to lower case
    unsigned len = email_.length();
    for (int i = 0; i < len; i ++)
        email_[i] = tolower(i);

    try
    {
        // Case invalid (negative) account number
        if (accNum < 0)
            throw ACC_NUM_EX;
        // Case invalid (not 4 digits) secret code
        if (code < MIN_CODE || code > MAX_CODE)
            throw ACC_CODE_EX;
        // Case email address missing "@"
        if (email_.find("@", 1) < 1)
            throw EMAIL_AT_EX;
        // Case invalid domain (not .com or .co.il)
        if (email_.find(".com", 2) < 1 || email_.find("co.il"))
            throw DOMAIN_EX;
    }
    // Case invalid input - Initialize all fields to default and raise exception
    catch(const char* error)
    {
        this->accountNumber = this->code = this->balance = 0;
        this->email = "";
        throw error;
    }
    

    // Case valid arguments, Assign to object fields.
    this->accountNumber = accNum;
    this->code = code;
    this->balance = balance_;
    this->email = email_;
}


// Input >> operator
istream& operator>>(istream& is, Account& acc)
{
    // Read account info from stream
    is >>  acc.accountNumber >> acc.code >> acc.email;

    try
    {
        if (acc.accountNumber < 0)
            throw ACC_NUM_EX;
        if (acc.code < MIN_CODE || acc.code > MAX_CODE)
            throw ACC_CODE_EX;
        if (acc.email.find("@", 1) < 1)
            throw EMAIL_AT_EX;
        if (acc.email.find(".com", 2) < 2 || acc.email.find(".co.il", 2) < 2)
            throw DOMAIN_EX;
    }
    // Case invalid input
    catch(const char* error)
    {
        // Set all fields to default empty values
        acc.accountNumber = acc.code = 0;
        acc.email = "";
        // Throw the exception to caller
        throw error;
    }
    return is;
}


void Account::withdraw(const int& withdrawAmount)
{
    // Case account overdraft exceeds credit limit - Raise exception
    if ((this->balance - withdrawAmount) < CREDIT_LIMIT)
        throw CREDIT_LIMIT_EX;
    // Case withdrawl exceeds maximum allowed withdrawl amount - Raise exception
    if (withdrawAmount > MAX_WITHDRAWL)
        throw WITHDRAW_LIMIT_EX;
    
    // Case valid withdrawl - Decreese withdrawl amount from account balance
    this->balance -= withdrawAmount;

    // Increment static withdrawl counter
    ++sumWithdraw;
}


void Account::deposit(const int& depositAmount)
{
    // Case argumented amount exceeds maximum allowed deposit amount
    if (depositAmount > MAX_DEPOSIT)
        throw DEPOSIT_LIMIT_EX;
    
    // Case valid deposit - Increase account balance by deposit amount
    this->balance += depositAmount;

    // Increment static deposits counter
    ++sumDeposit;
}




