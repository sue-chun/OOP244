// Workshop 4 - Constructors - Test Main
// w4_in_lab.cpp
// Chris Szalwinski
// 9/23/2017
//
#include <iostream>
#include "Passenger.h"
#include "Passenger.h" // this is intentional

using namespace std;
using namespace sict;

int main() {
	Passenger travellers[] = {
		Passenger(nullptr, "Toronto"),
		Passenger("", "Toronto"),
		Passenger("John Smith", nullptr),
		Passenger("John Smith", ""),
		Passenger("John Smith", "Toronto"), // valid
		Passenger(nullptr, nullptr),
		Passenger()
	};
	cout << "----------------------------------------\r" << endl;
	cout << "Testing the validation logic\r" << endl;
	cout << "(only passenger 5 should be valid)\r" << endl;
	cout << "----------------------------------------\r" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << "Passenger " << i + 1 << ": " << (travellers[i].isEmpty() ? "not valid\r" : "valid\r") << endl;
	}
	cout << "----------------------------------------\r" << endl << "\r" << endl;

	Passenger vanessa("Vanessa", "Paris"),
		      mike("Mike", "Tokyo"),
		      alice("Alice", "Paris");

	cout << "----------------------------------------\r" << endl;
	cout << "Testing the display function\r" << endl;
	cout << "----------------------------------------\r" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	travellers[0].display();
	cout << "----------------------------------------\r" << endl << "\r" << endl;

	return 0;
}
