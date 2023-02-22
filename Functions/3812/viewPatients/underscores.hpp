#ifndef UNDERSCORES_HPP
#define UNDERSCORES_HPP

#include "../viewPatients.hpp"

string underscores (int amount) {
	
	string underscores = "";
	
	for (int i = 1; i <= amount; i++)
		underscores += "_";
	
	return underscores;
}

#endif