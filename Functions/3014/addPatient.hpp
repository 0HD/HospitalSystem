#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include "../../headers.hpp"

// Mohammad AlGhamdi - 2220003014

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

#endif