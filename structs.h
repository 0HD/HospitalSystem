#ifndef STRUCTS_H
#define STRUCTS_H

using namespace std;

struct Name {
	string first; // First name
	string last; // Last name
};

struct Date {
	int dd; // Day
	int mm; // Month
	int yy; // Year
};

struct Person {
	string id;
	Name name;
	char gender;
	Date dob; // Date of Birth
};

struct Patient {
	Person patient;
	string medicine;
	int dose;
};

#endif