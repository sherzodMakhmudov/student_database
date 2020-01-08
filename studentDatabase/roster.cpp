#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

Roster::Roster() {
	this->lastIndex = -1;
	this->sizeofArray = 0;
	this->rosterArray = nullptr;
}

Roster::Roster(int sizeOfArray){
	this->lastIndex = - 1;
	this->sizeofArray = sizeOfArray;
	this->rosterArray = new Student * [sizeofArray];
}



void main() {
	string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Sherzod,Makhmudov,smakhmu@wgu.edu,21,25,30,29,SOFTWARE",
	};
}
