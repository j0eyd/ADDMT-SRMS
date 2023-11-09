#ifndef _COURSE
#define _COURSE

#include <iostream>
#include <vector>
#include "Teacher.h"
#include "Student.h"
using namespace std;

class Course
{
private:
	int ID;
	string name;
	Teacher* teacher;
	vector<Lecture*> lectures;
	vector<Student*> students;
public:
	Course(); //creator
	~Course(); //destructor
	//accessor methods
	int getID();
	string getName();
	Teacher* getTeacher();
	vector<Lecture*> getLectures();
	vector<Student*> getStudents();
	//mutator methods
	void setID(int id);
	void setName(string name);
	void setTeacher(const Teacher& newTeacher);
	bool addLecture(const Lecture& newLecture);
	bool dropLecture(const Lecture& oldLecture);
	bool addStudent(const Student& newStudent);
	bool dropStudent(const Student& oldStudent);
};

#endif