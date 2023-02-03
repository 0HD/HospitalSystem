// Bassil AlZahrani, Anas AlGhamdi, Anas AlGhamdi, Ahmad Al Ohaid, Mohammad AlGhamdi

#include <iostream>
#include <string>

using namespace std;

// Definitions

int NoP = 0; // Number of Patients

int const SIZE = 5;

struct Name {
	string first; // First name
	string last; // Last name
};

struct Date {
	int dd; // Day
	int mm; // Month
	int yy; // Year
};

struct Person {
	int id;
	Name name;
	char gender;
	Date dob; // Date of Birth
};

struct Patient {
	Person patient;
	string medicine;
	double dose;
} records[SIZE];

// Function Prototypes

void menu(string);

void garbagerecords();

void view(int, int);

int maxCharacters (string, int);

string underscores (int);

string fillSpaces (string, int);

int main () {
	garbagerecords();
	
	menu("Welcome to the Hospital System.");
	
	return 0;
}

void view(int first, int last) {
	
	// Sets default character count in each column to the column's title length
	int maxID = 2, maxName = 10, maxLastName = 9, maxGender = 6, maxDoB = 9, maxMedicine = 8, maxDose = 4;
	
	// Replace the default length with the largest character count in each column for each row
	for (int i = 0; i < NoP; i++) {
		maxID = maxCharacters (to_string(records[i].patient.id), maxID);
		maxName = maxCharacters (records[i].patient.name.first, maxName);
		maxLastName = maxCharacters (records[i].patient.name.last, maxLastName);
		maxGender = maxCharacters (to_string(records[i].patient.gender), maxGender);
		maxDoB = maxCharacters (to_string(records[i].patient.dob.mm) + "/" + to_string(records[i].patient.dob.dd) + "/" + to_string(records[i].patient.dob.yy), maxDoB);
		maxMedicine = maxCharacters (records[i].medicine, maxMedicine);
		maxDose = maxCharacters (to_string(records[i].dose), maxDose);
	}
	
	// Prints the top border line, with the total width adjusting for the largest character count in each row
	cout << " _" << underscores(maxID) << "__" << underscores(maxName) << "__" << underscores(maxLastName) << "__" << underscores(maxGender) << "__" << underscores(maxDoB) << "__" << underscores(maxMedicine) << "__" << underscores(maxDose) << "\n";
	
	// Prints the title for every column, and adds spaces if the data is too small, then adds the separator "|" character
	cout << "| " << fillSpaces("", maxID) << "| " << fillSpaces("", maxName) << "| " << fillSpaces("", maxLastName) << "| " << fillSpaces("", maxGender) << "| " << fillSpaces("", maxDoB) << "| " << fillSpaces("", maxMedicine) << "| " << fillSpaces("", maxDose) <<"|\n";
	cout << "| " << fillSpaces("ID", maxID) << "| " << fillSpaces("First Name", maxName) << "| " << fillSpaces("Last Name", maxLastName) << "| " << fillSpaces("Gender", maxGender) << "| " << fillSpaces("Birthdate", maxDoB) << "| " << fillSpaces("Medicine", maxMedicine) << "| " << fillSpaces("Dose", maxDose) <<"|\n";
	
	// Prints the line below the column titles, with the total width adjusting for the largest character count in each row, separated by "|"
	cout << "|_" << underscores(maxID) << "|_" << underscores(maxName) << "|_" << underscores(maxLastName) << "|_" << underscores(maxGender) << "|_" << underscores(maxDoB) << "|_" << underscores(maxMedicine) << "|_" << underscores(maxDose) << "|\n";
	cout << "| " << fillSpaces("", maxID) << "| " << fillSpaces("", maxName) << "| " << fillSpaces("", maxLastName) << "| " << fillSpaces("", maxGender) << "| " << fillSpaces("", maxDoB) << "| " << fillSpaces("", maxMedicine) << "| " << fillSpaces("", maxDose) <<"|\n";
	
	// Prints every row's data on separate lines, with the total width adjusting for the largest character count in each row
	for (int i = first; i < last; i++) {
		
		// Converts all data to strings
		string id = to_string(records[i].patient.id);
		string firstName = records[i].patient.name.first;
		string lastName = records[i].patient.name.last;
		string gender = string(1, records[i].patient.gender);
		string birthdate = to_string(records[i].patient.dob.mm) + "/" + to_string(records[i].patient.dob.dd) + "/" + to_string(records[i].patient.dob.yy);
		string medicine = records[i].medicine;
		string dose = to_string(records[i].dose);
		
		// Prints the data for every column, and adds spaces if the data is too small, then adds the separator "|" character
		cout << "| " << fillSpaces(id, maxID) << "| " << fillSpaces(firstName, maxName) << "| " << fillSpaces(lastName, maxLastName) << "| " << fillSpaces(gender, maxGender) << "| " << fillSpaces(birthdate, maxDoB) << "| " << fillSpaces(medicine, maxMedicine) << "| " << fillSpaces(dose, maxDose) <<"|\n";
	}
	
	// Prints the bottom border line, with the total width adjusting for the largest character count in each row, separated by "|"
	cout << "|_" << underscores(maxID) << "|_" << underscores(maxName) << "|_" << underscores(maxLastName) << "|_" << underscores(maxGender) << "|_" << underscores(maxDoB) << "|_" << underscores(maxMedicine) << "|_" << underscores(maxDose) << "|\n";
}

void menu(string message) {
	int input = 0;
	while (true) {
	cout << message << endl;
	cout << "(!) Number of records: " << NoP << endl << endl;
	cout << "Menu:" << endl;
	cout << "1 - Add a patient\'s record" << endl;
	cout << "2 - Delete a patient\'s record" << endl;
	cout << "3 - Update a patient\'s record" << endl;
	cout << "4 - Display all records" << endl;
	cout << "5 - Sort records by scores" << endl;
	cout << "\nPlease enter a number: ";
	cin >> input;
	switch (input) {
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			view(0, NoP);
			break;
		case 5:
			break;
		default:
			system("cls");
			cout << "\nPlease enter a valid option." << endl;
			break;
		}
	}
}

void garbagerecords() {
	for (int i = 0; i < SIZE; i++) {
		records[i].patient.id = i+1;
		records[i].patient.name.first = "A";
		records[i].patient.name.last = "A";
		records[i].patient.gender = 'M';
		records[i].patient.dob.dd = i;
		records[i].patient.dob.mm = i;
		records[i].patient.dob.yy = i;
		records[i].medicine = "A";
		records[i].dose = i;
		NoP++;
	}
}


int maxCharacters (string str, int max) {
	if (str.length() > max)
			return str.length();
	else
		return max;
}

string underscores (int amount) {
	
	string underscores = "";
	
	for (int i = 0; i <= amount; i++)
		underscores += "_";
	
	return underscores;
}

string fillSpaces (string str, int max) {
	
	while (str.length() < max)
		str += " ";
	
	return str + " ";
}

