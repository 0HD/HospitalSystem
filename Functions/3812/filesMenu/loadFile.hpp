#ifndef LOADFILE_HPP
#define LOADFILE_HPP

#include "../filesMenu.hpp"

void loadFile() {
	
	if (!silentLoad) {
		printLoadMenu();
	}
	
	if (!loadFromHistory) // if not already loading file from history
		fileName = stringInput(); // Takes input from user, stores in fileName global variable
	else
		finishedLoadingFromHistory = true; // Return to case 2 once case 1 ends
	
	loadFromHistory = false; // Cancel skipping for future iterations of the loop
	
	inFile.open(fileName); // Attempt opening the file inputted by the user
	
	if (inFile.is_open()) { // if file was successfully opened
		
		inFile.close();
		
		if (isFileCompatible()) { // if inputted file was confirmed to be compatible
			
			getArrayInfoFromFile();
			
			// create a struct array from loaded size
			Patient records[CurrentSize];
			
			// run function to load the records from the file into the struct array
			loadRecords(records, NoP);
			
			clear();
			
			title("Hospital System - File: \"" + fileName + "\" - " + to_string(NoP) + " Records");
			
			menu(records); // start the program
			
			// after user exits the menu
			clear();
		
			inFile.close(); // close the file
			
			// print a feedback message and go back to the files menu
			cout << "(X) Closed file.\n";
			
		} else { // if inputted file was incompatible
			
			
			inFile.close(); // close the file
			
			// print an error message and go back to the files menu
			if (!silentLoad) {
				clear();
				
				printError("Unable to load");
			}
		}
	}
	else { // if inputted file was not open
		
		inFile.close(); // close the file, just in case it was somehow open
		
		// print an error message and go back to the files menu
		if (!silentLoad) {
			clear();
			
			printError("File not found");
		}
	}
}

#endif