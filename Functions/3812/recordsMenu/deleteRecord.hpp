#ifndef DELETERECORD_HPP
#define DELETERECORD_HPP

#include "../recordsMenu.hpp"

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

#endif