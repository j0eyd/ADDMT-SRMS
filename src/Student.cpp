#include "Student.h"

Student::Student() {}

Student::Student(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName, vector<Course*> courses = {},
            vector<Grade*> grades = {})
    : User(ID, username, password, firstName, lastName), coursesEnrolled(courses),
        gradeList(grades) {}

Student::~Student() {
}

vector<Grade*> Student::getCourseGrades(Course& course) const{
    vector<Grade*> result;
    for (Grade* grade : gradeList){
        if (grade->getCourse() == &course) result.push_back(grade);
    }
    return result;
}

vector<Course*> Student::getCoursesEnrolled() const {return coursesEnrolled;}

string Student::getBiography() const {return biography;}
// Mutator Methods

bool Student::setBiography(const string& newBiography){
    if (biography==newBiography) return false;
    biography = newBiography;
    return true;
}

bool Student::addEnrolledCourse(Course& course){
    auto it = find(coursesEnrolled.begin(), coursesEnrolled.end(), &course);
    if (it!=coursesEnrolled.end()) return false; //course already present
    coursesEnrolled.push_back(&course);
    return true;
}

bool Student::dropEnrolledCourse(Course& course){
    auto it = find(coursesEnrolled.begin(), coursesEnrolled.end(), &course);
    if (it==coursesEnrolled.end()) return false; //course already absent
    coursesEnrolled.erase(it);
    return true;
}

bool Student::addGrade(Grade& grade){
    auto it = find(gradeList.begin(), gradeList.end(), &grade);
    if (it!=gradeList.end()) return false; //grade already present
    gradeList.push_back(&grade);
    grade.setStudent(*this);
    return true;
}

bool Student::dropGrade(Grade& grade){
    auto it = find(gradeList.begin(), gradeList.end(), &grade);
    if (it==gradeList.end()) return false; //grade already absent
    gradeList.erase(it);
    return true;
}