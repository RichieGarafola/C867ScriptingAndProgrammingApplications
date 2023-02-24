#pragma once
#include <array>
#include <string>
#include <vector>
#include "degree.h"

using namespace std;

class Student {
	// keep sensitive data as protected as possible
protected:
	string studentID, firstName, lastName, studentEmail;
	int studentAge;
	vector<int> courseDays;
	DegreeProgram degree;

public:
	// constructor declaration
	Student();
	// destuctor
	~Student();
	// constructor overload
	Student(
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
	// print function
	void print();

public:

	void setStudentID(string id);
	const string getStudentID() const;

	void setFirstName(string first);
	const string getFirstName() const;

	void setLastName(string last);
	const string getLastName() const;

	void setEmail(string email);
	const string getEmail() const;

	void setAge(int age);
	const int getStudentAge() const;

	void setCourseDays(vector<int> newCourseDays);
	const vector<int> getCourseDays() const;

	void setDegreeProgram(DegreeProgram program);
	const DegreeProgram getDegreeProgram() const;
};
