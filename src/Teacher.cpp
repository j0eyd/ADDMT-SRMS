#include <iostream>
#include <vector>
#include <string>

#include "User.h"
#include "Student.h"
// #include "Course.h"
// #include "Grade.h"
// #include "Attendance.h"

class Teacher : public User{
private:
    std::vector<Course*> courseTaught;
public:
    Teacher(const std::string& userID, const std::string& username, const std::string& password)
    : User(userID, username, password){

    }

    void assignGrade(Student& student, Course& course, Grade& grade, Attendance& attendance){

    }
};