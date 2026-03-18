#include<iostream>
#include "Account.h"
using namespace std;

/**
 * @file Source.cpp
 * @author Winston Sewell
 * @date 2025-02-26
 * @brief A banking simulation interacting with Account and Customer objects.
 */

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

int deposit_amount = 0;
int withdrawal_amount = 0;


int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);
    account.printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
            /* 
            TODO: Gather the deposit amount input and validate it is > 0.
            Add the code that interacts with the account object to add
            a deposit to the account.
            */
           cout << "Enter Deposit Amount: " << endl;
           cin >> deposit_amount;
           if (deposit_amount > 0)
           {
            account.deposit(deposit_amount);
           }
           else
           {
            cout << "Sorry, that's not a valid number, try again" << endl;
            cin >> deposit_amount;
           }
           
            break;
        case WITHDRAWAL:
            /*
            TODO: Gather the withdrawal amount input and validate it is > 0.
            Add the code that interacts with the account object to add
            a widthdrawal to the account.
            */

            cout << "Enter how much you'd like to take out: " << endl;
            cin >> withdrawal_amount;

            if (withdrawal_amount > 0)
            {
                cout << "Enter how much you'd like to withdrawl: " << endl;
                cin >> withdrawal_amount;
                if (withdrawal_amount > 0)
                {
                    account.getBalance() - withdrawal_amount; 
                }
                else
                {
                    cout << "That is not a valid amount, try again" << endl;
                    cin >> withdrawal_amount;
                }
                
                
            }
            
           
            break;
        case CLOSE_OF_BUSINESS:
            /*
            TODO: Add the code that interacts with the account object to perform
            the close of business account balancing.
            */

            account.closeOfBusiness();
            break;
        }

        menuChoice = getMenuOption();
    }
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}