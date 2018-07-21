/* Task-2-
Balanced () and [] and {}. 

CPP source file UTF-8, Linux.

Compiler on Ubuntu 16.04, version C++11 (ISO/IEC 14882:2011). 
*/ 

// 1 step

#include <iostream>
#include <string>
using namespace std;

int main()
{   
	// terms: parentheses is round brackets () , brackets is square brackets [], braces is braces {} :)
	
	int parentheses = 0, brackets = 0, braces = 0;   // counter for each bracket
	bool err = false, first_open_parentheses = false /* to all brakets nead 3 bools*/ ;
	int last_open_parentheses_pos, last_close_parentheses_pos;   // fixe last position
	int i;

	//string text ("())");   // string initialization for testing
	string text;

	cout << "Input text with () and/or [] and/or {} .\n"; 
	cin >> text;   // text input

	cout << "\n";

	int count = text.length();   // text length

		// text output
		cout << text << "\n";

		for (i = 0; i < count; ++i)
		{
			cout << text[i] << i + 1 << " "; 
		}
		// for testing 
		cout << "\nLength is " << count << "\n\n";

	// balance checking 
	for (i = 0; i < count; i++) {
		if (text[i] == '(') {   // open parentheses
			parentheses++;
			last_open_parentheses_pos = i + 1; 
		} 
			
		if (text[i] == ')')   // close parentheses
			parentheses--;

			if (parentheses < 0) {
				err = true;
				cout << "Error!!! In position " << i + 1 << ".\n";   // output for testing 
				last_close_parentheses_pos = i + 1; 
				break;  // break loop on error
			}

	}

	// Answer 
	if (!err && parentheses == 0)
		cout << " () is balanced.";
	else {
		cout << " () NOT balanced.";

		if (parentheses < 0) 
			cout << "\nClose parentheses error in position " << last_close_parentheses_pos << ".";
		else
			cout << "\nOpen parentheses error in position " << last_open_parentheses_pos << ".";  
	}

	cout << endl << endl; 
	return 0; 	
}
