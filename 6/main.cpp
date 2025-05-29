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

// Function to prompt user for action number from menu and return user input
ACTION menu();
// Function to print transaction details
void printTransaction(Account a, ACTION ac, Clock& c);
// Function that reads account info from user and print account balance
void getBalance(Account* bank, int numAccounts, Clock& c);
// Function that reads account info and deposit amount from user and perform deposit
void cashDeposit(Account* bank, int numAccounts, Clock& c);
// Function that reads account info and withdrawl amount from user and perform withdrawl
void cashWithdraw(Account* bank, int numAccounts, Clock& c);


int main() 
{
    const int SIZE = 10;
    Clock present;

    cout << "enter current time" << endl;
    try
    {
        cin >> present;
    }
    // Case invalid time inputed - Raise exception, Time will be set to 00:00:00
    catch(const char* exception)
    {
        cout << exception << endl;
    }
    // Print current time
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
            cout << present << "\t" << error << endl;
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
    
    try
    {
        // Get account number
        cout << "please enter account number " << endl;
        cin >> accNum;

        // Search for account 
        for (unsigned i = 0; i < numAccounts; ++i)
        {
            // Case account exists in bank
            if (accNum == bank[i].getAccountNumber())
            {
                // Get code
                cout << "please enter the code " << endl;
                cin >> code;

                // Check if the code matches
                if (code == bank[i].getCode()) 
                {
                    // Case correct code, Get deposit amount
                    cout << "enter the amount of the deposit " << endl;
                    cin >> amount;
                    // Try performing a deposit, If amount is invalid, An exception will be raised
                    bank[i].deposit(amount);
                    // Print the transaction details - will only be executed if an exception was not raised in the previous line
                    printTransaction(bank[i], WITHDRAW, c);
                    return;
                }
                // Case wrong code
                throw WRONG_CODE_EX;
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

    try
    {
        // Get account number
        cout << "please enter account number " << endl;
        cin >> accNum;

        // Search for account 
        for (unsigned i = 0; i < numAccounts; ++i)
        {
            // Case account exists in bank
            if (accNum == bank[i].getAccountNumber())
            {
                // Get code
                cout << "please enter the code " << endl;
                cin >> code;

                // Check if the code matches
                if (code == bank[i].getCode()) 
                {
                    // Case correct code, Get withdraw amount
                    cout << "enter the amount of money to withdraw " << endl;
                    cin >> amount;
                    // Try performing a withdrawl, If amount is invalid, An exception will be raised
                    bank[i].withdraw(amount);
                    // Print the transaction details - will only be executed if an exception was not raised in the previous line
                    printTransaction(bank[i], WITHDRAW, c);
                    return;
                }
                // Case wrong code
                throw WRONG_CODE_EX;
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
    // Perform action based on argumented action
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
            // Print the summary of all deposits from bank, Using the static summary
            cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
            break;
        case SUM_WITHDRAW:
        // Print the summary of all withdrawls from bank, Using the static summary
            cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
            break;
    }
}


/*
EXAMPLE:

enter current time
11:58:01
current time is: 11:58:01
enter account number, code and email for 10 accounts:
3829 2293 matt@gmail.com
9999 2323 jenny@yahoo.com
3939 1010 josh@hotmail.com
-2933 8888 gabe@meta.co.il
11:58:01        ERROR: account number must be positive
2933 8888 gabe@meta.co.il
9900 781 brandon@microsoft.com
11:58:01        ERROR: code must be of 4 digits
9900 7810 brandon@microsoft.com
5651 2224 glen@gmail.com
8902 3855 abe@amazon.eu
11:58:01        ERROR: email must end with .com or .co.il
8902 3855 abe.amazon.com
11:58:01        ERROR: email must contain @
2902 3855 abe@amazon.com
4589 0344 tiffany@intel.co.il
11:58:01        ERROR: code must be of 4 digits
4589 7344 tiffany@intel.co.il
3921 5156 nate@ajhco.com
9233 7771 jacob@apple.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to exit
1
please enter account number: 
4589
please enter the code: 
7344
11:58:01                account #: 4589 balance: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to exit
2
please enter account number 
4589
please enter the code 
7344
enter the amount of the deposit 
3500
11:58:41                account #: 4589 balance: 3500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to exit
3
please enter account number 
2902
please enter the code 
3855
enter the amount of money to withdraw 
800

*/