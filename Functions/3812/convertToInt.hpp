#ifndef CONVERTTOINT_H
#define CONVERTTOINT_H

#include "PROTOTYPES.hpp"

int convertToInt (string input) {
	bool isDigit = true; // creates a boolean
	
	for (int i = 0; i < input.length(); i++)
		
		if (!isdigit(input[i])) // if ANY of the characters in the input is NOT a digit
		
			isDigit = false; // set the boolean to false
		
		// else, boolean would be unchanged
	
	if (input.length() > 0) {
		int num = 0; // creates an empty integer
	
		if (isDigit) { // if all characters in input string are digits
			for (int i = 0; i < input.length(); i++)
				
				// Adds the ASCII digit characters to "int num"
				{
					num += (input[i] - 48) * pow(10, input.length() - 1 - i);
				}
			
			// returns the input as integer
			return num;
			
		} else
			// returns -1 (error) when user inputs a non-digit character
			return -1;
	} else
		return -1;
}

#endif