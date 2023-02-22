#ifndef COLOR_HPP
#define COLOR_HPP

#include "../commands.hpp"

// Change the terminal colors (Windows-only)
void color(bool enable) {
	
	#ifdef _WIN32
		if (enable)
			system("color f0");
		else
			system("color 07");
	#endif
	
}

#endif