//// Basil AlZahrani, Anas AlGhamdi, Anas AlGhamdi, Ahmad Al Ohaid, Mohammad AlGhamdi

#include "headers.hpp"

//// Function Definitions

int main () {
	
	color(true);
	
	printWelcomeMessage();
	
	while (true) {
		
		if (isExit)
			break;
		
		if (!silentLoad)
			printFilesMenu();
		
		filesMenuNavigation();
	}
	
	color(false);
	
	return 0;
}
