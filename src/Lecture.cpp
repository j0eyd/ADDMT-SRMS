#include "Lecture.h"
#include "Course.h"

//Creator, Destructor methods
Lecture::Lecture()
{}

Lecture::~Lecture()
{}

//Accessor methods
int Lecture::getID() {return ID;}

string Lecture::getName() {return name;}

Course* Lecture::getAssociatedCourse() {return associatedCourse;}

Teacher* Lecture::getTeacher() {return teacher;}

bool Lecture::getAttendanceStatus(Student& student){
	//if the pointer to that student is in the hash_set,
	//had been counted as present previously.
	return attendance.count(&student)>0;
}

//Mutator methods

void Lecture::setID(int newID)
{
	ID = newID;
}

void Lecture::setName(string newName)
{
	name = newName;
}

void Lecture::setTeacher(Teacher& newTeacher)
{
	teacher = &newTeacher;
}

bool Lecture::addAttendingStudent(Student& newStudent){
	if (attendance.count(&newStudent)>0) return false;
	//the method will only reach this point if the student was not already in the set
	attendance.insert(&newStudent);
	return true;
}

bool Lecture::addMissingStudent(Student& oldStudent){
	if (attendance.count(&oldStudent)==0) return false;
	//the method will only reach this point if the student was already in the set
	attendance.erase(&oldStudent);
	return true;
}
