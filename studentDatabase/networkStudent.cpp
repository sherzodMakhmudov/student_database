#include "networkStudent.h"
#include <iostream>


NetworkStudent::NetworkStudent() :Student() {
	//all the settings will be inherited from student cosntructor except degree type
	//It will be set up down below:
	studentDegreeType = NETWORKING;
}

NetworkStudent::NetworkStudent(string id, string firstName, string lastName, string email, int age, int days[], Degree degreeType) :Student(firstName, lastName, age, id, email, days) {
	studentDegreeType = NETWORKING;
}

Degree NetworkStudent::getDegreeProgram() {
	return NETWORKING; //Now we can return this, it's not virtual anymore
}

void NetworkStudent::print() {
	this->Student::print();
	cout << studentDegreeType << " student" << endl;
}

NetworkStudent::~NetworkStudent() {
	this->Student::~Student();
}