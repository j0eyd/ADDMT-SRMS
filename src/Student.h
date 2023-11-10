#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
// #include "grade.h"
#include <vector>

class Student : public User {
private:
    std::vector<Course*> coursesEnrolled;
    std::vector<Grade*> gradeList;

public:
    Student(const std::string& userID, const std::string& username, const std::string& password);
    ~Student();

    Grade* getGrade(Course& course);
    Grade* updateGrade(const std::string& gradeValue, double percentage);
    bool updateBio(const std::string& biography);

    // Additional methods as required...
};

#endif // STUDENT_H