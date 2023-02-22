#ifndef GETFILESMENUINPUT_HPP
#define GETFILESMENUINPUT_HPP

#include "../filesMenu.hpp"

void getFilesMenuInput () {
	if (loadFromHistory)
		isLoadFile = true;
	else if (finishedLoadingFromHistory)
		isRecentFiles = true;
	else {
		int input = numberInput();
		switch (input) {
			case 0:
				isExit = true;
				break;
			case 1:
				isRecentFiles = true;
				break;
			case 2:
				isLoadFile = true;
				break;
			case 3:
				isCreateFile = true;
				break;
			default:
				clear();
				printError("Invalid option");
		}
	}
}

#endif