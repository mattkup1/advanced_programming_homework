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


int main() 
{
    const int SIZE = 10;
    Clock present;

    cout << "enter current time" << endl;
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


void getBalance(Account* bank, int numAccounts, Clock& c) 
{
    int accNum, code;
    float amount;

    // Get account details
    cout << "please enter account number: " << endl;
    cin >> accNum;
    cout << "please enter the code: " << endl;
    cin >> code;
    
    try
    {
        // Validate input
        // Search for account 
        for (unsigned i = 0; i < numAccounts; ++i)
        {
            // Case account exists in bank
            if (accNum == bank[i].getAccountNumber())
            {
                // Check if the code matches, If so, Call printTransaction, Else, Raise exception
                (code == bank[i].getCode() ? printTransaction(bank[i], BALANCE, c) : throw WRONG_CODE_EX);
                return;
            }
        }
        // Case account number not found in iterations - Raise exception
        throw ACC_NOT_FOUND_EX;
    }
    // Case exception caught
    catch (const char* exception)
    {   
        // Pass the exception on to the caller function
        throw exception;
    }
}


// Deposit
void cashDeposit(Account* bank, int numAccounts, Clock& c)
{
   int accNum, code;
    float amount;

    // Get account details
    cout << "please enter account number: " << endl;
    cin >> accNum;
    cout << "please enter the code: " << endl;
    cin >> code;
    // Get deposit amount
    cout << "enter the amount of the deposit: " << endl;
    cin >> amount;
    
    try
    {
        // Validate input
        // Search for account 
        for (unsigned i = 0; i < numAccounts; ++i)
        {
            // Case account exists in bank
            if (accNum == bank[i].getAccountNumber())
            {
                // Check if the code matches, If so, Perform deposit, Else, Raise exception
                (code == bank[i].getCode() ? bank[i].deposit(amount) : throw WRONG_CODE_EX);
                // Print the transaction details - will only be executed if an exception was not raised in the previous line
                printTransaction(bank[i], DEPOSIT, c);
                return;
            }
        }
        // Case account number not found in iterations - Raise exception
        throw ACC_NOT_FOUND_EX;
    }
    // Case exception caught
    catch (const char* exception)
    {   
        // Pass the exception on to the caller function
        throw exception;
    }
} 


// Withdraw
void cashWithdraw(Account* bank, int numAccounts, Clock& c)
{
    int accNum, code;
    float amount;

    // Get account details
    cout << "please enter account number: " << endl;
    cin >> accNum;
    cout << "please enter the code: " << endl;
    cin >> code;
    // Get withdraw amount
    cout << "enter the amount of money to withdraw: " << endl;
    cin >> amount;
    
    try
    {
        // Validate input
        // Search for account 
        for (unsigned i = 0; i < numAccounts; ++i)
        {
            // Case account exists in bank
            if (accNum == bank[i].getAccountNumber())
            {
                // Check if the code matches, If so, Perform withdrawl, Else, Raise exception
                (code == bank[i].getCode() ? bank[i].withdraw(amount) : throw WRONG_CODE_EX);
                // Print the transaction details - will only be executed if an exception was not raised in the previous line
                printTransaction(bank[i], WITHDRAW, c);
                return;
            }
        }
        // Case account number not found in iterations - Raise exception
        throw ACC_NOT_FOUND_EX;
    }
    // Case exception caught
    catch (const char* exception)
    {   
        // Pass the exception on to the caller function
        throw exception;
    }
}


void printTransaction(Account a, ACTION ac, Clock& c) 
{
    cout << c << "\t\t";
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