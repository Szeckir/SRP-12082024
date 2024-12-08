// SzeckirThomaz_Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

enum EnumColorDefinition {
	Red,
	Blue,
};

struct Car {
	char Make[32];
	char Model[32];
	int Year;
	int Mileage;
	EnumColorDefinition Color;
};

void printCar(Car c);
void printCarPointer(Car* ptrCar);
void addMileage(Car* ptrCar, int milestoadd);

void repaintCar(Car* ptrCar, EnumColorDefinition newcolor);

void printElements(int& param, int* paramPtr);

void program1();
void program2();
void program3();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);
	_CrtDumpMemoryLeaks();

	//program1();
	program2();
	//program3();
}

void program1() {
	const int arraySize = 15;
	int array[arraySize];
	for (int i = 0; i < arraySize; i++) {
		array[i] = rand() % 1000;
	}

	for (int i = 0; i < arraySize; i++) {
		std::cout << "Number: " << array[i] << '\t';
		int* ptrArray = &array[i];
		std::cout << "| Memory address: " << ptrArray << std::endl;
	}
}

void program2() {
	const int arraySize = 15;
	int array[arraySize];
	for (int i = 0; i < arraySize; i++) {
		array[i] = rand() % 10000;
	
	}

	std::cout << "Debug: Array contents:\n";
	for (int i = 0; i < arraySize; i++) {
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}

	for (int i = 0; i < arraySize; i++) {
		int* ptrArray = &array[i];
		printElements(array[i], ptrArray);
	}
}

void program3() {
	Car cars[3];
	int i = 0;

	do {
		char make_[32];
		char model_[32];
		int year_;
		int mileage_;
		EnumColorDefinition color_;

		cout << "You are adding the Car number " << i + 1 << ":" << endl;
		std::cout << "Make: ";
		
		std::cin.getline(make_, 32);
		
		std::cout << "Model: ";
		std::cin.getline(model_, 32);

		std::cout << "Year: ";
		std::cin >> year_;
		std::cin.ignore();

		std::cout << "Milage: : ";
		std::cin >> mileage_;
		std::cin.ignore();

		int input;
		std::cout << "Type the nuber to select the color of your car: " << '\n' << "[1]: Red " << '\n' << "[2]: Blue \n" << "Input: ";
		std::cin >> input;
		std::cin.ignore();	

		switch (input)
		{
		case 1:
			color_ = EnumColorDefinition::Red;
			break;
		case 2:
			color_ = EnumColorDefinition::Blue;
			break;
		default:
			color_ = EnumColorDefinition::Red;
			break;
		}

		strcpy_s(cars[i].Make, make_);
		strcpy_s(cars[i].Model, model_);
		cars[i].Year = year_;
		cars[i].Mileage = mileage_;
		cars[i].Color = color_;

		cout << "\nYour car was created \n";
		//cout << cars[i].Make << " " << cars[i].Model << " " << cars[i].Year << " " << cars[i].Mileage << " " << cars[i].Color << std::endl;
		i++;

	} while (i < 3);

	repaintCar(&cars[0], EnumColorDefinition::Red);
	addMileage(&cars[1], 95000);

	cout << "Printing cars:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Car " << i + 1 << " - ";
		printCar(cars[i]);
	}

	cout << "Printing cars pointer:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Car " << i + 1 << " - ";
		printCarPointer(&cars[i]);
	}
}

void printElements(int& param, int* paramPtr) {
	std::cout << "Number: [ " << param << " ] \t| Pointer: [ Ox" << paramPtr << " ]" << std::endl;
	/*std::cout << "Debug: Inside printElements\n";
	std::cout << "param = " << param
		<< ", Address of param = " << &param
		<< ", paramPtr = " << paramPtr
		<< ", *paramPtr = " << *paramPtr << std::endl;*/

	//std::cout << "Number: " << param << ' \t' << "| Pointer: " << paramPtr << std::endl;
}

void repaintCar(Car* ptrCar, EnumColorDefinition newcolor) {
	ptrCar->Color = newcolor;
}

void printCar(Car c) {
	printCarPointer(&c);
}

void printCarPointer(Car* ptrCar) {
	cout << ptrCar->Year << ' ';

	switch (ptrCar->Color)
	{
	case 0:
		cout << "Red ";
		break;
	case 1:
		cout << "Blue ";
		break;
	}

	cout << ptrCar->Make << ' ' << ptrCar->Model << " with " << ptrCar->Mileage << " miles" << endl;
}

void addMileage(Car* ptrCar, int milestoadd) {
	ptrCar->Mileage += milestoadd;
}