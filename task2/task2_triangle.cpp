/* Task-2-
Drawing a triangle in ASCII graphics.

CPP source file UTF-8, Linux.

Compiler on Ubuntu 16.04, version C++11 (ISO/IEC 14882:2011). 
*/ 

#include <iostream>
using namespace std;

int main()
{
	int base_length;   // triangle base's length
	int space;   // spaces quantity in begin
	int count;   // stars quantity in begin
	int space_count, star_count;   // spaces and start counters

	cout << "Input a triangle base's length (integer number): ";
	cin >> base_length;

	// checking number 
	while (base_length <= 0) {
		cout << "\nIncorrect number!!!\n\n";
		cout << "Input a triangle base's length (positive number): ";
		cin >> base_length;
	} 

	// stars and spaces quantity in first line
	if (base_length % 2 == 1) {   // odd number 
		count = 1;
		space = base_length / 2;
	}
	else {   // even number
		count = 2;
		space =	base_length / 2 - 1;
	} 
	
	// drawing triangle	
	while (count <= base_length) {
		for (space_count = 1; space_count <= space; space_count++)   // drawed spaces
			cout << " ";
		for (star_count = 1; star_count <= count; star_count++)   // drawed stars
			cout << "*";

		// new triangle line
		cout << endl; 

		space--;   // space quantity decrement -1
		count+=2;   // stars quantity increment +2 
	}

	return 0;
}