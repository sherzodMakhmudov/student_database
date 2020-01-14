#ifndef SoftwareStudent_H
#define SoftwareStudent_H

#include "student.h"
using namespace std;

class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(string id, string firstName, string lastName, string email, int age, int days[], Degree type);

	Degree getDegreeProgram();
	void print();

	~SoftwareStudent();
};

#endif // !SoftwareStudent_H
