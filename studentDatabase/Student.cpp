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

void Student::setDaysToComplete(int days[]) {
	for (int i = 0; i < sizeOfDaysToCompleteArr; i++) {
		this->daysToComplete[i] = days[i];
	}
}

int* Student::getDaysToComplete() {
	return daysToComplete;//Arrays is a pointer in c++
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

void Student::print() {
	cout << "Student fullname is:" << this->first_name << " " << this->last_name << endl;
	cout << "Student age is" << this->studentAge << " and email is: " << this->email_address << endl;
	cout << "This student has an ID of " << this->studentID<< endl;
}


Student::~Student() {
	cout << "Program will come to its end and going to be terminated at once" << endl;
}





