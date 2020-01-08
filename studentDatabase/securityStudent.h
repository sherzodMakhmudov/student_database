#ifndef SecurityStudent_H
#define SecurityStudent_H

#include "student.h"
#include <string>
using namespace std;

class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(string id, string firstName, string lastName, string email, int age, int days[], Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~SecurityStudent();
};

#endif // !SecurityStudent_H