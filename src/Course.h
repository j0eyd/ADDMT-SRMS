#ifndef _COURSE
#define _COURSE

#include <iostream>
#include <vector>
#include "Teacher.h"
#include "Student.h"
#include "Lecture.h"
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
	void setTeacher(Teacher& newTeacher);
	bool addLecture(Lecture& newLecture);
	bool dropLecture(Lecture& oldLecture);
	bool addStudent(Student& newStudent);
	bool dropStudent(Student& oldStudent);
};

#endif