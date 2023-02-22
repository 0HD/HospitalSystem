#ifndef CREATEFOLDER_HPP
#define CREATEFOLDER_HPP

#include "../commands.hpp"

// Create a folder next to the program (OS-specific)
void createFolder(string folderName) {
	
	string *temp = new string; // Create temporary string
	
	*temp = folderName; // Add folder name from the argument to the temporary string
	
	// For Windows
	#ifdef _WIN32
		// Appends the cmd command to "*temp"
		*temp = "if not exist \"" + *temp + "\" mkdir -p \"" + *temp + "\"";
		system((*temp).c_str()); // Send "create folder" command to the terminal
	
	// For everything else (assuming Unix-like)
	#else
		// Appends the shell command to "*temp"
		*temp = "mkdir -p \"" + *temp + "\"";
		system((*temp).c_str()); // Send "create folder" command to the terminal
	#endif
	
}

#endif