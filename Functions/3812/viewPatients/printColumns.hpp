#ifndef PRINTCOLUMNS_HPP
#define PRINTCOLUMNS_HPP

#include "../viewPatients.hpp"

void printColumns (int columns[], string start, string col1, string col2, string col3, string col4, string col5, string col6, string col7, string end) {
	for (int i = 0; i < 7; i++) {
			cout << start;
			switch (columns[i]) {
				case 1:
					cout << col1; break;
				case 2:
					cout << col2; break;
				case 3:
					cout << col3; break;
				case 4:
					cout << col4; break;
				case 5:
					cout << col5; break;
				case 6:
					cout << col6; break;
				case 7:
					cout << col7; break;
			}
		}
	cout << end;
}

#endif