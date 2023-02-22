#ifndef UPDATEPATIENT_H
#define UPDATEPATIENT_H

#include "../../headers.hpp"

// Ahmad Al Ohaid - 2200004371

int updatePatient(Patient a[], string id, int choice, string newData, int NoP) {
  
  	int index = findPatient(a, id, NoP);
  
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
			a[index].dose = convertToInt(newData);
    	default:
	      	return -1;
	      	break;
  }
  return 0;
}

#endif