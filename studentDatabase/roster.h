#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <string>
class Roster {
private:
	int lastIndex;
	int sizeofArray;
	Student** classRosterArray;

public:
	Roster();
	Roster(int sizeofArray);

public:
	void printMyInfo(string courseTitle, string progLang, string id, string name);
	void parseStudentData(string data);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree type);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	~Roster();
};




#endif // !ROSTER_H

