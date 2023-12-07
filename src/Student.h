#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include <vector>

bool newStudent(sqlite3* db, string biography,  string username, string password,
    string firstName, string lastName);

bool deleteStudent(sqlite3* db, int userID);

vector<int> getEnrolledCourseIDs(sqlite3* db, int userID);

string getBiography(sqlite3* db, int userID);

bool modifyBiography(sqlite3* db, int userID, string newBiography);

bool addEnrolledCourse(sqlite3* db, int userID, int courseID);

bool dropEnrolledCourse(sqlite3* db, int userID, int courseID);

#endif // STUDENT_H