// SzeckirThomaz_Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Helper.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);
	_CrtDumpMemoryLeaks();

	int i = Helper::GetValidatedInt("Type a number: ", 10, 100);
	//std::cout << i;
	Helper::PrintInteger(i);

	std::vector<std::string> menu;
	menu.push_back("Eat Pumpkin");
	menu.push_back("Eat Apple");
	menu.push_back("Eat Orange");
	menu.push_back("Eat Banana");
	int option = Helper::PrintMenu(menu);
	std::cout<< "\n\n" << menu[option];


	int j = Helper::GetRandomNumber(20, 27);
	std::cout << i;
}