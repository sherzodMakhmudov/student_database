#include <iostream>
#include "roster.h"
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

using namespace std;

Roster::Roster(){
	//Empty constructor
	this->lastIndex = -1;
	this->sizeofArray = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int sizeOfArray){
	this->lastIndex = - 1;
	this->sizeofArray = sizeOfArray;
	this->classRosterArray = new Student*[sizeofArray]; // ask this
}



void main() {
	//Storing the student data:
	const int numberOfStudents = 5;
	string studentData[numberOfStudents] = {
		"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.bla ck@comcast.net,22,50,58,40,SECURITY",
		"A5,Sherzod,Makhmudov,smakhmu@wgu.edu,21,25,30,29,SOFTWARE",
	};
	

	Roster* studentRoster = new Roster(numberOfStudents);
	
	studentRoster->printMyInfo("Computer Science", "C++", "001102147", "Sherzod Makhmudov");

	for (int i = 0; i < numberOfStudents; i++) {
		studentRoster->parseStudentData(studentData[i]);
	}
	cout << "Printing all students in the roster:" << endl;
	studentRoster->printAll();
	studentRoster->printInvalidEmails();
	string studentId = "A5";
	cout << "Number of days in the three courses for student ID - " << studentId << ": " << endl;
	studentRoster->printDaysInCourse(studentId);
	cout << endl;
	cout << "Printing student data by Software degree type:" << endl;
	studentRoster->printByDegreeProgram(2);
	cout << endl;
	string studentToRemove = "A3";
	cout << "Student ID - " << studentToRemove << " has been removed from the roster:" << endl;
	studentRoster->remove(studentToRemove);
	cout << endl;

	cout << "Removing student #A3 again:";
	studentRoster->remove(studentToRemove);
	studentRoster->~Roster();
	system("pause");
}

void Roster::parseStudentData(string row) {
	if (lastIndex > sizeofArray) {
		cerr << "Array is out of scope";
		exit(-1);
	}
	else {
		lastIndex++;
		int rightHandSide = row.find(",");
		string id = row.substr(0, rightHandSide);
		//cout << id << endl;

		int leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		string firstName = row.substr(leftHandSide, rightHandSide - leftHandSide);
		//cout << firstName << endl;

		leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		string lastName = row.substr(leftHandSide, rightHandSide - leftHandSide);
		//cout << lastName << endl;

		leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		string email = row.substr(leftHandSide, rightHandSide - leftHandSide);
		//cout << email << endl;

		leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		int age = stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));
		//cout << age << endl;

		leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		int day1 = stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));
		//cout << day1 << endl;

		leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		int day2 = stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));
		//cout << day2 << endl;

		leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		int day3 = stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));
		//cout << day3 << endl;

		leftHandSide = rightHandSide + 1;
		rightHandSide = row.find(",", leftHandSide);
		string type = row.substr(leftHandSide, rightHandSide - leftHandSide);
		Degree degreeType;
		if (type == "SECURITY") {
			degreeType = SECURITY;
		}
		else if (type == "NETWORK") {
			degreeType = NETWORK;
		}
		else if (type == "SOFTWARE") {
			degreeType = SOFTWARE;
		}
		

		add(id, firstName, lastName, email, age, day1, day2, day3, degreeType);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree type){
	int daysArray[Student::sizeOfDaysToCompleteArr];
	daysArray[0] = daysInCourse1;
	daysArray[1] = daysInCourse2;
	daysArray[2] = daysInCourse3;

	if (type == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysArray, SECURITY);
	}
	else if (type == NETWORK) {
		classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysArray, NETWORK);
	}
	else if (type == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysArray, SOFTWARE);
	}
}

void Roster::printAll() {
		for (int i = 0; i <= this->lastIndex; i++) {
			this->classRosterArray[i]->print();
			cout << endl;
		}	
}

void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentId() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			//Fill up the missing index with the last one:
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
			printAll();
		}
	}
	if (found == false) {
		cout<<"Student is not found." << endl;
	}

}

void Roster::printDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentId() == studentID) {
			found = true;
			for (int j = 0; j < this->classRosterArray[i]->sizeOfDaysToCompleteArr; j++) {
				
				int* days = this->classRosterArray[i]->getDaysToComplete();
				cout<< days[j] << " ";
			}
		}
	}
	if (found == false) {
		cout << "Student was not found." << endl;
	}
}

void Roster::printInvalidEmails() {
	cout << "Printing all invalid emails:" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		bool hasSpace = false;
		string email = this->classRosterArray[i]->getEmailAddress();
		int leftHandPosition = email.find("@");
		int rightHandPostion = leftHandPosition + 1;

		int leftHandDotPosition = email.find(".");
		int leftRightDotPosition = leftHandDotPosition + 1;

		int leftHandSpacePostion = email.find(" ");
		int righthandSpacePosition = leftHandDotPosition + 1;
		if (leftHandSpacePostion >= 0) {
			hasSpace = true;
		}
		else {
			hasSpace = false;
		}

		//Position must be greater or equal to zero to void out of range error,
		//if find() can't find the character it will return -1 which will break the programm.
		if (leftHandPosition >= 0 && leftHandDotPosition>=0 && hasSpace == false) {
			continue;
		}
		else if(leftHandSpacePostion>=0){
			cout << "Invalid email with space:"<<email << endl;
		}
		else {
			cout << "Missing '@' or '.' characters:" << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(int degreeProgram) {
	string typeString = studentDegreeArray[degreeProgram];
	Degree type;
	
	if (studentDegreeArray[0] == "SECURITY") {
		type = SECURITY;
	}
	else if (studentDegreeArray[1] == "NETWORK") {
		type = NETWORK;
	}
	else if (studentDegreeArray[2] == "SOFTWARE") {
		type = SOFTWARE;
	}
	
	cout << "Printing " << studentDegreeArray[degreeProgram] << " student(s)"<<"\n";
	for (int i = 0; i < sizeofArray; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
			cout << endl;
		}
	}
}

void Roster::printMyInfo(string courseTitle, string progLang, string id, string name) {
	cout << "Course title:" << courseTitle << ", Programming language used:" << progLang << ", student Id:" << id << ", name:" << name << endl;
}

Roster::~Roster() {
	cout << "Roster destructor has been called." << endl<<endl;
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i]; //Deletes each student object that was created dynamically
	}
	delete classRosterArray; //Deletes dynamically allocated array of pointers to the student;
}