#include "softwareStudent.h"
#include <iostream>


SoftwareStudent::SoftwareStudent():Student(){
	//all the settings will be inherited from student cosntructor except degree type
	//It will be set up down below:
	studentDegreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string id, string firstName, string lastName, string email, int age, int days[], Degree degreeType) :Student(firstName, lastName, age,  id,  email, days) {
	studentDegreeType = SOFTWARE;
}

Degree SoftwareStudent::getDegreeProgram(){
	return SOFTWARE; //Now we can return this, it's not virtual anymore
}

void SoftwareStudent::print(){
	this->Student::print();
	cout << studentDegreeType << " student" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	this->Student::~Student();
}