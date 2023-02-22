#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//// Definitions

#include "structs.h"

ifstream inFile;

int NoP = 0; // Number of Patients

int CurrentSize = 0; // Used to track the size globally

bool loadFromHistory = false; // Used to skip loading files manually

bool finishedLoadingFromHistory = false; // Used to show feedback after loading from history

bool silentLoad = false; // Used to stop printing messages temporarily

int columns[] = {1, 2, 3, 4, 5, 6, 7}; // Order of columns

bool isExit = false;
bool isLoadFile = false;
bool isRecentFiles = false;
bool isCreateFile = false;

bool showNumbers = false; // Used to show columns numbers temporarily
bool showAllRecords = false; // Used to show all records

int currentYear = time(NULL) / 60 / 60 / 24 / 365 + 1970;
int currentMonth = (time(NULL) - ((currentYear - 1970) * 31556952)) / 60 / 60 / 24 / 30;
int currentDay = (time(NULL) - ((currentYear - 1970) * 31556952) - (currentMonth * 2628000)) / 60 / 60 / 24;

string fileName = "";

// Functions

#include "Functions/3812/PROTOTYPES.hpp"

// Basil AlZahrani - 2220004116
#include "Functions/4116/findPatient.hpp"

// Ahmad Al Ohaid - 2200004371
#include "Functions/4371/updatePatient.hpp"

// Anas Ali Mohammad AlGhamdi - 2220005776
#include "Functions/5776/sortPatients.hpp"

// Mohammad AlGhamdi - 2220003014
#include "Functions/3014/addPatient.hpp"

// Anas Ali Mastour AlGhamdi - 2220003812
#include "Functions/3812/filesMenu.hpp"
#include "Functions/3812/filesFuncs.hpp"
#include "Functions/3812/inputFuncs.hpp"
#include "Functions/3812/printFuncs.hpp"
#include "Functions/3812/convertToInt.hpp"
#include "Functions/3812/viewPatients.hpp"
#include "Functions/3812/recordsMenu.hpp"
#include "Functions/3812/commands.hpp"

#endif