#ifndef NUMBERINPUT_HPP
#define NUMBERINPUT_HPP

#include "../inputFuncs.hpp"

// Function that returns integer input from user
int numberInput () {
	
	string input = ""; // creates empty string
	getline(cin, input); // takes input from user, adds it to string
	
	return convertToInt(input);
}

#endif