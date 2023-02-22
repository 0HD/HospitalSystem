#ifndef MENU_HPP
#define MENU_HPP

#include "../recordsMenu.hpp"

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
			
			case 1: {
				title(fileName + " - Hospital System - Adding to record #" + to_string(NoP+1));
				clear();
				
				int *feedback = new int;
				
				*feedback = newPatient(records);
				
				if (*feedback == 0) {
					clear();
					cout << "(+) Successfully added record #" + to_string(NoP) + "\n";
					break;
				}
				else if (*feedback == -1) {
					clear();
					cout << "(!) Record not added!\n";
					break;
				}
				else if (*feedback == -2) {
					clear();
					cout << "(!) You have too many records!\n";
					break;
				}
			}
			case 2: {
				bool *loop = new bool;
				*loop = true;
				clear();
				while (*loop) {
					title(fileName + " - Hospital System - Editing " + to_string(NoP) + " records");
					
					view(records, 0, NoP, 0);
					
					cout << "\n\n.--> [1] Update Record / [2] Delete Record / [0] Go Back\n"
							"|\n"
							"'-- What would you like to do? ";
					
					int input = numberInput();
					
					switch(input) {
						case 1: {
							title(fileName + " - Hospital System - Updating a record from " + to_string(NoP) + " records");
							clear();
							
							view(records, 0, NoP, 0);
							
							string IDinput = stringInput("\nEnter patient\'s ID: ");
							int index = findPatient(records, IDinput, NoP);
							
							if (index != -1) {
								clear();
								showNumbers = true;
								view(records, index, index+1, 0);
								showNumbers = false;
								
								cout << "Which value would you like to edit? ";
								
								int column = numberInput();
								
								if (column > 0 && column <= 7) {
									string input = stringInput("Enter the new value: ");
									updatePatient(records, IDinput, column, input, NoP);
								} else {
									clear();
									printError("Invalid option");
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
							
							int patientIndex = findPatient(records,stringInput(), NoP);
							
							if (patientIndex >= 0)
								deleteRecord(records, patientIndex);
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
				
				cout << "\n\nFind by (1) ID or by (2) name? ";
				
				int input = numberInput();
				
				if (input == 1) {
					title(fileName + " - Hospital System - Finding patient by ID");
					clear();
					
					cout << "(6) Finding patient by ID.\n";
					
					cout << "\n\nEnter patient\'s ID:\n";
					
					int* patientIndex = new int;
					*patientIndex = findPatient(records, stringInput());
					
					if (*patientIndex != -1) {
						clear();
						view(records, *patientIndex, *patientIndex+1, 0);
						delete patientIndex;
						cout << "\nEnter anything to continue." << stringInput();
						clear();
					}
					else {
						clear();
						cout << "Unable to find patient.\n";
					}
				}
				else if (input == 2) {
					title(fileName + " - Hospital System - Finding patient by name");
					clear();
					
					cout << "Find using first name or last name?\n1 for First, 2 for Last: ";
					
					*choice = numberInput();
					
					if (*choice == 1 || *choice == 2) {
						
						int* patientIndex = new int;
						*patientIndex = findPatient(records, stringInput("\n\nEnter name to find: "), *choice);
						
						if (*patientIndex != -1) {
							clear();
							view(records, *patientIndex, *patientIndex+1, 0);
							delete patientIndex;
							cout << "\nEnter anything to continue." << stringInput();
							clear();
						}
						else {
							clear();
							cout << "Unable to find patient.\n";
						}
					}
					else {
						clear();
						message = "Please enter a valid number.\n";
					}
				}
				else {
					clear();
					printError("Invalid option");
					break;
				}
				
				break;
			}
			
			case 4:
				title(fileName + " - Hospital System - Sorting " + to_string(NoP) + " records");
				clear();
				
				cout << "Enter 1 / 2 for ascending / descending respectively: ";
				
				sortPatients(records, numberInput(), NoP);
				
				clear();
				break;
				
			
			case 6: {
				clear();
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

#endif