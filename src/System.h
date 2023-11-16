#include <iostream>
#include <vector>
#include <string>
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Lecture.h"
#include "Grade.h"
#include "User.h"

// A temporary test for main (may or may not be kept)

User* authenticateUser(const std::string& username, const std::string& password);
void showStudentMenu(Student* student);
void showTeacherMenu(Teacher* teacher);
