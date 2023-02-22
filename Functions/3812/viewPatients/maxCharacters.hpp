#ifndef MAXCHARS_HPP
#define MAXCHARS_HPP

#include "../viewPatients.hpp"

int maxCharacters (string str, int max) {
	if (str.length() > max)
		return str.length();
	else
		return max;
}

#endif