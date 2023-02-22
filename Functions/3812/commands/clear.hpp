#ifndef CLEAR_HPP
#define CLEAR_HPP

#include "../commands.hpp"

// Clear the terminal (OS-specific)
void clear() {
	
	// For Windows
	#ifdef _WIN32
		system("cls"); // Send "cls" command to the terminal
	
	// For everything else (assuming Unix-like)
	#else
		system("clear"); // Send "clear" command to the terminal
	
	#endif

}

#endif