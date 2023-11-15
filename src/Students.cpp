#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "User.h"
#include "Course.h"


class Student : public User {
private:
    string studentID; 
    string studentName; 
    vector<Course*> coursesEnrolled;
    vector<Grade*> gradeList;

public:
    
    Student(const string& userID, const string& username, const string& password, 
            const string& sID, const string& sName)
    : User(userID, username, password), studentID(sID), studentName(sName) {}

    // Accessors
    string getID() const { return studentID; }
    string getName() const { return studentName; }

    // Mutators
    void setStudentID(const string& newID) { studentID = newID; }
    void setStudentName(const string& newName) { studentName = newName; }

};


