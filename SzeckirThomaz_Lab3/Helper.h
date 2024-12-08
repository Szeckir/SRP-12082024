#pragma once
#include <string>
#include <iostream>
#include <bitset>
#include <vector>

namespace Helper {

	int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0) {
		int userInput;
		bool isValidated = true;

		while (isValidated) {
			std::cout << strMessage;
			std::cin >> userInput;

			if ((userInput >= nMinimumRange && userInput <= nMaximumRange) || (nMinimumRange == 0 && nMaximumRange == 0)) {
				isValidated = false;
			}
			else {
				std::cout << "\nNumber not valid!\n";
				std::cin.clear();
				std::cin.ignore();
			}
		}

		return userInput;
	}

	int PrintMenu(std::vector<std::string> menuOptions) {
		int userInput;
		bool isNotValid = true;
		
		do {
			int i = 0;

			for(i = 0; i < menuOptions.size(); i++) {
				std::cout << "[" << i + 1 << "]: " << menuOptions[i] << std::endl;
			}
			
			std::cout << "What option do you want? ";
			std::cin >> userInput;
			
			if (userInput >= 0 && userInput <= menuOptions.size()) {
				isNotValid = false;
			}
			else {
				std::cout << "Invalid option. Please try again.\n";
			}
		} while (isNotValid);

		return userInput - 1;
	}

	void PrintInteger(int& number) {
		std::cout << "Binary: " << std::bitset<8>(number) << std::endl;
		std::cout << "Oct: " << std::oct << number << std::endl;
		std::cout << "Hexadecimal: " << std::hex << number << std::dec << std::endl;
	}

	int GetRandomNumber(int nMinimumRange = 0, int nMaximumRange = 0) {
		int randNumber = rand() % (nMaximumRange - nMinimumRange + 1) + nMinimumRange;
		return randNumber;
	}
}