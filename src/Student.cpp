#include <iostream>
#include <vector>
#include <string>

#include "User.h"
// #include "Course.h"
// #include "Grade.h"
// #include "Attendance.h"

class Student : public User{
private:
    std::vector<Course*> coursesEnrolled;
    std::vector<Grade*> gradeList;
public:
    Student(const std::string& userID, const std::string& username, const std::string& password)
    : User(userID, username, password){

    }

    //Method to get grade for a course
    Grade* getGrade(Course& course){
        //Search for the grade in the gradeList based on the course 
        // and return it
        for(auto& grade : gradeList){
            if(grade->getCourse() == &course){
                return grade;
            }
        }
        return nullptr;
    }
};

