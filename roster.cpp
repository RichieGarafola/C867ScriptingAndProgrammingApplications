#pragma once
#include <iostream>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"

using namespace std;

// default constructor
Roster::Roster() {
	// initialize rosterSize and rosterIndex
	this->rosterSize = 0;
	this->rosterIndex = -1;
	// initialize the classRosterArray pointer to nullptr
	this->classRosterArray = nullptr;
};

// overloaded constructor
Roster::Roster(int rosterSize) {
	// initialize rosterSize and rosterIndex
	this->rosterSize = rosterSize;
	this->rosterIndex = -1;
	// dynamically allocate memory for the classRosterArray pointer using rosterSize
	this->classRosterArray = new Student * [rosterSize];
};
// destructor
Roster::~Roster() {    
	// Free the memory allocated by classRosterArray
	for (int i = 0; i < this->rosterSize; ++i) {
		if (this->classRosterArray[i] != nullptr) {
			delete this->classRosterArray[i];
			this->classRosterArray[i] = nullptr;
		}
	}
	// Free the memory allocated for classRosterArray
	delete[] this->classRosterArray;
	this->classRosterArray = nullptr;
}

void Roster::parseThenAddRow(string row) {
	// parse string into vector for easier separation, more readable code
	vector<string> rowData;
	stringstream rowStream(row);
	while (rowStream.good()) {
		string substr;
		getline(rowStream, substr, ',');
		rowData.push_back(substr);
	}

	// assign and convert from string to int where needed
	string studentIDTemp = rowData.at(0);
	string firstNameTemp = rowData.at(1);
	string lastNameTemp = rowData.at(2);
	string emailAddressTemp = rowData.at(3);
	int ageTemp = stoi(rowData.at(4));
	int courseDays1Temp = stoi(rowData.at(5));
	int courseDays2Temp = stoi(rowData.at(6));
	int courseDays3Temp = stoi(rowData.at(7));
	string degreeProgramString = rowData.at(8);

	// determine degree from string
	DegreeProgram degreeProgramTemp = DegreeProgram::NETWORK;
	if (degreeProgramString == "NETWORK") {
		degreeProgramTemp = DegreeProgram::NETWORK;
	}
	else if (degreeProgramString == "SECURITY") {
		degreeProgramTemp = DegreeProgram::SECURITY;
	}
	else if (degreeProgramString == "SOFTWARE") {
		degreeProgramTemp = DegreeProgram::SOFTWARE;
	}

	add(
		studentIDTemp,
		firstNameTemp,
		lastNameTemp,
		emailAddressTemp,
		ageTemp,
		courseDays1Temp,
		courseDays2Temp,
		courseDays3Temp,
		degreeProgramTemp
	);
}

// regex from here: https://www.codespeedy.com/program-to-validate-email-id-using-regex-in-cpp/
// take an emaill address string as a parameter
bool Roster::isValidEmail(string email) {
	// chck if it is a valid email address by matching against regular expression pattern
	const regex regexPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, regexPattern);
}

// locate specific students in studentRoster by taking an int index as a parameter
Student* Roster::retrieveStudent(int index) {
	// return a pointer to the Student object at that index in the classRosterArray
	return classRosterArray[index];
}

// take all the necessary pieces of information to create a new student object,
// create the object using the provied parameters, and add it to the classRosterArray
void Roster::add(
	string studentID,
	string firstName,
	string lastName,
	string studentEmail,
	int studentAge,
	int courseDays1st,
	int courseDays2nd,
	int courseDays3rd,
	DegreeProgram degree
) {
	// increase index to empty one
	rosterIndex++;
	// add new student object
	classRosterArray[rosterIndex] = new Student(
		studentID,
		firstName,
		lastName,
		studentEmail,
		studentAge,
		courseDays1st,
		courseDays2nd,
		courseDays3rd,
		degree
	);
}
// takes s a student ID as a parameter and removes the student object with the ID from the classRosterArray
void Roster::remove(string studentID) {
	// to know if to raise error or not
	bool recordLocated = false;
	// iterate through records for a match
	for (int i = 0; i <= rosterIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			recordLocated = true;
			delete this->classRosterArray[i];
			// switch position with last element to avoid gaps in array
			this->classRosterArray[i] = this->classRosterArray[rosterIndex];
			rosterIndex--;
		}
	}
	// print out error if student not located
	if (!recordLocated) {
		cout << "The student with the ID: " << studentID << " was not found.\n";
		cout << "DONE.";
	}
}
// iterate iver the classRosterArray and print out the information of each Student object
void Roster::printAll() {
	for (int i = 0; i <= this->rosterIndex; i++) {
		this->classRosterArray[i]->print();
	}
}
// Takes studentID as a parameter and calculates the avg num of days each student took to complete course
// iterate over the classRosterArray and compute the average of the course day numbers for the specified student
void Roster::printAvgDaysInCourse(string studentID) {
	for (int i = 0; i <= rosterIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			vector<int> courseDays = classRosterArray[i]->getCourseDays();
			// this should allow for easier expansion of courseDays if needed
			int avgCourseDays = accumulate(courseDays.begin(), courseDays.end(), courseDays.size()) / courseDays.size();
			cout << "Student ID: " << studentID << ", average days in course is: " << avgCourseDays << endl;
		}
	}
}

// iterate over the classRosterArray and print out an error message for each student whos email is invalid
void Roster::printInvalidEmails() {
	for (int i = 0; i <= this->rosterIndex; i++) {
		string tempEmail = this->classRosterArray[i]->getEmail();
		if (!isValidEmail(tempEmail)) {
			cout << tempEmail << " - is invalid." << endl;
		}
	}
}
// take a degree program as a paramater and iterate over the classRosterArray
// // print out the information of each student with the specified degree program
// use degree to ensure no unintended type conversion with int
void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i <= rosterIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degree) {
			this->classRosterArray[i]->print();
		}
	}
}
