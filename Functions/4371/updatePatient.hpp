#ifndef UPDATEPATIENT_H
#define UPDATEPATIENT_H

#include "../../headers.hpp"

// Ahmad Al Ohaid - 2200004371

int updatePatient(Patient a[], string id, int choice, string newData, int NoP) {
  
  	int index = findPatient(a, id, true);
  
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
		case 51:
			a[index].patient.dob.yy = convertToInt(newData);
			break;
		case 52:
			a[index].patient.dob.mm = convertToInt(newData);
			break;
		case 53:
			a[index].patient.dob.dd = convertToInt(newData);
			break;
		case 6:
			a[index].medicine = newData;
			break;
		case 7:
			a[index].dose = convertToInt(newData);
			break;
    	default:
	      	return -1;
  }
  return 0;
}

#endif