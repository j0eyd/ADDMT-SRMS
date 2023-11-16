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
	int getID() const;
	string getName() const;
	Course* getAssociatedCourse() const;
	Teacher* getTeacher() const;
	bool getAttendanceStatus(Student& student) const;
	//mutator methods
	void setID(int id);
	void setName(string name);
	void setTeacher(Teacher& newTeacher);
	bool addAttendingStudent(Student& newStudent);
	bool addMissingStudent(Student& oldStudent);
};

#endif
