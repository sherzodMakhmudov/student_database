#ifndef NetworkStudent_H
#define NetworkStudent_H

#include "student.h"
#include <string>
using namespace std;

class NetworkStudent: public Student {
public:
	NetworkStudent();
	NetworkStudent(string id, string firstName, string lastName, string email, int age, int days[], Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~NetworkStudent();
};

#endif // !NetworkStudent_H