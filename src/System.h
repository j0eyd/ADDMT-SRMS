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
#include <sstream>
#include <fstream>

// A temporary test for main (may or may not be kept)
extern std::vector<User*> usersData;

void initializeSystem();
User* authenticateUser(const std::string& username, const std::string& password);
void showStudentMenu(Student* student);
void showTeacherMenu(Teacher* teacher);
void cleanupSystem();
