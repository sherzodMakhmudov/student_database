#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

class Student{

public: const static int sizeOfDaysToCompleteArr = 3;

protected:
	string studentID;
	int studentAge;
	string first_name;
	string last_name;
	string email_address;
	int daysToComplete[sizeOfDaysToCompleteArr];
	Degree studentDegreeType;

public:
	//Constructor:
	Student(); //Empty Constructor
	Student(string id, string firstName, string lastName, string email, int age, int days[]);

public:
	//Mutator:
	void setStudentID(string id);
	void setAge(int age);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setDaysToComplete(int days[]);

public:
	//Accessor:
	string getStudentId();
	int  getAge();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int* getDaysToComplete();

public:
	//Virtual functions:
	virtual void print() = 0; //if there is a virtual function in the class then that class is an abstraact class,
	//virtual Degree getDegreeProgram(); //thus they should be in subclasses. :: Not working as of now.

public:
	//Destructor:
	~Student();
};




#endif //STUDENT_H