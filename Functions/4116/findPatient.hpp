#ifndef FINDPATIENT_H
#define FINDPATIENT_H

#include "../../headers.hpp"

// Basil AlZahrani - 2220004116

int findPatient(Patient a[], string needed_id, int NoP){ // Basil Al Zahrani 2220004116
    
	int middle = 0;
    int first = 0;
    int last = NoP-1;
    
	while(last - first > 1) {
        
		middle = (first + last) / 2;
        
        if (convertToInt(a[middle].patient.id) == convertToInt(needed_id))
            return middle;
        
		else if(convertToInt(a[middle].patient.id) < convertToInt(needed_id))
            first = middle + 1;
        
        else 
            last = middle - 1;
    }
    
    if (convertToInt(a[first].patient.id) == convertToInt(needed_id))
            return first;
    
    if (convertToInt(a[last].patient.id) == convertToInt(needed_id))
            return last;
    
	return -1;
}

int findPatient(Patient a[], string name, int choice, int NoP){ // Basil Al Zahrani 2220004116
    
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

#endif