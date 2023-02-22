#ifndef NEWPATIENT_HPP
#define NEWPATIENT_HPP

#include "../recordsMenu.hpp"

int newPatient (Patient records[]) {
    
    if (NoP >= CurrentSize) {
    	// If the array is full
		return -2;
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
							updatePatient(New, New[0].patient.id, column, valueinput, NoP);
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

#endif