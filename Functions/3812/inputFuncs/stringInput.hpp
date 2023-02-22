#ifndef STRINGINPUT_HPP
#define STRINGINPUT_HPP

#include "../inputFuncs.hpp"

string stringInput () {
	string input = "";
	getline(cin, input);
	return input;
}

string stringInput (string message) {
	string input = "";
	cout << message;
	getline(cin, input);
	return input;
}

#endif