#ifndef FILESMENUNAVIGATION_HPP
#define FILESMENUNAVIGATION_HPP

#include "../filesMenu.hpp"

void filesMenuNavigation() {
	
	getFilesMenuInput();
	
	if (isExit) { // When user selects "Exit"
		clear();
		printBox("         (X)  Exiting...         ");
	}
	
	else if (isLoadFile) { // When user selects "Load existing file"
		isLoadFile = false;
		loadFile();
	}
	
	else if (isRecentFiles) {
		isRecentFiles = false;
		
		clear();
		title("Hospital System - Recent Files");
		
		silentLoad = false;
		finishedLoadingFromHistory = false;
		loadFromHistory = false;
		fileName = "";
		
		inFile.open("FileHistory");
		
		int *counter = new int;
		string *tempString = new string;
		int *tempInt = new int;
		
		*counter = 1;
		
		if (inFile.is_open()) {
			
			printBox("      Showing recent files       ");
			
			cout << "  _______________ _____ _ _  __    _\n"
			        " |\n";
			while (getline(inFile, *tempString)) {
				cout << " |   [" << *counter << "] " << *tempString << endl;
//				cout << " |---|\n";
				*counter += 1;
			}
			cout << " |   [0] Go back to main menu\n";
			cout << " |_______________ _____ _ _  __    _\n";
			cout << "  _______________ _____ _ _  __    _\n"
					" |                                  \n"
					" '---> Please enter a number: ";
			*tempInt = numberInput();
			
			
			*counter = 1;
			
			inFile.close();
			inFile.open("FileHistory");
			
			while (getline(inFile, *tempString)) {
					if (*counter == *tempInt)
						fileName = *tempString;
					*counter += 1;
			}
			
			*tempInt = 0;
			
			if (fileName != "")
				while (*tempInt != 1 && *tempInt != 2) {
					clear();
					printBox("      Showing recent files       ");
					cout << "\nDo you want to load \"" + fileName + "\"?\n";
					cout << "\n1 - Yes\n2 - No\n\nEnter a number: ";
					*tempInt = numberInput();
					if (*tempInt == 1)
						break;
					else if (*tempInt == 2)
						fileName = "";
				}
			
			clear();
			
			if (fileName == "")
				printBox("     (!) No file was loaded      ");
			else {
				loadFromHistory = true;
				silentLoad = true;
			}
		} else {
			clear();
			printBox("   (!) File history not found    ");
		}
		
		delete tempString;
		delete tempInt;
		delete counter;
		
		inFile.close();
		
		
	}
	
	else if (isCreateFile) { // When user selects "Create new file"
		isCreateFile = false;
		
		clear();
		title("Hospital System - New File");
		printBox("      Creating new records       ");
		
		NoP = 0;
		
		cout << "\nPlease enter the array size: ";
		
		CurrentSize = numberInput();
		
		if (CurrentSize > 0) {
			Patient records[CurrentSize];
			
			cout << "\nPlease enter the new file name: ";
			
			fileName = "Records/" + stringInput() + ".txt";
			
			createFolder("Records");
			if (saveRecords(records) == -1) {
				clear();
				printError("Unable to save");
			} else {
				clear();
				printBox (  "    Success! You may find it     |\n"
							" |   in the recent records menu    ");
			}
		} else {
			clear();
			printError("Invalid size");
		}
		
	}
}

#endif