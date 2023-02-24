#include <iostream>
#include "roster.h"
#include "student.h"

int main()
{
	int amountStudents = 5;

	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Richie,Garafola,rgaraf1@wgu.edu,32,50,30,55,SOFTWARE"
	};
	// required performance assessment information
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: TBD" << endl;
	cout << "Name: Richie Garafola\n" << endl;
	
	cout << "Displaying all students:" << endl;
	// amountStudents can and should be something more dynamic than a static int
	Roster* studentRoster = new Roster(amountStudents);
	// iterate through data to parse and add to roster
	for (const auto& rowData : studentData) {
		studentRoster->parseThenAddRow(rowData);
	}

	studentRoster->printAll();
	cout << endl;

	cout << "Displaying invalid emails:\n" << endl;
	studentRoster->printInvalidEmails();
	cout << endl;

	for (int i = 0; i < amountStudents; i++) {
		studentRoster->printAvgDaysInCourse(studentRoster->retrieveStudent(i)->getStudentID());
	}
	cout << endl;

	cout << "Showing students in degree program: SOFTWARE\n" << endl;
	studentRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	cout << "Removing A3:\n" << endl;
	studentRoster->remove("A3");
	studentRoster->printAll();
	cout << endl;

	cout << "Removing A3 again\n" << endl;
	// should print out error message after this attempt
	studentRoster->remove("A3");
	cout << endl;

	studentRoster->~Roster();

	return 0;
}
