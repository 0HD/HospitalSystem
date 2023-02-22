#ifndef UPDATEFILEHISTORY_HPP
#define UPDATEFILEHISTORY_HPP

#include "../filesFuncs.hpp"

void updateFileHistory () {
	ifstream fileHistory;
	
	fileHistory.open("FileHistory");
	
	string fileNames[9] = {"", "", "", "", "", "", "", "", ""};
	
	if (fileHistory.is_open())
		for (int i = 0; i < 9; i++) {
			if (fileHistory.eof())
				break;
			getline(fileHistory, fileNames[i]);
		}
	else {
		ofstream outFile("FileHistory");
		outFile.close();
		fileHistory.close();
		return;
	}
	
	fileHistory.close();
	
	if (fileNames[0] != fileName) {
		// Puts fileName as the first value,
		// pushing everything below it
		for (int i = 8; i > 0; i--) {
			fileNames[i] = fileNames[i-1];
		}
		fileNames[0] = fileName;
	}
	
	string newHistory[9] = {"", "", "", "", "", "", "", "", ""};
	
	int *counter = new int; *counter = 0;
	int *indexcounter = new int; *indexcounter = 0;
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (fileNames[i] != newHistory[j]) {
				*counter += 1;
			}
		}
		if (*counter == 9) {
			newHistory[*indexcounter] = fileNames[i];
			(*indexcounter)++;
		}
		*counter = 0;
	}
	
	delete counter; delete indexcounter;
	
	ofstream outFile("FileHistory");
	
	if (outFile.is_open()) {
		for (int i = 0; i < 9; i++) {
			if (newHistory[i] != "")
				outFile << newHistory[i] << endl;
		}
	}
	
	outFile.close();
	
}

#endif