#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Grade.h"
#include <vector>
#include <string>

class Admin : public User {
public:
    Admin(const int& ID, const std::string& username, const std::string& password,
        const std::string& firstName, const std::string& lastName);
    ~Admin();

    // Profile management
    void createStudentProfile(const Student& student);
    void createTeacherProfile(const Teacher& teacher);
    void deleteProfile(const std::string& userID);
    void modifyStudentProfile(const std::string& userID, const Student& newStudentData);
    void modifyTeacherProfile(const std::string& userID, const Teacher& newTeacherData);

    // Course and grade management
    void enrollStudentInCourse(Student& student, Course& course);
    void unenrollStudentFromCourse(Student& student, Course& course);
    void assignGradeToStudent(Student& student, Grade& grade);
    void modifyStudentGrade(Student& student, Grade& newGradeData);
};

#endif // ADMIN_H

