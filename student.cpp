#include <iostream>
#include <string>
#include"student.h"

using namespace std;

// default constructor
Student::Student() {};
// destructor
Student::~Student() {};
// overloaded constructor
Student::Student(
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
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(studentEmail);
	setAge(studentAge);
	courseDays.push_back(courseDays1st);
	courseDays.push_back(courseDays2nd);
	courseDays.push_back(courseDays3rd);
	setDegreeProgram(degree);
}

// prints information for single student
void Student::print() {
	// convert degree enum to string
	string degreeProgram;
	switch (degree) {
	case DegreeProgram::NETWORK:
		degreeProgram = "NETWORK";
		break;
	case DegreeProgram::SECURITY:
		degreeProgram = "SECURITY";
		break;
	case DegreeProgram::SOFTWARE:
		degreeProgram = "SOFTWARE"; 
		break;
	}

	cout << studentID << "\t" << firstName << "\t" << lastName << "\t" << studentAge << "\t";
	// created loop to allow for course days vector to be expanded if needed
	if (!courseDays.empty()) {
		for (auto& days : courseDays)
		{
			if (&days == &courseDays.back()) {
				cout << days << "\t ";
				break;
			}
			cout << days << ", ";
		}
		cout << " " << degreeProgram << endl;
	}
}

// setters for student records
void Student::setStudentID(string id) {
	studentID = id;
}
void Student::setFirstName(string first) {
	firstName = first;
}
void Student::setLastName(string last) {
	lastName = last;
}
void Student::setEmail(string email) {
	studentEmail = email;
}
void Student::setAge(int age) {
	this->studentAge = age;
}
void Student::setCourseDays(vector<int> newCourseDays) {
	courseDays = newCourseDays;
}
void Student::setDegreeProgram(DegreeProgram program) {
	this->degree = program;
}

// getters for student records
const string Student::getStudentID() const {
	return studentID;
}
const string Student::getFirstName() const {
	return firstName;
}
const string Student::getLastName() const {
	return lastName;
}
const string Student::getEmail() const {
	return studentEmail;
}
const int Student::getStudentAge() const {
	return studentAge;
}
const vector<int> Student::getCourseDays() const {
	return courseDays;
}
const DegreeProgram Student::getDegreeProgram() const {
	return degree;
}
