/* Task-1-
Longest recurring sequence
With extra point - one loop

CPP source file UTF-8, Linux.

Compiler on Ubuntu 16.04, version C++11 (ISO/IEC 14882:2011). 
*/ 

#include <iostream>
using namespace std;

// function: longest recurring sequence
int longest_sequence(int arr[], int size) {

	int current_sequence_num; // current number
	int current_sequence_counter; // current counter
	int max_sequence = 0; // longest sequence in begin is 0

	int prev_number, prev_counter; // to save preveuse number and counter

	current_sequence_num = arr[0]; // current number is first array element 
	current_sequence_counter = 1; 

	for (int index=1; /*second array element*/ index <= size - 1; index++) 
		if (current_sequence_num == arr[index]) // if is sequence continue 
			current_sequence_counter++;
		else { 
			// if don't sequence continue
			if (current_sequence_counter >= max_sequence) {
				max_sequence = current_sequence_counter; // new longest sequence

				// save number and counter
				prev_number = current_sequence_num;
				prev_counter = current_sequence_counter; 
			} // end if >=

			// changed to new sequence 
			current_sequence_num = arr[index]; 
			current_sequence_counter = 1;

		} // end else of if ==

	// compare if last sequence is longest 
	if (current_sequence_counter >= max_sequence) {  
		// last sequence is longest 
		prev_number = current_sequence_num;
		prev_counter = current_sequence_counter; 
	} // end if >=

	//test 
    cout << "Sequence counter (prev_counter) is: " <<  prev_counter << "\n" 
         << "Sequence number (prev_number) is: " << prev_number << "\n\n"; 

	return prev_number; 
}

int main()
{
	const int size = 22; // array size

	// an int array with size elements.
	int static_array [] = {1,5,5,5,6,6,7,7,7,7,7,7,7,7,5,5,5,5,5,5,5,5}; 

	// test 
	cout << "Size: " << size << "\tArray: ";
	for (int i=0; i<=size-1;i++)
		cout << static_array[i] << " ";
	cout << endl;

	int recurring_seque; // longest recurring sequence number

		recurring_seque = longest_sequence(static_array, size);  // call function 

	/* // output result
	cout << "Longest recurring sequence is " << recurring_seque; */

	//test 
    cout << "Longest recurring sequence (recurring_seque) is: " << recurring_seque;

	cout << endl << endl; 
	return 0;
}