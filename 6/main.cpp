#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;

enum ACTION 
{
    EXIT,
    BALANCE,
    DEPOSIT,
    WITHDRAW,
    SUM_DEPOSIT,
    SUM_WITHDRAW
};

ACTION menu();
void printTransaction(Account a, ACTION ac, Clock& c);



ACTION menu() 
{
    cout << "enter 1 to get account balance" << endl;
    cout << "enter 2 to deposit money" << endl;
    cout << "enter 3 to withdraw money" << endl;
    cout << "enter 4 to see the sum of all deposits" << endl;
    cout << "enter 5 to see the sum of all withdrawals" << endl;
    cout << "enter 0 to exit" << endl;

    int x;
    cin >> x;

    return (ACTION)x;
}

void printTransaction(Account a, ACTION ac, Clock& c) 
{
    cout << c << "\t";
    switch (ac) 
    {
        case BALANCE:
            break;
        case DEPOSIT:
            break;
        case WITHDRAW: 
            cout << "account #: " << a.getAccountNumber() << "\t";
            cout << "balance: " << a.getBalance() << endl;
            break;
        case SUM_DEPOSIT:
            cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
            break;
        case SUM_WITHDRAW:
            cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
            break;
    }
}


void getBalance(Account* bank, int size, Clock& c) 
{
    //TODO: read account number and code
    // if error - throw exception
    // print balance by calling balance function
}