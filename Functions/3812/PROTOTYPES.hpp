#ifndef _2220003812
#define _2220003812

#include "../../headers.hpp"

// Anas Ali Mastour AlGhamdi - 2220003812

// convertToInt.hpp
int convertToInt (string);

// commands.hpp
void clear();
void color(bool enable);
void createFolder(string);
void title(string);

// filesFuncs.hpp
void getArrayInfoFromFile ();
bool isFileCompatible ();
void loadRecords (Patient [], int &);
int saveRecords (Patient []);
void updateFileHistory ();

// filesMenu.hpp
void filesMenuNavigation();
void getFilesMenuInput();
void loadFile();
void printFilesMenu();
void printLoadMenu();
void setSize (int);
void setNoP (int);

// inputFuncs.hpp
int numberInput();
string stringInput();
string stringInput(string);

// printFuncs.hpp
void printBox (string);
void printError(string);
void printWelcomeMessage();

// recordsMenu.hpp
void deleteRecord (Patient [], int);
void menu(Patient []);
int newPatient (Patient []);

// viewPatients.hpp
string fillSpaces (string, int);
int maxCharacters (string, int);
void printColumns (int [], string, string, string, string, string, string, string, string, string);
string underscores (int);
void view(Patient [], int, int, int);

#endif