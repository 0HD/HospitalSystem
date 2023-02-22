#ifndef PRINTLOADMENU_HPP
#define PRINTLOADMENU_HPP

#include "../filesMenu.hpp"

void printLoadMenu () {
	clear();
	title("Hospital System - Load File");

	printBox("    Loading existing records     ");
	cout << "\nEnter file name:\n> ";
}

#endif