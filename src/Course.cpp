#include "Course.h"
#include "Lecture.h"
#include <algorithm> // For std::find_if
#include <functional> // For lambda functions

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

bool Course::addLecture(Lecture& newLecture){
	//make sure that the lecture isn't already part of the course
	for(size_t i = 0; i<lectures.size(); i++){
		if (lectures[i]->getID() == newLecture.getID()) return false;
	}
	//add the lecture to the course
	lectures.push_back(&newLecture);
	return true;
}

bool Course::dropLecture(Lecture& oldLecture){
	auto it = find(lectures.begin(), lectures.end(), &oldLecture);
	if (it!=lectures.end()){
		lectures.erase(it);
		return true;
	}
	//the method will only reach this point if the lecture was not part of the course
	return false;
}

bool Course::addStudent(Student& newStudent){
	//make sure that the student isn't already part of the course
	for(size_t i = 0; i<students.size(); i++){
		if (students[i]->getID() == newStudent.getID()) return false;
	}
	//add the student to the course
	students.push_back(&newStudent);
	return true;
}

bool Course::dropStudent(Student& oldStudent) {
	// Use std::find_if with a lambda function to find the student
	auto it = std::find_if(students.begin(), students.end(), [&oldStudent](const Student* student) {
		return student->getID() == oldStudent.getID();
		});

	if (it != students.end()) {
		students.erase(it);
		return true;
	}

	// Student not found in the course
	return false;
}
