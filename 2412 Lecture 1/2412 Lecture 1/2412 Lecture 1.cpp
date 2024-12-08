// 2412 Lecture 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>

void Print(const unsigned int& _x);

int main()
{
	//int x;
	//x = 74;
	//std::cout << x << std::endl;
	//std::cout << (char)x << std::endl; // interpret what is at x as a char

	//std::cout << INT_MAX << std::endl;
	//std::cout << UINT_MAX << std::endl;
	//std::cout << ULLONG_MAX << std::endl;

	//Print(x);

	// Left Shift ( << )
	/*int x = 231;
	Print(x);
	x = x << 1;
	Print(x);*/


	//// Right Shift ( >> )
	//int x = 231;
	//Print(x);
	//x = x >> 1;
	//Print(x);
	//x = x << 1;
	//Print(x);

	//// NOT ( ~ )
	//unsigned int z = 231;
	//Print(z);
	//z = ~z;
	//Print(z);

	//// AND ( & )
	//int a = 231;
	//Print(a);
	//int b = 147;
	//Print(b);
	//Print(a & b);

	//// OR ( | )
	//int a1 = 231;
	//Print(a1);
	//int b1 = 147;
	//Print(b1);
	//Print(a1 | b1);

	//// XOR ( ^ )
	//int a2 = 231;
	//Print(a2);
	//int b2 = 147;
	//Print(b2);
	//Print(a2 ^ b2);

	//Let’s look at an example of storing 8 flags(Boolean values) in one char

	//const unsigned char isHungry =	1 << 0; // 0000 0001
	//const unsigned char isSad =		1 << 1; // 0000 0010
	//const unsigned char isMad =		1 << 2; // 0000 0100
	//const unsigned char isHappy =	1 << 3; // 0000 1000
	//const unsigned char isLaughing =1 << 4; // 0001 0000
	//const unsigned char isAsleep =	1 << 5; // 0010 0000
	//const unsigned char isDead =	1 << 6; // 0100 0000
	//const unsigned char isCrying =	1 << 7; // 1000 0000

	//unsigned char me = 0; // all flags/options turned off to start

	//me = me | isHappy | isLaughing; // I am happy and laughing
	//// me			0000 0000
	//// isHappy		0000 1000
	//// isLaughing	0001 0000
	//// ----------------------
	//// me			0001 1000
	//Print(me);

	//me = me & ~isLaughing; // I am no longer laughing
	//// me			0001 1000
	////~isLaughing	1110 1111
	//// ----------------------
	//// me			0000 1000
	//Print(me);

	//// Query a few states (we'll use static_cast<bool> to interpret the results as a 
	//// boolean value rather than an integer)
	//std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	//// me			0000 1000
	//// isHappy		0000 1000
	//// ----------------------
	////				0000 1000

	//std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';
	//// me			0000 1000
	//// isLaughing	0001 0000
	//// ----------------------
	////				0000 0000


	//Let’s look at an example of storing RGBA values in one 32 bit(4byte) integer
	const unsigned int redBits =	0xFF000000;
	const unsigned int greenBits =	0x00FF0000;
	const unsigned int blueBits =	0x0000FF00;
	const unsigned int alphaBits =	0x000000FF;

	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
	unsigned int pixel;
	std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

	// use bitwise AND to isolate red pixels, then right shift the value into the range 0-255
	unsigned char red = (pixel & redBits) >> 24;
	unsigned char green = (pixel & greenBits) >> 16;
	unsigned char blue = (pixel & blueBits) >> 8;
	unsigned char alpha = pixel & alphaBits;

	std::cout << "Your color contains:\n";
	std::cout << static_cast<int>(red) << " of 255 red\n";
	std::cout << static_cast<int>(green) << " of 255 green\n";
	std::cout << static_cast<int>(blue) << " of 255 blue\n";
	std::cout << static_cast<int>(alpha) << " of 255 alpha\n";


}

void Print(const unsigned int& _x)
{
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
