#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "Database.h"
#include "Student.h"
#include "Teacher.h"

class Admin {
private:
    Database& db; // Reference to a database to manage persistence

public:
    Admin(Database& db);

    void createStudentProfile(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName);
    void deleteStudentProfile(Student& oldStudent);

    void createTeacherProfile(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName);
    void deleteTeacherProfile(const Teacher& teacher);

    void createCourse(int& ID, const string& name, Teacher& teacher, vector<Lecture*> lectures, vector<Student*>& students);
    void deleteCourse(const int& ID);

    void modifyStudentGrade(const string& studentId, const string& courseId, float newGrade);

};

#endif // ADMIN_H

