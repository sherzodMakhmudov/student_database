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

void Student::setFirstName(string fName) {
	first_name = fName;
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

void Student::setStudentDegree(Degree type) {
	degreeType = type;
}

Degree Student::getStudentDegree() {
	return degreeType;
}

/*
Create a setter/getter function for daysToComplete.
*/



//Constructors:
Student::Student(string firstName, string lastName, int age, string id, string email, Degree type){ //, int dayToComplete[3], ) {
	this->first_name = firstName;
	this->last_name = lastName;
	this->studentAge = age;
	this->studentID = id;
	this->email_address = email;
	//this->daysToComplete = dayToComplete[3]
	this->degreeType = type;
}

Student::Student() {
	this->first_name = "";
	this->last_name = "";
	this->studentAge = 0;
	this->studentID = "";
	this->email_address = "";
	//this->daysToComplete = dayToComplete[3]
	this->degreeType;
}

void Student::printStudentInfo() {
	cout << "Student fullname is:" << this->first_name << " " << this->last_name << endl;
	cout << "Student age is" << this->studentAge << " and email is: " << this->email_address << endl;
	cout << "This student has an ID of " << this->studentID << " and degree type is: " << this->degreeType<<endl;
}

/*
Create a virtual getDegree function here
*/

Student::~Student() {
	cout << "Program has come to its end and going to be terminated at once" << endl;
}





