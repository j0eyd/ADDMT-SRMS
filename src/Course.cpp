#include "Course.h"
#include "Lecture.h"

//Creator, Destructor methods
Course::Course(/* args */)
{}

Course::~Course()
{}

//Accessor methods
int Course::getID() {return ID;}

string Course::getName() {return name;}

Teacher* Course::getTeacher() {return teacher;}

vector<Lecture*> Course::getLectures() {return lectures;}

//Mutator methods

void Course::setID(int newID)
{
	ID = newID;
}

void Course::setName(string newName)
{
	name = newName;
}

void Course::setTeacher(Teacher& newTeacher)
{
	teacher = &newTeacher;
}

bool Course::addLecture(const Lecture& newLecture){
	//make sure that the lecture isn't already part of the course
	for(int i = 0; i<lectures.size(); i++){
		if (lectures[i]->getID() == newLecture.getID()) return false;
	}
	//add the lecture to the course
	lectures.push_back(&newLecture);
	return true;
}

bool Course::dropLecture(const Lecture& oldLecture){
	auto it = find(lectures.begin(), lectures.end(), &oldLecture);
	if (it!=lectures.end()){
		lectures.erase(it);
		return true;
	}
	//the method will only reach this point if the lecture was not part of the course
	return false;
}

bool Course::addStudent(const Student& newStudent){
	//make sure that the student isn't already part of the course
	for(int i = 0; i<students.size(); i++){
		if (students[i]->getID() == newStudent.getID()) return false;
	}
	//add the student to the course
	students.push_back(&newStudent);
	return true;
}

bool Course::dropStudent(const Student& oldStudent){
	auto it = find(students.begin(), students.end(), &oldStudent);
	if (it!=students.end()){
		students.erase(it);
		return true;
	}
	//the method will only reach this point if the student was not part of the course
	return false;
}