#ifndef ISFILECOMPATIBLE_HPP
#define ISFILECOMPATIBLE_HPP

#include "../filesFuncs.hpp"

bool isFileCompatible () {
	
	inFile.open(fileName);
	
	if (inFile.is_open()) {
		string value = "";
		while (getline(inFile, value, ',')) {
			if (value ==  "!!!!!!!!!!!!CS-221!!!!!!!!!!!!") {
				// if first string in the file is matching
				inFile.close();
				return true;
			}
		}
		inFile.close();
	}
	
	return false;
}

#endif