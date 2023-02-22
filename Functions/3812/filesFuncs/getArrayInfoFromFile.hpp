#ifndef GETARRAYINFO_HPP
#define GETARRAYINFO_HPP

#include "../filesFuncs.hpp"

void getArrayInfoFromFile () {
	
	inFile.open(fileName);
	
	if (inFile.is_open()) {
		string value = ""; // create empty string
		int i = -1; // create counter for the order of strings in the file
		
		while (getline(inFile, value, ',')) {
			
			if (i == 1) {
				// first string after the warning string
				setSize (convertToInt(value)); // load SIZE from file
				cout << "\nRecords maximum limit set";
			}
			if (i == 2) {
				// second string after the warning string
				setNoP (convertToInt(value)); // load NoP from file
				cout << "\nLoading " << NoP << " records";
			}
			if (i > 1)
				// stop after loading SIZE and NoP
				break;
			i++;
		}
	}
}

#endif