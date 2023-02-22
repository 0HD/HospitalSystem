#ifndef SORTPATIENTS_H
#define SORTPATIENTS_H

#include "../../headers.hpp"

// Anas Ali Mohammad AlGhamdi - 2220005776

void sortPatients(Patient records[], int choice, int NoP) { 
	Patient temp_patients;
	int i,j;
	if(NoP<2){
		cout<<"Nothing to sort"; 
		return;
	}
	if (choice == 1) {
		for ( i=0 ; i<NoP-1 ; i++ ) {
			for ( j=0; j<NoP-1; j++ ) {
				if(convertToInt(records[j].patient.id)>convertToInt(records[j+1].patient.id)) {
					temp_patients = records[j];
					records[j] = records[j+1];
					records[j+1] = temp_patients;
				}
			}
		}
		sorted = choice;
	} else if (choice == 2) {
		for ( i=0 ; i<NoP-1 ; i++ ) {
			for ( j=0; j<NoP-1; j++ ) {
				if(convertToInt(records[j].patient.id)<convertToInt(records[j+1].patient.id)) {
					temp_patients = records[j];
					records[j] = records[j+1];
					records[j+1] = temp_patients;
				}
			}
		}
		sorted = choice;
	}	
}

#endif