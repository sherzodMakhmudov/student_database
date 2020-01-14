#include "securityStudent.h"
#include <iostream>


SecurityStudent::SecurityStudent() :Student() {
	//all the settings will be inherited from student cosntructor except degree type
	//It will be set up down below:
	studentDegreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string id, string firstName, string lastName, string email, int age, int days[], Degree degreeType):Student(id, firstName, lastName, email, age, days) {
	studentDegreeType = SECURITY;
}

Degree SecurityStudent::getDegreeProgram() {
	return SECURITY; //Now we can return this, it's not virtual anymore
}

void SecurityStudent::print() {
	this->Student::print();
	cout <<"Security";
}

SecurityStudent::~SecurityStudent() {
	this->Student::~Student();
}