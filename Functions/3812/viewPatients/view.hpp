#ifndef VIEW_HPP
#define VIEW_HPP

#include "../viewPatients.hpp"


void view(Patient records[], int first, int last, int highlight) {
	
	string ID = "ID", name = "First Name", lastName = "Last Name", gender = "Gender", DoB = "Birthdate", medicine = "Medicine", dose = "Dose (in micro)";
	
	if (showNumbers) {
		ID = "1. " + ID;
		name = "2. " + name;
		lastName = "3. " + lastName;
		gender = "4. " + gender;
		DoB = "5. " + DoB;
		medicine = "6. " + medicine;
		dose = "7. " + dose;
	}
	
	// Sets default character count in each column to the column's title length
	int maxID = ID.length(), maxName = name.length(), maxLastName = lastName.length();
	int maxGender = gender.length(), maxDoB = DoB.length(), maxMedicine = medicine.length(), maxDose = dose.length();
	
	// Replace the default length with the largest character count in each column for each row
	for (int i = first; i < last; i++) {
		maxID = maxCharacters (records[i].patient.id, maxID);
		maxName = maxCharacters (records[i].patient.name.first, maxName);
		maxLastName = maxCharacters (records[i].patient.name.last, maxLastName);
		maxGender = maxCharacters (to_string(records[i].patient.gender), maxGender);
		maxDoB = maxCharacters (to_string(records[i].patient.dob.yy) + "-MMM-" + to_string(records[i].patient.dob.dd), maxDoB);
		maxMedicine = maxCharacters (records[i].medicine, maxMedicine);
		maxDose = maxCharacters (to_string(records[i].dose), maxDose);
	}
	
	switch (highlight) {
		case 1:
			ID = ">" + ID + "<"; maxID += 2; break;
		case 2:
			name = ">First Name<"; maxName += 2; break;
		case 3:
			lastName = ">Last Name<"; maxLastName += 2;  break;
		case 4:
			gender = ">Gender<"; maxGender += 2; break;
		case 5:
			DoB = ">Birthdate<"; maxDoB += 2; break;
		case 6:
			medicine = ">Medicine<"; maxMedicine += 2; break;
		case 7:
			dose = ">Dose<"; maxDose += 2; break;
	}
	
	// Prints the top border line, with the total width adjusting for the largest character count in each row
	cout << " " << underscores(20 + maxID + maxName + maxLastName + maxGender + maxDoB + maxMedicine + maxDose) << "\n";
	
	// Prints the title for every column, and adds spaces if the data is too small, then adds the separator "|" character
	printColumns(columns, "| ", fillSpaces("", maxID), fillSpaces("", maxName), fillSpaces("", maxLastName), fillSpaces("", maxGender),
				fillSpaces("", maxDoB), fillSpaces("", maxMedicine), fillSpaces("", maxDose), "|\n");
		
	printColumns(columns, "| ", fillSpaces(ID, maxID), fillSpaces(name, maxName), fillSpaces(lastName, maxLastName),
				fillSpaces(gender, maxGender), fillSpaces(DoB, maxDoB), fillSpaces(medicine, maxMedicine), fillSpaces(dose, maxDose), "|\n");
	
	printColumns(columns, "|_", underscores(maxID + 1), underscores(maxName + 1), underscores(maxLastName + 1), underscores(maxGender + 1),
					underscores(maxDoB + 1), underscores(maxMedicine + 1), underscores(maxDose + 1), "|\n");

	// Prints the line below the column titles, with the total width adjusting for the largest character count in each row, separated by "|"
	printColumns(columns, "| ", fillSpaces("", maxID), fillSpaces("", maxName), fillSpaces("", maxLastName), fillSpaces("", maxGender),
				fillSpaces("", maxDoB), fillSpaces("", maxMedicine), fillSpaces("", maxDose), "|\n");
	
	string months[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	// Prints every row's data on separate lines, with the total width adjusting for the largest character count in each row
	for (int i = first; i < last; i++) {
		
		// Converts all data to strings
		string id = records[i].patient.id;
		string firstName = records[i].patient.name.first;
		string lastName = records[i].patient.name.last;
		string gender = string(1, records[i].patient.gender);
		string birthdate = to_string(records[i].patient.dob.yy) + "-" + months[records[i].patient.dob.mm - 1] + "-" + to_string(records[i].patient.dob.dd);
		string medicine = records[i].medicine;
		string dose = to_string(records[i].dose);
		
		// Prints the data for every column, and adds spaces if the data is too small, then adds the separator "|" character
		printColumns(columns, "| ", fillSpaces(id, maxID), fillSpaces(firstName, maxName), fillSpaces(lastName, maxLastName),
				fillSpaces(gender, maxGender), fillSpaces(birthdate, maxDoB), fillSpaces(medicine, maxMedicine), fillSpaces(dose, maxDose), "|\n");
	}
	
	printColumns(columns, "|_", underscores(maxID + 1), underscores(maxName + 1), underscores(maxLastName + 1), underscores(maxGender + 1),
					underscores(maxDoB + 1), underscores(maxMedicine + 1), underscores(maxDose + 1), "|\n");
}

#endif