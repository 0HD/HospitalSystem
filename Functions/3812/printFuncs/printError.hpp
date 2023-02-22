#ifndef PRINTERROR_HPP
#define PRINTERROR_HPP

#include "../printFuncs.hpp"

void printError (string message) {
	if (message == "Invalid option") {
		cout <<  "  _________________________________ \n"
				 " |                                 |\n"
				 " |       (!)  Invalid option       |\n"
				 " |  _____________________________  |\n"
				 " |                                 |\n"
				 " |  Please enter a number from     |\n"
				 " |  one of the available options.  |\n"
				 " |_________________________________|\n";
	}
	else if (message == "Unable to load") {
		cout <<  "  _________________________________ \n"
				 " |                                 |\n"
				 " |   (!)  Error loading the file   |\n"
				 " |  _____________________________  |\n"
				 " |                                 |\n"
				 " |  This file might be corrupted,  |\n"
				 " |  or incompatible with the       |\n"
				 " |  hospital system.               |\n"
				 " |_________________________________|\n";
		
	}
	else if (message == "File not found") {
		cout <<  "  _________________________________ \n"
				 " |                                 |\n"
				 " |   (!) Unable to find the file   |\n"
				 " |  _____________________________  |\n"
				 " |                                 |\n"
				 " |  Maybe the file doesn't exist,  |\n"
				 " |  or you've entered an invalid   |\n"
				 " |  file name.                     |\n"
				 " |_________________________________|\n";
	}
	else if (message == "Invalid size") {
		cout <<  "  _________________________________ \n"
				 " |                                 |\n"
				 " |    (!)  Invalid size entered    |\n"
				 " |  _____________________________  |\n"
				 " |                                 |\n"
				 " |  Please enter a valid size      |\n"
				 " |  limit for the records.         |\n"
				 " |_________________________________|\n";
	}
	else if (message == "Unable to save") {
		cout <<  "  _________________________________ \n"
				 " |                                 |\n"
				 " |   (!) Unable to save the file   |\n"
				 " |  _____________________________  |\n"
				 " |                                 |\n"
				 " |  Either you entered an invalid  |\n"
				 " |  file name, or there is a       |\n"
				 " |  problem with your computer.    |\n"
				 " |_________________________________|\n";
	}
	
}

#endif