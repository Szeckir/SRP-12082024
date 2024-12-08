#include "Console.h"

// All parameters should use one of the following,
//	- bitField
//		- The field of bits that you are manipulating
//  - bitIndex 
//		- The position of the bit that you are manipulating

// TODO: Create a TurnOn method
// TODO: Create a TurnOff method
// TODO: Create a Toggle method
// TODO: Create a IsBitOn method
// TODO: Create a Negate method
// TODO: Create a LeftShift method
// TODO: Create a RightShift method

void TurnOn(int& bitfield, int bitIndex) {
	int aux = 1 << bitIndex;
	bitfield = bitfield | aux;
}

void TurnOff(int& bitfield, int bitIndex) {
	int aux = 1 << bitIndex;
	bitfield = bitfield & ~aux;
}

void Toggle(int& bitfield, int bitIndex) {
	int aux = 1 << bitIndex;
	bitfield = bitfield ^ aux;
}

bool IsBitOn(int& bitfield, int bitIndex) {
	int aux = 0 << bitIndex;
	if (aux & bitfield) {
		return false;
	}
	else {
		return true;
	}
}

void Negate(int& bitfield, int bitIndex) {
	bitfield = ~bitfield;
}

void LeftShift(int& bitfield) {
	bitfield = bitfield << 1;
}

void RightShift(int& bitfield) {
	bitfield = bitfield >> 1;
}

// OPTIONAL - 
// You can implement this method
//		void ToHex(int bitField, std::string& displayField);

void ToHex(int bitField, std::string& displayField) {
	for (int i = 0; i < displayField.length(); i++) {
		
	}
}

// You can implement this method
//		void ToOct(int bitField, std::string& displayField);

/*
	YOU SHOULD - only be adding to the code via:
		- Creating/Calling methods
		- Passing Parameters
		- Manipulating Data using bit shifting

	DO NOT:
		- Modify/Remove any methods being called already.
			This will result in a 0.
		- Be using
			- std::bitset
			- std::oct
			- std::hex
			- std::stringstream
*/
int main()
{
	int bitField = 0;
	int nSelectedBit = 0;
	std::string hexField = "0";
	std::string octField = "0";
	bool run = true;

	System::Console app = System::Console(bitField, nSelectedBit, hexField, octField);
	if (!app.Init()) return -1; 

	while (app.Run())
	{
		// DO NOT REMOVE THIS LINE:
		app.DisplayMenu();

		if (System::Console::WasMoveSelectorRightPressed())
		{
			if (nSelectedBit < 31) ++nSelectedBit;
		}
		if (System::Console::WasMoveSelectorLeftPressed())
		{
			if (nSelectedBit > 0) --nSelectedBit;
		}
		if (System::Console::WasTurnOnPressed())
		{
			// Implement the TurnOn Method
			TurnOn(bitField, nSelectedBit);

		}
		if (System::Console::WasTurnOffPressed())
		{
			// Implement the TurnOff Method
			TurnOff(bitField, nSelectedBit);

		}
		if (System::Console::WasTogglePressed())
		{
			// Implement the Toggle Method
			Toggle(bitField, nSelectedBit);
		}
		if (System::Console::WasNegatePressed())
		{
			// Implement the Negate Method
			Negate(bitField, nSelectedBit);

		}
		if (System::Console::WasShiftLeftPressed())
		{
			// Implement the LeftShift Method
			LeftShift(bitField);

		}
		if (System::Console::WasShiftRightPressed())
		{
			// Implement the RightShift Method
			RightShift(bitField);
		}

		//ToHex(bitField, )

		// OPTIONAL - Implement the ToHex method
		
		// OPTIONAL - Implement the ToOct method

		System::Console::Lock(false);
		Sleep(50);
	}
	app.Exit();
}