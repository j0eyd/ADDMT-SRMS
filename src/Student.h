#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include "Grade.h"
using namespace std;

class Student : public User {
private:
    string biography;
    vector<Course*> coursesEnrolled;
    vector<Grade*> gradeList;

public:
    // Creator
    Student();
    Student(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName, vector<Course*> courses = {},
            vector<Grade*> grades = {});
    // Destructor
    ~Student();

    // Accessor Methods
    vector<Grade*> getCourseGrades(Course& course) const;
    vector<Course*> getCoursesEnrolled() const;
    string getBiography() const;
    // Mutator Methods

    bool setBiography(const string& newBiography);
    bool addEnrolledCourse(Course& course);
    bool dropEnrolledCourse(Course& course);
    bool addGrade(Grade& grade);
    bool dropGrade(Grade& grade);
};

#endif // STUDENT_H