#ifndef _2220003812
#define _2220003812

#include <fstream>
#include <string>
#include "../structs.h"

// Anas Ali Mastour AlGhamdi - 2220003812


// viewPatients.hpp

void view(Patient [], int, int, int);

int maxCharacters (string, int);

string underscores (int);

string fillSpaces (string, int);

void printColumns (int [], string, string, string, string, string, string, string, string, string);

// convertToInt.hpp

int convertToInt (string);

// input.hpp

int numberInput();

string stringInput();

string stringInput(string);

//

void menu(Patient []);

void clear();

void title(string);

int saveRecords(Patient []);

void loadRecords(Patient [], int &);

void deleteRecord(Patient [], int);

void printWelcomeMessage();

void printFilesMenu();

void printLoadMenu();

void filesMenuNavigation();

void loadFile();

bool isCompatible ();

void getArrayInfoFromFile ();

void setSize (int);

void setNoP (int);

void getFilesMenuInput();

void printError(string);

void createFolder(string);

int newPatient (Patient []);

void updateFileHistory ();

void color(bool enable);

void printBox (string);

#endif