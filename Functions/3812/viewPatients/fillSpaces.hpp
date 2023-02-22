#ifndef FILLSPACES_HPP
#define FILLSPACES_HPP

#include "../viewPatients.hpp"

string fillSpaces (string str, int max) {
	
	while (str.length() < max)
		str += " ";
	
	return str + " ";
}

#endif