#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Student.h"
#include "Course.h"
#include "Grade.h"
#include <vector>
using namespace std;

class Teacher : public User {
private:
    int teacherID;
    string teacherName;
    vector<Course*> coursesTaught;

public:
    // Creator
    Teacher();
    Teacher(const string& ID, const string& username, const string& password);
    // Destructor
    ~Teacher();

    // Accessor Methods
    string getID() const;
    string getName() const;

    // Mutator Methods
    void setID(const string& newID);
    void setName(const string& newName);

    void assignGrade(Student& student, Course& course, Grade& grade, Attendance& attendance);
    void addCourse(Course&);
    void removeCourse(Course&);
    void viewCourseGrades(Course&);
    
};

#endif // TEACHER_H
