#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

class Student{
public:
	string studentID;
	int studentAge;
	string first_name;
	string last_name;
	string email_address;
	int daysToComplete[3];
	Degree degreeType;




	//Constructor:
	Student();//Default constructor if the user does not input any parameters. char first_name[20], char last_name[20], char email_address[20],
	Student(string firstName, string lastName, int age, string id, string email, Degree type);// int dayToComplete[3]

public:
//Mutator:
	void setStudentID(string id);
	void setAge(int age);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setDaysToComplete(int days[3]);
	void setStudentDegree(Degree degreeType);






	
	/*
	
	
	*/

public:
	//Accessor:
	string getStudentId();
	int  getAge();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getDaysToComplete();
	Degree getStudentDegree();


	//Virtual functions:
	virtual void printStudentInfo();
	//virtual Degree getDegreeProgram();

	//Destructor:
	~Student();
};

#endif //STUDENT_H