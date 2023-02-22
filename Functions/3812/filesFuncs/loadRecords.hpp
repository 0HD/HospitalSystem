#ifndef LOADRECORDS_HPP
#define LOADRECORDS_HPP

#include "../filesFuncs.hpp"

void loadRecords(Patient f[], int &NoP) {
	
	ifstream inFile;
	
	int row = 0, col = -4;
	
	string data = "";
	
	inFile.open(fileName);
	
	if (inFile.is_open()) {
		if (!inFile.eof()) {
			while (getline(inFile, data, ',')) {

				if (col == 1)
					f[row].patient.id = data;
				else if (col == 2)
					f[row].patient.name.first = data;
				else if (col == 3)
					f[row].patient.name.last = data;
				else if (col == 4)
					f[row].patient.gender = data[0];
				else if (col == 5)
					f[row].patient.dob.mm = convertToInt(data);
				else if (col == 6)
					f[row].patient.dob.dd = convertToInt(data);
				else if (col == 7)
					f[row].patient.dob.yy = convertToInt(data);
				else if (col == 8)
					f[row].medicine = data;
				else if (col == 9) {
					f[row].dose = convertToInt(data);
					cout << "\nLoaded record #" << row+1;
					row++;
					col = -1;
				}
				
				col++;
				data = "";
			}
		}
		updateFileHistory();
	}
	else {
		cout << "\nError! Couldn't load file.\n";
	}
	
	inFile.close();
	
	return;
	
}

#endif