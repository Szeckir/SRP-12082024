// SzeckirThomaz_Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

void Deposit(BaseAccount* account) {
    float amount;
    std::cout << "Enter the amount to deposit: ";
    std::cin >> amount;
    if (amount > 0) {
        account->Deposit(amount);
        std::cout << "Deposit successful. Current balance: $" << account->GetBalance() << "\n";
    }
    else {
        std::cout << "You have to deposit more than 0$\n";
    }
    
}

void Withdraw(BaseAccount* account) {
    float amount;
    std::cout << "Enter the amount to withdraw: ";
    std::cin >> amount;
    if (account->GetBalance() >= amount) {
        account->Withdraw(amount);
        std::cout << "Withdrawal processed. Current balance: $" << account->GetBalance() << "\n";
    }
    else {
        std::cout << "Insufficient funds. Withdrawal denied.\n";
    }
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1);
    _CrtDumpMemoryLeaks();

    CheckingAccount* checking = new CheckingAccount();
    SavingsAccount* savings = new SavingsAccount();
    CreditAccount* credit = new CreditAccount();

    /*checking->Deposit(1000);
    savings->Deposit(2000);
    credit->Deposit(1500);*/

    //credit->Withdraw(400);

    bool running = true;
    while (running) {
        std::cout << "\nWelcome to the Bank Menu\n";
        std::cout << "1. Deposit to Checking\n";
        std::cout << "2. Withdraw from Checking\n";
        std::cout << "3. Deposit to Savings\n";
        std::cout << "4. Withdraw from Savings\n";
        std::cout << "5. Deposit to Credit\n";
        std::cout << "6. Withdraw from Credit\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            Deposit(checking);
            break;
        case 2:
            Withdraw(checking);
            break;
        case 3:
            Deposit(savings);
            break;
        case 4:
            Withdraw(savings);
            break;
        case 5:
            Deposit(credit);
            break;
        case 6:
            Withdraw(credit);
            break;
        case 7:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    delete checking;
    delete savings;
    delete credit;
}


