#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

#include "../headers.hpp"

////// Basil AlZahrani
///// 2220004116

// 4116/findPatient.hpp
int findPatient(Patient [], string);
int findPatient(Patient [], string, int);

////// Mohammad AlGhamdi
///// 2220003014

// 3014/addPatient.hpp
void addPatient (Patient [], Patient);

////// Ahmad Al Ohaid
///// 2200004371

// 4371/updatePatient.hpp
int updatePatient(Patient [], string, int, string, int);

////// Anas Ali Mohammad AlGhamdi
///// 2220005776

// 5776/sortPatients.hpp
void sortPatients(Patient [], int, int);

////// Anas Ali Mastour AlGhamdi
///// 2220003812

// 3812/convertToInt.hpp
int convertToInt (string);

// 3812/commands.hpp
void clear();
void color(bool enable);
void createFolder(string);
void title(string);

// 3812/filesFuncs.hpp
void getArrayInfoFromFile ();
bool isFileCompatible ();
void loadRecords (Patient [], int &);
int saveRecords (Patient []);
void updateFileHistory ();

// 3812/filesMenu.hpp
void filesMenuNavigation();
void getFilesMenuInput();
void loadFile();
void printFilesMenu();
void printLoadMenu();
void setSize (int);
void setNoP (int);

// 3812/inputFuncs.hpp
int numberInput();
string stringInput();
string stringInput(string);

// 3812/printFuncs.hpp
void printBox (string);
void printError(string);
void printWelcomeMessage();

// 3812/recordsMenu.hpp
void deleteRecord (Patient [], int);
void menu(Patient []);
int newPatient (Patient []);

// 3812/viewPatients.hpp
string fillSpaces (string, int);
int maxCharacters (string, int);
void printColumns (int [], string, string, string, string, string, string, string, string, string);
string underscores (int);
void view(Patient [], int, int, int);

#endif