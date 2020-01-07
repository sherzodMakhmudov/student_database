#include <iostream>
#include "student.h"

using namespace std;



int main(){
	//Degree type;
	//type = NETWORKING;
	//char id[10] = { 'a', '1' };
	//Student student(id, 20, 50, type); //Constructor doesnot work either
	
	Student student("Sher", "Mk", 21, "SHQ!", "sher@gmail.com", SOFTWARE);
	student.printStudentInfo();
	student.~Student();
	system("pause");
	return 0;
}


