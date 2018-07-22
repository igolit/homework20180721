/* Task-3-
Balanced () and [] and {}. 

Terms: parentheses is round brackets () , brackets is square brackets [], braces is braces {} :)

CPP source file UTF-8, Linux.

Compiler on Ubuntu 16.04, version C++11 (ISO/IEC 14882:2011). 
*/ 

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{   
	bool err = false;   // balance error initialization

	string text;   // text variable 

	cout << "Input text with () and/or [] and/or {} .\n"; 
	cin >> text;   // text input

	// stack of char declaration 
	stack <char> brackets_stack;
   
		// balance checking
		for (int i = 0; i < text.length(); i++) {

			if (text[i] == '(' || text[i] == '[' || text[i] == '{' )  // open brackets
				brackets_stack.push(text[i]);   // push to stack

			if (!brackets_stack.empty()) {
				if (text[i] == ')')   // close parentheses
					if (brackets_stack.top() == '(')
						brackets_stack.pop();   // pop from stack )
					else {
						err = true;
						break;   // break loop on error	
					}   // end else top is (


				if (text[i] == ']')   // close brackets
					if (brackets_stack.top() == '[') 
						brackets_stack.pop();   // pop from stack ]
					else {
						err = true;
						break;   // break loop on error	
					}   // end else top is [


				if (text[i] == '}')   // close braces
					if (brackets_stack.top() == '{') 
						brackets_stack.pop();   // pop from stack } 
					else {
						err = true;
						break;   // break loop on error	
					}   // end else top is {


			}   // end if !empty
			else {
				err = true; 
				break;   // break loop on error	
			}   // end else !empty
		}   // end for

	// Answer 
	cout << "\n";
	if (!err && brackets_stack.empty())
		cout << "Brackets are balanced.";
	else
		cout << "Are NOT balanced!"; 

	cout << endl << endl; 
	return 0; 	
}