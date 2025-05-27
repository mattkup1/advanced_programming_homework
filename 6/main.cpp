#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;

const char* ACC_NOT_FOUND_EX = "ERROR: no such account number";
const char* WRONG_CODE_EX    = "ERROR: wrong code";

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
void getBalance(Account* bank, int amount, Clock& c);
void cashDeposit(Account* bank, int amount, Clock& c);


int main() 
{
    const int SIZE = 10;
    Clock present;

    cout << "enter current time";
    cin >> present;
    cout << "current time is: " << present << endl;

    Account bank[SIZE];
    cout << "enter account number, code and email for " << SIZE << " accounts:\n";
    
    for (unsigned i = 0; i < SIZE; ++i)
    {
        try
        {
            cin >> bank[i];
        }
        catch(const char* error)
        {
            cout << error << endl;
            --i;
        }
    }

    // Read action code from user
    ACTION ac = menu();

    // While action code != 0
    while (ac) 
    {
        switch (ac) 
        {
            case BALANCE: 
                try
                {
                    getBalance(bank, SIZE, present);
                }
                catch (const char* exception)
                {
                    cout << exception << endl;
                }
                break;
                // TODO combine tries to one and a single catch
            case WITHDRAW:
                try
                {
                    cashWithdraw(bank, SIZE, present);
                }
                catch(const char* exception)
                {
                    cout << exception << endl;
                }
                break;
            case DEPOSIT:
                cashDeposit(bank, SIZE, present);
                break;
            case SUM_DEPOSIT:
                printTransaction(bank[0], SUM_DEPOSIT, present);
                break;
            case SUM_WITHDRAW:
                printTransaction(bank[0], SUM_WITHDRAW, present);
        }
        // Increment time by 40 seconds
        present += 40;
        ac = menu();
    }
    return 0;
}


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
            cout << "account #: " << a.getAccountNumber() << "\t";
            cout << "new balance: " << a.getBalance() << endl;
            break;
        case DEPOSIT:
        case WITHDRAW: 
            cout << "account #: " << a.getAccountNumber() << "\t";
            cout << "new balance: " << a.getBalance() << endl;
            break;
        case SUM_DEPOSIT:
            cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
            break;
        case SUM_WITHDRAW:
            cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
            break;
    }
}


void getBalance(Account* bank, int numAccounts, Clock& c) 
{
    //TODO: read account number and code
    int accNum, code;

    cout << "please enter the account number: " << endl;
    cin >> accNum;
    cout << "please enter the code: " << endl;
    cin >> code;
    
    // Search for account 
    for (int i = 0; i <= numAccounts; ++i)
    {
        if (accNum == bank[i].getAccountNumber())
        {
            if (code == bank[i].getCode())
                printTransaction(bank[i], BALANCE, c);
            else
                throw WRONG_CODE_EX;
        }
    }
    throw ACC_NOT_FOUND_EX;
}


void cashDeposit(Account* bank, int numAccounts, Clock& c)
{
    // CHECK THIS CODE
    try
    {
        int accNum, code, amount;
        cout << "please enter account number: " << endl;
        cin >> accNum;
        cout << "please enter the code: " << endl;
        cin >> code;
        cout << "enter the amount of the deposit: " << endl;
        cin >> amount;
    }
    catch(const char* error)
    {
        cout << error << endl;
    }

    // TODO: Case error - throw exception

    // TODO: Update balance accordingly

    // TODO: Call printTransaction()
}


void cashWithdraw(Account* bank, int numAccounts, Clock& c)
{
    // TODO: read account number, code and amount

    // TODO: Case error - throw exception

    // TODO: Update balance accordingly

    // TODO: Call printTransaction()
}