#ifndef _LECTURE
#define _LECTURE

#include <vector>
#include <iostream>
#include <unordered_set>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
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
	bool getAttendanceStatus(Student& student);
	//mutator methods
	void setID(int id);
	void setName(string name);
	void setTeacher(Teacher& newTeacher);
	bool studentAttended(Student& newStudent);
	bool studentMissed(Student& oldStudent);
};

#endif
