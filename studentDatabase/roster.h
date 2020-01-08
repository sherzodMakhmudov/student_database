#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
class Roster {
private:
	int lastIndex;
	int sizeofArray;
	Student** rosterArray;

public:
	Roster();
	Roster(int sizeofArray);
};


#endif // !ROSTER_H

