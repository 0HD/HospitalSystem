//// Basil AlZahrani, Anas AlGhamdi, Anas AlGhamdi, Ahmad Al Ohaid, Mohammad AlGhamdi

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//// Definitions

ifstream inFile;

int NoP = 0; // Number of Patients

int CurrentSize = 0; // Used to track the size globally

bool loadFromHistory = false; // Used to skip loading files manually

bool finishedLoadingFromHistory = false; // Used to show feedback after loading from history

bool silentLoad = false; // Used to stop printing messages temporarily

bool isExit = false;
bool isLoadFile = false;
bool isRecentFiles = false;
bool isCreateFile = false;

bool showNumbers = false; // Used to show columns numbers temporarily
bool showAllRecords = false; // Used to show all records

int currentYear = time(NULL) / 60 / 60 / 24 / 365 + 1970;
int currentMonth = (time(NULL) - ((currentYear - 1970) * 31556952)) / 60 / 60 / 24 / 30;
int currentDay = (time(NULL) - ((currentYear - 1970) * 31556952) - (currentMonth * 2628000)) / 60 / 60 / 24;

string fileName = "";

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
	string id;
	Name name;
	char gender;
	Date dob; // Date of Birth
};

struct Patient {
	Person patient;
	string medicine;
	int dose;
};

//// Function Prototypes

// Anas Ali Mastour AlGhamdi - 17 Functions:

int numberInput();

int convertToInt(string);

double convertToDouble (string);

string stringInput();

string stringInput(string);

void menu(Patient []);

void garbagerecords(Patient []);

void view(Patient [], int, int, int);

int maxCharacters (string, int);

string underscores (int);

string fillSpaces (string, int);

void printColumns (int [], string, string, string, string, string, string, string, string, string);

void clear();

void title(string);

int saveRecords(Patient []);

void loadRecords(Patient [], int &);

void deleteRecord(Patient [], int);

void printWelcomeMessage();

void printFilesMenu();

void printLoadMenu();

void filesMenuNavigation();

void loadFile();

bool isCompatible ();

void getArrayInfoFromFile ();

void setSize (int);

void setNoP (int);

void getFilesMenuInput();

void printError(string);

void createFolder(string);

int newPatient (Patient []);

void updateFileHistory ();

// Ahmad Al Ohaid:

int updatePatient(Patient [], string, int, string);

// Basil AlZahrani - 2 Functions:

int findPatient(Patient [], string);

int findPatient(Patient [], string, int);

// Anas Ali Mohammad AlGhamdi:

void sortPatients(Patient [], int);

// Mohammad AlGhamdi:

void addPatient (Patient[], Patient);

//// Function Definitions

int main () {
	
	printWelcomeMessage();
	
	while (true) {
		
		if (isExit)
			break;
		
		if (!silentLoad)
			printFilesMenu();
		
		filesMenuNavigation();
	}
	
	return 0;
}

int findPatient(Patient a[], string needed_id){ // Basil Al Zahrani 2220004116
    
	int middle = 0;
    int first = 0;
    int last = NoP-1;
    
	while(last - first > 1) {
        
		middle = (first + last) / 2;
        
        if (convertToDouble(a[middle].patient.id) == convertToDouble(needed_id))
            return middle;
        
		else if(convertToDouble(a[middle].patient.id) > convertToDouble(needed_id))
            first = middle + 1;
        
        else 
            last = middle - 1;
    }
    
    if (convertToDouble(a[first].patient.id) == convertToDouble(needed_id))
            return first;
    
    if (convertToDouble(a[last].patient.id) == convertToDouble(needed_id))
            return last;
    
	return -1;
}

int findPatient(Patient a[], string name, int choice){ // Basil Al Zahrani 2220004116
    
	if (choice == 1) {
		// Find using first name
		for (int i = 0; i < NoP; i++) {
			if (a[i].patient.name.first == name)
            	return i;
		}
	} else if (choice == 2) {
		// Find using last name
		for (int i = 0; i < NoP; i++) {
			if (a[i].patient.name.last == name)
            	return i;
		}
	} else
		// Invalid choice
		return -1;
	
    // When not found
	return -1;
}

//sort patients 
void sortPatients(Patient records[], int choice) { 
	Patient temp_patients;
	int i,j;
	if(NoP<2){
		cout<<"Nothing to sort"; 
		return;
	}
	if (choice == 1) {
		for ( i=0 ; i<NoP-1 ; i++ ) {
			for ( j=0; j<NoP-1; j++ ) {
				if(convertToDouble(records[j].patient.id)>convertToDouble(records[j+1].patient.id)) {
					temp_patients = records[j];
					records[j] = records[j+1];
					records[j+1] = temp_patients;
				}
			}
		}
	} else if (choice == 2) {
		for ( i=0 ; i<NoP-1 ; i++ ) {
			for ( j=0; j<NoP-1; j++ ) {
				if(convertToDouble(records[j].patient.id)<convertToDouble(records[j+1].patient.id)) {
					temp_patients = records[j];
					records[j] = records[j+1];
					records[j+1] = temp_patients;
				}
			}
		}
	}
	
	
	
}

void addPatient (Patient records[], Patient newPatient) {
	
	records[NoP].patient.id = newPatient.patient.id;
    records[NoP].patient.name.first = newPatient.patient.name.first;
    records[NoP].patient.name.last = newPatient.patient.name.last;
    records[NoP].patient.gender = newPatient.patient.gender;
    records[NoP].patient.dob.mm = newPatient.patient.dob.mm;
    records[NoP].patient.dob.dd = newPatient.patient.dob.dd;
    records[NoP].patient.dob.yy = newPatient.patient.dob.yy;
    records[NoP].medicine = newPatient.medicine;
    records[NoP].dose = newPatient.dose;
	NoP++;
	
}

int newPatient (Patient records[]) {
    
    if (NoP >= CurrentSize) {
    	return -1;
	}
    else {
	    Patient New[1];
	    
	    {
	    	New[0].patient.id = "00";
		    New[0].patient.name.first = "____";
		    New[0].patient.name.last = "____";
		    New[0].patient.gender = '?';
		    if (currentMonth > 0 && currentMonth <= 12)
				New[0].patient.dob.mm = currentMonth;
			else
				New[0].patient.dob.mm = 1;
		    if (currentDay > 0 && currentDay <= 31)
				New[0].patient.dob.dd = currentDay;
			else
				New[0].patient.dob.dd = 1;
		    New[0].patient.dob.yy = currentYear;
		    New[0].medicine = "";
		    New[0].dose = 0;
		}
	    
	    string input = "";
	    
	    string message = "(+) Adding patient information to record #" + to_string(NoP+1) + ":\n";

	    
		do {
			clear();
			cout << message;
			view(New,0,1,1);
			cout << "\n.-- Patient\'s ID:\n";
			input = stringInput("\'-> ");
		} while (convertToInt(input) == -1);
		New[0].patient.id = input;
		
		{
			clear();
			cout << message;
			view(New,0,1,2);
			cout << "\n.-- Patient\'s first name:\n";
			input = stringInput("\'-> ");
			New[0].patient.name.first = input;
		}
		{
			clear();
			cout << message;
			view(New,0,1, 3);
			cout << "\n.-- Patient\'s last name:\n";
			input = stringInput("\'-> ");
			New[0].patient.name.last = input;
		}
		
		do {
			clear();
			cout << message;
			view(New,0,1, 4);
			cout << "\n.-- Patient\'s gender:\n";
			input = stringInput("\'-> ");
		} while (toupper(input[0]) != 'M' && toupper(input[0]) != 'F');
		New[0].patient.gender = toupper(input[0]);
		
		do {
			clear();
			cout << message;
			view(New,0,1, 5);
			cout << "\n.-- Patient\'s birthdate:\n";
			cout << "|-- Day:\n";
			input = stringInput("\'-> ");
		} while (convertToInt(input) <= 0 || convertToInt(input) > 31);
		New[0].patient.dob.dd = convertToInt(input);
		
		do {
			clear();
			cout << message;
			view(New,0,1, 5);
			cout << "\n.-- Patient\'s birthdate:\n";
			cout << "|-- Month:\n";
			input = stringInput("\'-> ");
		} while (convertToInt(input) <= 0 || convertToInt(input) > 12);
		New[0].patient.dob.mm = convertToInt(input);
		
		do {
			clear();
			cout << message;
			view(New,0,1, 5);
			cout << "\n.-- Patient\'s birthdate:\n";
			cout << "|-- Year:\n";
			input = stringInput("\'-> ");
		} while (convertToInt(input) < 1900 || convertToInt(input) > currentYear);
		New[0].patient.dob.yy = convertToInt(input);
		
		{
			clear();
			cout << message;
			view(New,0,1, 6);
			cout << "\n.-- Patient\'s medicine:\n";
			input = stringInput("\'-> ");
			New[0].medicine = input;
		}
		
		do {
			clear();
			cout << message;
			view(New,0,1, 7);
			cout << "\n.-- Medicine dose:\n";
			input = stringInput("\'-> ");
		} while (convertToInt(input) == -1);
		New[0].dose = convertToInt(input);
		
		while (true) {
			clear();
			cout << message;
			view(New,0,1, 0);
			cout << "\n(!) Is this information correct? (Y/N)\n";
			input = stringInput();
			
			if (tolower(input[0]) == 'n') {
//				deleteRecord(arrayName,NoP);
				while (true) {
					clear();
					cout << message;
					view(New,0,1, 5);
					cout << "\n(!) Is there a value you\'d like to fix? (Y/N)\n";
					input = stringInput();
					
					if (tolower(input[0] == 'n')) {
						clear();
						cout << message;
						view(New,0,1, 5);
						cout << "\n(!) Would you like to add this record? (Y/N)\n";
						input = stringInput();
					
						if (tolower(input[0] == 'n'))
							return -1;
					
						else if (tolower(input[0]) == 'y')
							addPatient(records, New[0]);
							return 0;
					
					}
						
					else if (tolower(input[0]) == 'y') {
						clear();
						showNumbers = true;
						view(New, 0, 1, 0);
						showNumbers = false;
						
						cout << "\n(!) Which value would you like to edit? ";
						
						int column = numberInput();
						
						if (column > 0 && column <= 7) {
							string valueinput = stringInput("Enter the new value: ");
							updatePatient(New, New[0].patient.id, column, valueinput);
						}
					}
					
				}
				return 0;
			}
			else if (tolower(input[0]) == 'y') {
				addPatient(records, New[0]);
				return 0;
			}
		}
	}
}

int updatePatient(Patient a[], string id, int choice, string newData) {
  
  	int index = findPatient(a, id);
  
  	switch (choice) {
    	case 1:
			a[index].patient.id = newData;
			break;
		case 2:
			a[index].patient.name.first = newData;
			break;
		case 3:
			a[index].patient.name.last = newData;
			break;
		case 4:
			a[index].patient.gender = newData[0];
			break;
		case 5:
			a[index].patient.dob.mm = convertToInt(newData);
			break;
		case 6:
			a[index].patient.dob.dd = convertToInt(newData);
			break;
		case 7:
			a[index].patient.dob.yy = convertToInt(newData);
			break;
		case 8:
			a[index].medicine = newData;
			break;
		case 9:
			a[index].dose = convertToDouble(newData);
    	default:
	      	return -1;
	      	break;
  }
  return 0;
}

void deleteRecord(Patient a[], int index) {
	
    for(int i = index; i < NoP - 1; i++) {
    	a[i].patient.id = a[i+1].patient.id;
      	a[i].patient.gender = a[i+1].patient.gender;
      	a[i].patient.name.first = a[i+1].patient.name.first;
      	a[i].patient.name.last = a[i+1].patient.name.last;
      	a[i].patient.dob.dd = a[i+1].patient.dob.dd;
      	a[i].patient.dob.mm = a[i+1].patient.dob.mm;
      	a[i].patient.dob.yy = a[i+1].patient.dob.yy;
      	a[i].medicine = a[i+1].medicine;
      	a[i].dose = a[i+1].dose;
	}
    
	NoP--;
  
}

void view(Patient records[], int first, int last, int highlight) {
	
	int columns[] = {1, 2, 3, 4, 5, 6, 7}; 
	
	
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

void menu(Patient records[]) {
	
	clear();
	
	string message = "(?) Number of records: " + to_string(NoP) + "\n";
	
	int *choice = new int;
	
	while (true) {
		
		title(fileName + " - Hospital System - Displaying " + to_string(NoP) + " records");
		
		cout << message << endl;
		message = "(?) Number of records: " + to_string(NoP) + "\n";
		
		
		
		if (NoP > 5 && showAllRecords == false) {
			cout << "\n* Showing last 5 records:\n";
			view(records, NoP-5, NoP, 0);
		}
		else {
			cout << "\n* Showing all records:\n";
			view(records, 0, NoP, 0);
		}
		
		string allRecords = "";
		if (showAllRecords)
			allRecords = "Show Last 5 Records";
		else
			allRecords = "Show All Records";
		
		cout << "\n __\\ [1] Add Record / [2] Edit Record / [3] Find Record / [4] Sort Records\n"
				"|  /    [5] Rearrange Columns / [6] " + allRecords + " / [0] Save and Exit\n"
				"|\n"
				"'-- What would you like to do? ";
		
//		cout << "Options:\n\n"
//				"1 -> Add a patient\'s record\n"
//				"2 -> Delete a patient\'s record\n"
//				"3 -> Update a patient\'s record\n"
//				"4 -> Display all records\n"
//				"5 -> Sort records\n"
//				"6 -> Find patient by ID\n"
//				"7 -> Find patient by name\n"
//				"\n0 -> Save and return to main menu\n"
//				"\nPlease enter a number: ";
		
		switch (numberInput()) {
			
			case 0:
				
				clear();
				
				cout << "(+) Saving as a new file \n";
				cout << "\nEnter file name:\n> ";
			
				fileName = stringInput();
				
				if (saveRecords(records) != 0)
					message = "Couldn't save file! Enter \"221\" to exit without saving.";
				else
					return;
				
				break;
			
			case 221:
				clear();
				
				return;
			
			case 1:
				
				title(fileName + " - Hospital System - Adding to record #" + to_string(NoP+1));
				clear();
				
				if (newPatient(records) == 0) {
					clear();
					cout << "(+) Successfully added record #" + to_string(NoP) + "\n";
				}
				else {
					clear();
					cout << "(!) Record not added!\n";
					break;
				}
				clear();
				break;
			
			case 2: {
				bool *loop = new bool;
				*loop = true;
				clear();
				while (*loop) {
					title(fileName + " - Hospital System - Editing " + to_string(NoP) + " records");
				
					cout << "\n\n.--> [1] Update Record / [2] Delete Record / [0] Go Back\n"
							"|\n"
							"'-- What would you like to do? ";
					
					int input = numberInput();
					
					switch(input) {
						case 1: {
							title(fileName + " - Hospital System - Updating a record from " + to_string(NoP) + " records");
							clear();
							
							string IDinput = stringInput("Enter patient\'s ID: ");
							int index = findPatient(records, IDinput);
							
							if (index != -1) {
								clear();
								showNumbers = true;
								view(records, index, index+1, 0);
								showNumbers = false;
								
								cout << "Which value would you like to edit? ";
								
								int column = numberInput();
								
								if (column > 0 && column <= 7) {
									string input = stringInput("Enter the new value: ");
									updatePatient(records, IDinput, column, input);
								} else {
									clear();
									cout << "Invalid value.";
								}
							}
							else {
								clear();
								cout << "Couldn't find patient.";
							}
							
							break;
						}
						case 2: {
							title(fileName + " - Hospital System - Deleting a record from " + to_string(NoP) + " records");
							clear();
							
							cout << "(2) Deleting a patient\'s record.\n";
							
							cout << "\nEnter patient ID: ";
							
							int patientID = findPatient(records,stringInput());
							
							if (patientID >= 0)
								deleteRecord(records, patientID);
							else
								message = "Patient not found\n";
							
							clear();
							break;
						}
						case 0: {
							*loop = false;
							break;
						}
						default: {
							clear();
							printError("Invalid option");
							break;
						}
					}
				}
				delete loop;
				clear();
				break;
			}
			
			case 3: {
				title(fileName + " - Hospital System - Finding a record");
				clear();
				
				cout << "Find by (1) name or by (2) ID? ";
				
				int input = numberInput();
				
				if (input == 1) {
					title(fileName + " - Hospital System - Finding patient by ID");
					clear();
					
					cout << "(6) Finding patient by ID.\n";
					
					cout << "\nEnter patient\'s ID:\n";
					cout << findPatient(records,stringInput());
				}
				else if (input == 2) {
					title(fileName + " - Hospital System - Finding patient by name");
					clear();
					
					cout << "Find using first name or last name?\n1 for First, 2 for Last: ";
					
					*choice = numberInput();
					
					if (*choice == 1 || *choice == 2)
						cout << findPatient(records, stringInput("Enter name to find: "), *choice);
					else
						message = "Please enter a valid number.\n";
					
					clear();
				}
				else {
					clear();
					printError("Invalid option");
					break;
				}
				
				clear();
				break;
			}
			
			case 4:
				title(fileName + " - Hospital System - Sorting " + to_string(NoP) + " records");
				clear();
				
				cout << "Enter 1 / 2 for ascending / descending respectively: ";
				
				sortPatients(records, numberInput());
				
				clear();
				break;
				
			
			case 6: {
				if (showAllRecords == true)
					showAllRecords = false;
				else
					showAllRecords = true;
				break;
			}
			
			default:
				
				clear();
				message = "(!) Please enter a valid option.\n";
				
				break;
		}
	}
	
	delete choice;
}

void loadRecords(Patient f[], int &NoP) {
	
	ifstream inFile;
	
	int row = 0, col = -4;
	
	string data = "";
	
	inFile.open(fileName);
	
	if (inFile.is_open()) {
		if (!inFile.eof()) {
			while (getline(inFile, data, ',')) {

				switch (col) {
					case 1:
						f[row].patient.id = data;
						break;
					case 2:
						f[row].patient.name.first = data;
						break;
					case 3:
						f[row].patient.name.last = data;
						break;
					case 4:
						f[row].patient.gender = data[0];
						break;
					case 5:
						f[row].patient.dob.mm = convertToInt(data);
						break;
					case 6:
						f[row].patient.dob.dd = convertToInt(data);
						break;
					case 7:
						f[row].patient.dob.yy = convertToInt(data);
						break;
					case 8:
						f[row].medicine = data;
						break;
					case 9:
						f[row].dose = convertToDouble(data);
						cout << "\nLoaded record #" << row+1;
						row++;
						col = -1;
						break;	
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

int saveRecords(Patient f[]) {
	
	ofstream outFile;
	
	int row = 0, col = -2;
	
	outFile.open(fileName);
	
	outFile <<  "!!!!!!!!!!!!CS-221!!!!!!!!!!!!,\n";
	outFile <<	"!!                          !!\n";
	outFile <<	"!!         WARNING!         !!\n";
	outFile <<	"!!                          !!\n";
	outFile <<	"!! This is a database file  !!\n";
	outFile <<	"!! for the Hospital System. !!\n";
	outFile <<	"!! You are not supposed to  !!\n";
	outFile <<	"!! open this directly.      !!\n";
	outFile <<	"!!                          !!\n";
	outFile <<	"!! Please use the Hospital  !!\n";
	outFile <<	"!! System app to read this  !!\n";
	outFile <<	"!! database.                !!\n";
	outFile <<	"!!                          !!\n";
	outFile <<	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	outFile <<	",";
	
	outFile << CurrentSize << ',';
	
	outFile << NoP << ',';
	
	if (outFile.is_open())
		for (int i = 0; i < NoP; i++) {
			outFile << endl << ',';
			outFile << f[i].patient.id << ',';
			outFile << f[i].patient.name.first << ',';
			outFile << f[i].patient.name.last << ',';
			outFile << f[i].patient.gender << ',';
			outFile << f[i].patient.dob.mm << ',';
			outFile << f[i].patient.dob.dd << ',';
			outFile << f[i].patient.dob.yy << ',';
			outFile << f[i].medicine << ',';
			outFile << f[i].dose << ',';
		} 
	else {
		cout << "\nError! Couldn't save file.\n";
		return -1;
	}
	
	outFile.close();
	
	return 0;
}

void updateFileHistory () {
	ifstream fileHistory;
	
	fileHistory.open("FileHistory");
	
	string fileNames[5] = {"", "", "", "", ""};
	
	if (fileHistory.is_open())
		for (int i = 0; i < 5; i++) {
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
		ofstream outFile("FileHistory");
		
		if (outFile.is_open()) {
			for (int i = 4; i > 0; i--) {
				fileNames[i] = fileNames[i-1];
			}
			outFile << fileName << endl;
			for (int i = 1; i < 5; i++) {
				if (fileNames[i] != "")
					outFile << fileNames[i] << endl;
			}
		}
		
		outFile.close();
	}
	
}

// Function that returns integer input from user
int numberInput () {
	
	string input = ""; // creates empty string
	getline(cin, input); // takes input from user, adds it to string
	
	return convertToInt(input);
}

int convertToInt (string input) {
	bool isDigit = true; // creates a boolean
	
	for (int i = 0; i < input.length(); i++)
		
		if (!isdigit(input[i])) // if ANY of the characters in the input is NOT a digit
		
			isDigit = false; // set the boolean to false
		
		// else, boolean would be unchanged
	
	if (input.length() > 0) {
		int num = 0; // creates an empty integer
	
		if (isDigit) { // if all characters in input string are digits
			for (int i = 0; i < input.length(); i++)
				
				// Adds the ASCII digit characters to "int num"
				{
					num += (input[i] - 48) * pow(10, input.length() - 1 - i);
				}
			
			// returns the input as integer
			return num;
			
		} else
			// returns -1 (error) when user inputs a non-digit character
			return -1;
	} else
		return -1;
}

double convertToDouble (string input) {
	bool isDigit = true; // creates a boolean
	
	for (int i = 0; i < input.length(); i++)
		
		if (!isdigit(input[i])) // if ANY of the characters in the input is NOT a digit
		
			isDigit = false; // set the boolean to false
		
		// else, boolean would be unchanged
	
	if (input.length() > 0) {
		double num = 0; // creates an empty integer
	
		if (isDigit) { // if all characters in input string are digits
			for (int i = 0; i < input.length(); i++)
				
				// Adds the ASCII digit characters to "int num"
				{
					num += (input[i] - 48) * pow(10, input.length() - 1 - i);
				}
			
			// returns the input as integer
			return num;
			
		} else
			// returns -1 (error) when user inputs a non-digit character
			return -1;
	} else
		return -1;
}

string stringInput () {
	string input = "";
	getline(cin, input);
	return input;
}

string stringInput (string message) {
	string input = "";
	cout << message;
	getline(cin, input);
	return input;
}

void garbagerecords(Patient records[]) {
	for (int i = 0; i < CurrentSize; i++) {
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

void printWelcomeMessage () {
	title("Hospital System");
	
	cout << "(?) Welcome to the Hospital System\n";
}

void printFilesMenu () {
	title("Hospital System");
	
	cout << "\nMain Menu:\n\n";
	cout << "1 -> Load existing file\n"
			"2 -> Recently opened files\n"
			"3 -> Create new file\n"
			"0 -> Exit\n";
	
	cout << "\nPlease enter a number: ";
}

void printLoadMenu () {
	clear();
	title("Hospital System - Load File");

	cout << "(=) Loading existing file.\n";
	cout << "\nEnter file name:\n> ";
}

void printError (string message) {
	if (message == "Invalid option") {
		cout << "(!) Invalid option.\n"
				" |\n"
				" \'-> Please enter a number corresponding to one of\n"
				"     the available options.\n";
	}
	else if (message == "Unable to load") {
		cout << "(!) Couldn't load the file.\n"
					" |\n"
					" \'-> We have found the file, but we were unable to load\n"
					"     it. The file might be incompatible or corrupted.\n";
	}
	else if (message == "File not found") {
		cout << "(!) Unable to find the file.\n"
				" |\n"
				" \'-> Possible cause is that the file does not exist,\n"
				"     or you have entered an incorrect file path.\n";
	}
	
}

void getFilesMenuInput () {
	if (loadFromHistory)
		isLoadFile = true;
	else if (finishedLoadingFromHistory)
		isRecentFiles = true;
	else {
		int input = numberInput();
		switch (input) {
			case 0:
				isExit = true;
				break;
			case 1:
				isLoadFile = true;
				break;
			case 2:
				isRecentFiles = true;
				break;
			case 3:
				isCreateFile = true;
				break;
			default:
				clear();
				printError("Invalid option");
		}
	}
}

void filesMenuNavigation() {
	
	getFilesMenuInput();
	
	if (isExit) { // When user selects "Exit"
		clear();
		cout << "(X) Exiting...";
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
			cout << "(*) Showing recent files.\n";
			
			cout << "\nFiles opened recently:\n\n";
			while (getline(inFile, *tempString)) {
				cout << *counter << " -> " << *tempString << endl;
				*counter += 1;
			}
			cout << "\n0 -> Go back to main menu\n";
			cout << "\nWhich file do you want to open?\nEnter a number: ";
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
					cout << "(*) Showing recent files.\n";
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
				cout << "(X) No file was loaded\n";
			else {
				loadFromHistory = true;
				silentLoad = true;
			}
		} else {
			clear();
			cout << "(X) File history not found";
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
		cout << "(+) Creating new file.\n";
		
		NoP = 0;
		
		cout << "\nPlease enter the array size: ";
		
		CurrentSize = numberInput();
		
		if (CurrentSize > 0) {
			Patient records[CurrentSize];
			
			cout << "\nPlease enter the new file name: ";
			
			fileName = "Records/" + stringInput();
			
			if (fileName != "") {
				createFolder("Records");
				saveRecords(records);
			}
			else
				cout << "\nInvalid file name.\n";
		} else {
			cout << "\nInvalid number.\n";
		}
		
	}
}

void loadFile() {
	
	if (!silentLoad) {
		printLoadMenu();
	}
	
	if (!loadFromHistory) // if not already loading file from history
		fileName = "Records/" + stringInput(); // Takes input from user, stores in fileName global variable
	else
		finishedLoadingFromHistory = true; // Return to case 2 once case 1 ends
	
	loadFromHistory = false; // Cancel skipping for future iterations of the loop
	
	inFile.open(fileName); // Attempt opening the file inputted by the user
	
	if (inFile.is_open()) { // if file was successfully opened
		
		inFile.close();
		
		if (isCompatible()) { // if inputted file was confirmed to be compatible
			
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

bool isCompatible () {
	
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
	}
	
	return false;
}

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

void setNoP (int value) {
	NoP = value;
}

void setSize (int value) {
	CurrentSize = value;
}

void createFolder(string folderName) {
	
	string *temp = new string; // Create temporary string
	
	*temp = folderName; // Add folder name from the argument to the temporary string
	
	#ifdef _WIN32
		*temp = "if not exist \"" + *temp + "\" mkdir -p \"" + *temp + "\"";
		system((*temp).c_str()); // Send "create folder" command to the terminal
	#else
		*temp = "mkdir -p \"" + *temp + "\"";
		system((*temp).c_str()); // Send "create folder" command to the terminal
	#endif
	
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