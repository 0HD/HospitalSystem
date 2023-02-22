#ifndef FINDPATIENT_H
#define FINDPATIENT_H

#include "../../headers.hpp"

// Basil AlZahrani - 2220004116

int findPatient(Patient a[], string needed_id){ // Basil Al Zahrani 2220004116
    
    // If the array is sorted,
	// binary search will be used
    if (sorted == 1 || sorted == 2) {
    	
    	int middle = 0;
	    int first = 0;
	    int last = NoP-1;
	    
		while(last - first > 1) {
	        
			middle = (first + last) / 2;
	        
	        if (a[middle].patient.id == needed_id)
	            return middle;
	        
	        // If the array is ascending
			else if (sorted == 1) {
				if(a[middle].patient.id < needed_id)
		            first = middle + 1;
		        
		        else 
		            last = middle - 1;
			}
			
			// If the array is descending
			else if (sorted == 2) {
				if(a[middle].patient.id > needed_id)
		            first = middle + 1;
		        
		        else 
		            last = middle - 1;
			}
	    }
	    
	    if (a[first].patient.id == needed_id)
	            return first;
	    
	    if (a[last].patient.id == needed_id)
	            return last;
	}
	
	// If the array is not sorted,
	// sequential search will be used
	else if (sorted == 0) {
		for (int i = 0; i < NoP; i++) {
			if (a[i].patient.id == needed_id)
            	return i;
        }
	}
	
	// When not found
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

#endif