// Bassil AlZahrani, Anas AlGhamdi, Anas AlGhamdi, Ahmad Al Ohaid, Mohammad AlGhamdi

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Definitions

int NoP = 0; // Number of Patients

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
};

// Function Prototypes

void menu(Patient [], string);

void garbagerecords(Patient [], int const);

void view(Patient [], int, int);

int maxCharacters (string, int);

string underscores (int);

string fillSpaces (string, int);

void printColumns (int [], string, string, string, string, string, string, string, string, string);

void clear();

void title(string);

int main () {
	
	title("Hospital System - New File");
	
	int *input = new int; // temporary variable to store input from user
	
	cout << "Maximum amount of records allowed: ";
	cin >> *input; // store input in the temporary variable
	
	int const SIZE = *input; // create constant integer for the array size
	
	delete input; // delete the temporary variable from memory
	
	Patient records[SIZE]; // create a struct array
	
	garbagerecords(records, SIZE); // fill the struct array
	
	clear();
	
	title("Hospital System - " + to_string(NoP) + " Records");
	
	menu(records, "Welcome to the Hospital System.\n"); // start the program
	
	return 0;
}

void view(Patient records[], int first, int last) {
	
	clear();
	int columns[] = {1, 3, 2, 7, 6, 5, 4}; 
	
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
	cout << " " << underscores(20 + maxID + maxName + maxLastName + maxGender + maxDoB + maxMedicine + maxDose) << "\n";
	
	// Prints the title for every column, and adds spaces if the data is too small, then adds the separator "|" character
	printColumns(columns, "| ", fillSpaces("", maxID), fillSpaces("", maxName), fillSpaces("", maxLastName), fillSpaces("", maxGender),
				fillSpaces("", maxDoB), fillSpaces("", maxMedicine), fillSpaces("", maxDose), "|\n");
		
	printColumns(columns, "| ", fillSpaces("ID", maxID), fillSpaces("First Name", maxName), fillSpaces("Last Name", maxLastName),
				fillSpaces("Gender", maxGender), fillSpaces("Birthdate", maxDoB), fillSpaces("Medicine", maxMedicine), fillSpaces("Dose", maxDose), "|\n");
	
	printColumns(columns, "|_", underscores(maxID + 1), underscores(maxName + 1), underscores(maxLastName + 1), underscores(maxGender + 1),
					underscores(maxDoB + 1), underscores(maxMedicine + 1), underscores(maxDose + 1), "|\n");

	// Prints the line below the column titles, with the total width adjusting for the largest character count in each row, separated by "|"
	printColumns(columns, "| ", fillSpaces("", maxID), fillSpaces("", maxName), fillSpaces("", maxLastName), fillSpaces("", maxGender),
				fillSpaces("", maxDoB), fillSpaces("", maxMedicine), fillSpaces("", maxDose), "|\n");
	
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
		printColumns(columns, "| ", fillSpaces(id, maxID), fillSpaces(firstName, maxName), fillSpaces(lastName, maxLastName),
				fillSpaces(gender, maxGender), fillSpaces(birthdate, maxDoB), fillSpaces(medicine, maxMedicine), fillSpaces(dose, maxDose), "|\n");
	}
	
	printColumns(columns, "|_", underscores(maxID + 1), underscores(maxName + 1), underscores(maxLastName + 1), underscores(maxGender + 1),
					underscores(maxDoB + 1), underscores(maxMedicine + 1), underscores(maxDose + 1), "|\n");
}

void menu(Patient records[], string message) {
	
	int input = 0;
	
	while (true) {
		
		title("Hospital System - " + to_string(NoP) + " Records");
		
		cout << message << endl;
		message = "Welcome to the Hospital System.\n";
		
		cout << "\n(!) Number of records: " << NoP << endl << endl;
		
		cout << "Menu:\n"
				"1 - Add a patient\'s record\n"
				"2 - Delete a patient\'s record\n"
				"3 - Update a patient\'s record\n"
				"4 - Display all records\n"
				"5 - Sort records\n"
				"\nPlease enter a number: ";
		cin >> input;
		
		switch (input) {
			
			case 1:
				
				title("Hospital System - " + to_string(NoP) + " Records - Adding a record");
				clear();
				
				break;
			
			case 2:
				
				title("Hospital System - " + to_string(NoP) + " Records - Deleting a record");
				clear();
				
				break;
			
			case 3:
				
				title("Hospital System - " + to_string(NoP) + " Records - Updating a record");
				clear();
				
				break;
			
			case 4:
				
				title("Hospital System - " + to_string(NoP) + " Records - Displaying records");
				
				view(records, 0, NoP);				
				system("pause"); // REMOVE
				
				clear();
				
				break;
			
			case 5:
				
				title("Hospital System - " + to_string(NoP) + " Records - Sorting records");
				clear();
				
				break;
			
			default:
				
				clear();
				message = "Please enter a valid option.\n";
				
				break;
		}
	}
}

void garbagerecords(Patient records[], int const SIZE) {
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
	
	for (int i = 1; i <= amount; i++)
		underscores += "_";
	
	return underscores;
}

string fillSpaces (string str, int max) {
	
	while (str.length() < max)
		str += " ";
	
	return str + " ";
}

void printColumns (int columns[], string start, string col1, string col2, string col3, string col4, string col5, string col6, string col7, string end) {
	for (int i = 0; i < 7; i++) {
			cout << start;
			switch (columns[i]) {
				case 1:
					cout << col1; break;
				case 2:
					cout << col2; break;
				case 3:
					cout << col3; break;
				case 4:
					cout << col4; break;
				case 5:
					cout << col5; break;
				case 6:
					cout << col6; break;
				case 7:
					cout << col7; break;
			}
		}
	cout << end;
}

// Clear the terminal (OS-specific)
void clear() {
	
	// For Windows
	#ifdef _WIN32
		system("cls"); // Send "cls" command to the terminal
	
	// For everything else (assuming Unix-like)
	#else
		system("clear"); // Send "clear" command to the terminal
	
	#endif

}

// Change terminal title
void title(string str) {
	
	// For Windows
	#ifdef _WIN32
		
		string *title = new string; // Create temporary string
		
		*title = "title " + str; // Add title from the argument to the temporary string
		
		system((*title).c_str()); // Send command to the user's terminal
		
		delete title; // Delete the temporary string
	
	#endif
}