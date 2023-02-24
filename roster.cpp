#pragma once
#include <string>
#include "student.h"

using namespace std;

class Roster {
private:
	Student** classRosterArray;
	int rosterSize;
	int rosterIndex;

public:
	// default constructor
	Roster();
	// overloaded constructor
	Roster(int rosterSize);
	// destructor
	~Roster();

	// utility functions
	void parseThenAddRow(string row);
	bool isValidEmail(string email);
	Student* retrieveStudent(int index);
	// roster functions
	void add(
		string studentID,
		string firstName,
		string lastName,
		string studentEmail,
		int studentAge,
		int courseDays1st,
		int courseDays2nd,
		int courseDays3rd,
		DegreeProgram degree
	);
	void remove(string studentID);
	void printAll();
	void printAvgDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
};
