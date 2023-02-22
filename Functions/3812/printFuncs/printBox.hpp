#ifndef PRINTBOX_HPP
#define PRINTBOX_HPP

#include "../printFuncs.hpp"

void printBox (string message) {
	cout << "  _________________________________\n"
			" |                                 |\n";
	cout << " |"        << message <<          "|\n";
	cout << " |_________________________________|\n";
}

#endif