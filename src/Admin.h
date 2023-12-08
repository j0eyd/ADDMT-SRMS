#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Course.h"
#include "Teacher.h"
#include "Grade.h"

//note: many of the functions needed by the admin are defined elsewhere - 
//for instance, to get all lectures from a course, use the function defined in Lecture.cpp

bool newAdmin(sqlite3* db,  string username, string password,
    string firstName, string lastName);

bool deleteAdmin(sqlite3* db, int userID);

//returns a list of the ids of all the existing courses
vector<int> getAllCoursesIDs(sqlite3* db);

//returns a list of the ids of all the existing Users
vector<int> getAllUsersIDs(sqlite3* db);

#endif
