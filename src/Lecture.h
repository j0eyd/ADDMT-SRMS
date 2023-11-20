#ifndef _LECTURE
#define _LECTURE

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

// Forward declarations
class Student;
class Teacher;
class Course;

class Lecture {
private:
    int ID;
    string name;
    Course* associatedCourse;
    Teacher* teacher;
    unordered_set<Student*> attendance;

public:
    Lecture(); // Constructor
    ~Lecture(); // Destructor

    // Accessor methods
    int getID() const;
    string getName() const;
    Course* getAssociatedCourse() const;
    Teacher* getTeacher() const;
    bool getAttendanceStatus(Student& student) const;

    // Mutator methods
    void setID(int id);
    void setName(string name);
    void setTeacher(Teacher& newTeacher);
    bool addAttendingStudent(Student& newStudent);
    bool addMissingStudent(Student& oldStudent);
};

#endif

