#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Course.h"
#include <vector>

bool newTeacher(sqlite3* db,  string username, string password,
    string firstName, string lastName);

bool deleteTeacher(sqlite3* db, int userID);

vector<int> getTaughtCourseIDs(sqlite3* db, int userID);

string getBiography(sqlite3* db, int userID);

bool modifyBiography(sqlite3* db, int userID, string newBiography);

bool addTaughtCourse(sqlite3* db, int userID, int courseID);

bool dropTaughtCourse(sqlite3* db, int userID, int courseID);

#endif // TEACHER_H