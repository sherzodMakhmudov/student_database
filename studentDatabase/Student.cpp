#include "student.h"
#include <iostream>
using namespace std;

void Student::setAge(int age) {
	studentAge = age;
}

int Student::getAge(){
	return studentAge;
}

void Student::setStudentID(string id) {
	studentID = id;
}

string Student::getStudentId(){
	return studentID;
}

void Student::setFirstName(string firstName) {
	this->first_name = firstName;
}

string Student::getFirstName() {
	return first_name;
}

void Student::setLastName(string lName) {
	last_name = lName;
}

string Student::getLastName() {
	return last_name;
}

void Student::setEmailAddress(string email) {
	email_address = email;
}

string Student::getEmailAddress() {
	return email_address;
}

void Student::setDaysToComplete(int days[]) {
	for (int i = 0; i < sizeOfDaysToCompleteArr; i++) {
		this->daysToComplete[i] = days[i];
	}
}

int* Student::getDaysToComplete() {
	return daysToComplete;//Arrays are a pointer in c++
}

Degree Student::getDegreeProgram() {
	return studentDegreeType;
}

void Student::print() {

	cout << this->studentID << "		First Name: " << this->getFirstName() << "		Last Name: " << this->getLastName() <<
		"		Age: " << this->getAge() << "		Days in course: ";

	for (int i = 0; i < sizeOfDaysToCompleteArr; i++) {
		int* daysToComplete = getDaysToComplete();
		cout << this->daysToComplete[i] << " ";
	}
	cout << "		Days in course: ";
}


//Constructors:
Student::Student(string id, string firstName, string lastName, string email, int age, int days[]){ //, int dayToComplete[3], ) {
	this->first_name = firstName;
	this->last_name = lastName;
	this->studentAge = age;
	this->studentID = id;
	this->email_address = email;
	//Degree type will be implemented in subclasses of the Book;

	for (int i = 0; i < sizeOfDaysToCompleteArr; i++) {
		this->daysToComplete[i] = days[i];
	}
}

Student::Student() {
	this->first_name = "";
	this->last_name = "";
	this->studentAge = 0;
	this->studentID = "";
	this->email_address = "";
	for (int i = 0; i < sizeOfDaysToCompleteArr; i++) this->daysToComplete[i] = 0;
	//Degree type will be implemented in subclasses of the Book;
}


Student::~Student() {
	//cout << "Program will come to its end and going to be terminated at once" << endl;
}





