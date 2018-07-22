/* Task-3-
Balanced () and [] and {}. 

CPP source file UTF-8, Linux.

Compiler on Ubuntu 16.04, version C++11 (ISO/IEC 14882:2011). 
*/ 

// 2 step with stack output to testing

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// to test stack
void showstack(stack <char> st)
{
    stack <char> temp = st;

    cout << "\n stack is ";
    while (!temp.empty())
    {
        cout << '\t' << temp.top();
        temp.pop();
    }
    cout << "<-- begin of text\n";
}

int main()
{   
	// terms: parentheses is round brackets () , brackets is square brackets [], braces is braces {} :)
	bool err_parentheses = false;   // balance error  

	int i;   // symbol position counter from 0 to text length - 1

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


	// stack of char declaration 
	stack <char> brackets_stack;

        
		// balance checking
		for (i = 0; /*second symbol text[1] */ i < count; i++) {

			if (text[i] == '(') {   // open parentheses
				brackets_stack.push(text[i]);

				// test stack after push()
				cout << "\nPush: ";
				showstack(brackets_stack);

			}   // end if == 

			if (!brackets_stack.empty()) {
				if (text[i] == ')')   // close parentheses
					if (brackets_stack.top() == '(') {
						brackets_stack.pop(); 

						// test stack after pop()
						cout << "\nPop: ";
						showstack(brackets_stack);
					}   // end if top is (
					else {
						err_parentheses = true;
						cout << "\nError top not ( !!! Loop break.\n";
						break;   // break loop on error	
					}   // end else top is (
			}   // end if empty
			else {
				err_parentheses = true;
				cout << "\nError stack is empty!!! Loop break.\n";
				break;   // break loop on error	
			}   // end else empty

			// test stack in loop, before next iteration
			cout << "\nIn loop in stack is ";
			showstack(brackets_stack);

		}   // end for

	// test stack after loop
	cout << "\nAfter loop in stack is ";
	showstack(brackets_stack);

	// Answer parentheses
	if (!err_parentheses && brackets_stack.empty())
		cout << " () is balanced.\n";
	else 
		cout << " () NOT balanced.\n";

	cout << endl << endl; 
	return 0; 	
}