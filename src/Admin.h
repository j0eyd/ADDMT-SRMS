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

    void createStudentProfile(const Student& student);
    void deleteStudentProfile(const std::string& studentId);

    void createTeacherProfile(const Teacher& teacher);
    void deleteTeacherProfile(const std::string& teacherId);

};

#endif // ADMIN_H

