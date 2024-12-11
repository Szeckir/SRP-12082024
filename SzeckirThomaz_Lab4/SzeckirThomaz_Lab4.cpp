// SzeckirThomaz_Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include <fstream>
#include <vector>

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

void WriteFileBinary(std::vector<BaseAccount*>& accounts) {
    std::ofstream fout;

    fout.open("output.bin", std::ios_base::binary);

    if (fout.is_open())
    {
        // write to the file the number of Person objects in the file
        int size = accounts.size();
        fout.write((char*)&(size), sizeof(int));
        // write to the file all the Person objects in the vector
        fout.write((char*)&(accounts[0]), accounts.size() * sizeof(BaseAccount)); // O(1)

        // close file
        fout.close();
    }
    else
    {
        std::cout << "File did not open" << std::endl;
    }
}

void ReadFileBinary(std::vector<BaseAccount*>& accounts) {
    std::ifstream fin;
    fin.open("output.bin", std::ios_base::binary); // binary format

    if (fin.is_open())
    {
        // read in  the number of Person objects in the file
        int size = 0;
        fin.read((char*)&size, sizeof(int));
        // resize the array to above size
        accounts.resize(size);

        // read from file all the Person objects in the vector
        fin.read((char*)&(accounts[0]), accounts.size() * sizeof(BaseAccount)); // O(1)

        // close file
        fin.close();
    }
    else
    {
        std::cout << "File did not open" << std::endl;
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

    BaseAccount* checking = new CheckingAccount();
    BaseAccount* savings = new SavingsAccount();
    BaseAccount* credit = new CreditAccount();
    BaseAccount* credit2 = new CreditAccount();
    BaseAccount* savings2 = new CreditAccount();

    std::vector<BaseAccount*> accounts;
    accounts.push_back(checking);
    accounts.push_back(savings);
    accounts.push_back(credit);
    accounts.push_back(credit2);
    accounts.push_back(savings2);

    checking->Deposit(2000);
    savings->Deposit(5000);
    credit->Deposit(1500);
    credit2->Deposit(3500);
    savings2->Deposit(1000000);
    savings2->Withdraw(200);

    WriteFileBinary(accounts);
    ReadFileBinary(accounts);

    for (int i = 0; i < accounts.size(); i++) {
        std::cout << accounts[i]->GetBalance() << std::endl;
    }


    /*checking->Deposit(1000);
    savings->Deposit(2000);
    credit->Deposit(1500);*/

    //credit->Withdraw(400);

   /* bool running = true;
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
    }*/

    

    delete checking;
    delete savings;
    delete credit;
}


