#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Student.h"
// #include "course.h"
// #include "grade.h"
// #include "attendance.h"
#include <vector>

class Teacher : public User {
private:
    std::vector<Course*> coursesTaught;

public:
    Teacher(const std::string& userID, const std::string& username, const std::string& password);
    ~Teacher();

    void assignGrade(Student& student, Course& course, Grade& grade, Attendance& attendance);

    // Additional methods as required...
};

#endif // TEACHER_H
