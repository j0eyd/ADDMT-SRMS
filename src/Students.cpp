#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "User.h"
#include "Course.h"


class Student : public User {
private:
    std::string studentID; 
    std::string studentName; 
    std::vector<Course*> coursesEnrolled;
    std::vector<Grade*> gradeList;

public:
    
    Student(const std::string& userID, const std::string& username, const std::string& password, 
            const std::string& sID, const std::string& sName)
    : User(userID, username, password), studentID(sID), studentName(sName) {}

    // Accessors
    string getID() const { return studentID; }
    string getName() const { return studentName; }

    // Mutators
    void setStudentID(const std::string& newID) { studentID = newID; }
    void setStudentName(const std::string& newName) { studentName = newName; }

};


