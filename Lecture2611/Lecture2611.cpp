// Lecture2611.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

void Print(const unsigned int& _x);

int main()
{
    int x;
    x = 47;

    Print(x);

    std::cout << "SHIFTING:" << std::endl;

    x = x << 1;

    Print(x);

    x = x >> 2;

    Print(x);

    std::cout << "\n NOT:" << std::endl;
    x = 47;

    x = ~x;

    Print(x);

    std::cout << "\n AND:" << std::endl;

    int a = 231;
    int b = 147;
    Print(a);
    Print(b);
    Print(a & b);

    std::cout << "\n OR:" << std::endl;
    int a1 = 231;
    int b1 = 147;
    Print(a1);
    Print(b1);
    Print(a1 | b1);

    std::cout << "\n XOR:" << std::endl;
    int a2 = 231;
    int b2 = 147;
    Print(a2);
    Print(b2);
    Print(a2 ^ b2);

}

void Print(const unsigned int& _x) {
    std::cout << "DEC:   " << _x << "\t";
    std::cout << "HEX:   " << std::hex << _x << std::dec << "\t";
    std::cout << "BIN:   " << std::bitset<32>(_x) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
