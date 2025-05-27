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
void cashWithdraw(Account* bank, int numAccounts, Clock& c);
void cashDeposit(Account* bank, int amount, Clock& c);
// Helper function to get and validate account information from user
unsigned getAccInfo(Account* bank, int numAccounts, ACTION ac);


int main() 
{
    const int SIZE = 10;
    Clock present;

    cout << "enter current time";
    try
    {
        cin >> present;
        cout << "current time is: " << present << endl;
    }
    catch(const char* exception)
    {
        cout << exception << endl;
        return 0;
    }

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
        try
        {
            switch (ac) 
            {           
                case EXIT:
                    break; 
                case BALANCE: 
                    getBalance(bank, SIZE, present);
                    break;
                case WITHDRAW:
                    cashWithdraw(bank, SIZE, present);
                    break;
                case DEPOSIT:
                    cashDeposit(bank, SIZE, present);
                    break;
                case SUM_DEPOSIT:
                    printTransaction(bank[0], SUM_DEPOSIT, present);
                    break;
                case SUM_WITHDRAW:
                    printTransaction(bank[0], SUM_WITHDRAW, present);
                    break;
            }
        }
        catch(const char* exception)
        {
            cout << exception << endl;
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
        // Add exit case to avoid warning when compiling
        case EXIT:
            break;
        case BALANCE:
        case DEPOSIT:
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


void getBalance(Account* bank, int numAccounts, Clock& c) 
{
    try
    {
        unsigned accIndex = getAccInfo(bank, numAccounts, BALANCE);
        printTransaction(bank[accIndex], BALANCE, c);
    }
    catch(const char* exception)
    {
        throw exception;
    }
}


void cashDeposit(Account* bank, int numAccounts, Clock& c)
{
    try
    {
        unsigned accIndex = getAccInfo(bank, numAccounts, DEPOSIT);
        printTransaction(bank[accIndex], DEPOSIT, c);
    }
    catch(const char* exception)
    {
        throw exception;
    }
} 



void cashWithdraw(Account* bank, int numAccounts, Clock& c)
{
    try
    {
        unsigned accIndex = getAccInfo(bank, numAccounts, WITHDRAW);
        printTransaction(bank[accIndex], WITHDRAW, c);
    }
    catch(const char* exception)
    {
        throw exception;
    }
}


unsigned getAccInfo(Account* bank, int numAccounts, ACTION ac)
{
    int accNum, code;
    float amount;

    // Get account details
    cout << "please enter the account number: " << endl;
    cin >> accNum;
    cout << "please enter the code: " << endl;
    cin >> code;
    // Case deposit / withdraw - Get amount
    if (ac == DEPOSIT || ac == WITHDRAW)
    {
        cout << "enter the amount of" << 
        (ac == DEPOSIT ? "the deposit: " : "money to withdraw") << endl;
        cin >> amount;
    }
    
    // Validate input
    // Search for account 
    for (unsigned i = 0; i <= numAccounts; ++i)
    {
        // Case account exists in bank
        if (accNum == bank[i].getAccountNumber())
        {
            // Case correct account code
            if (code == bank[i].getCode())
            {
                // Call function based on action
                if (ac == BALANCE) return i;
                else ac == DEPOSIT ? bank[i].deposit(amount) : bank[i].withdraw(amount);
                return i;
            }
            // Case worng code - Raise exception
            throw WRONG_CODE_EX;
        }
    }
    // Case account number not found in iterations - Raise exception
    throw ACC_NOT_FOUND_EX;
}