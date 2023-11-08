#include <iostream>
#include <vector>
#include <unordered_map>
#include "Lecture.cpp"
#include "Teacher.cpp"
#include "Student.cpp"
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

//Creator, Destructor methods
Course::Course(/* args */)
{
}

Course::~Course()
{
}

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

void Course::setTeacher(const Teacher& newTeacher)
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