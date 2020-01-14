#include "networkStudent.h"
#include <iostream>


NetworkStudent::NetworkStudent() :Student() {
	//all the settings will be inherited from student cosntructor except degree type
	//It will be set up down below:
	studentDegreeType = NETWORK;
}

NetworkStudent::NetworkStudent(string id, string firstName, string lastName, string email, int age, int days[], Degree degreeType):Student(id, firstName, lastName, email, age, days) {
	studentDegreeType = NETWORK;
}

Degree NetworkStudent::getDegreeProgram() {
	return NETWORK; //Now we can return this, it's not virtual anymore
}

void NetworkStudent::print() {
	this->Student::print();
	cout <<"Network";
}

NetworkStudent::~NetworkStudent() {
	this->Student::~Student();
}