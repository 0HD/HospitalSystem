#ifndef TITLE_HPP
#define TITLE_HPP

#include "../commands.hpp"

// Change terminal title (Windows-only)
void title(string str) {
	
	// For Windows
	#ifdef _WIN32
		
		string *title = new string; // Create temporary string
		
		*title = "title " + str; // Add title from the argument to the temporary string
		
		system((*title).c_str()); // Send command to the user's terminal
		
		delete title; // Delete the temporary string
	
	#endif
}

#endif