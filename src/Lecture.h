#ifndef _LECTURE
#define _LECTURE

#include <vector>
#include <iostream>
#include <unordered_set>
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Lecture
{
private:
	int ID;
	string name;
	Course* associatedCourse;
	Teacher* teacher;
	unordered_set<Student*> attendance;
public:
	Lecture(); //creator
	~Lecture(); //destructor
	//accessor methods
	int getID();
	string getName();
	Course* getAssociatedCourse();
	Teacher* getTeacher();
	bool getAttendanceStatus(const Student& student);
	//mutator methods
	void setID(int id);
	void setName(string name);
	void setTeacher(const Teacher& newTeacher);
	bool studentAttended(const Student& newStudent);
	bool studentMissed(const Student& oldStudent);
};

#endif
