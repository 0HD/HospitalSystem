#ifndef SAVERECORDS_HPP
#define SAVERECORDS_HPP

#include "../filesFuncs.hpp"

int saveRecords(Patient f[]) {
	
	ofstream outFile;
	
	int row = 0, col = -2;
	
	outFile.open(fileName);
	
	if (outFile.is_open()) {
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
	}
	else
		return -1;
	
	outFile.close();
	
	updateFileHistory();
	
	return 0;
}

#endif