#ifndef _COURSE
#define _COURSE

#include <string>
#include <iostream>
#include "lib/sqlite3.h"
using namespace std;

// Constructor
bool newCourse(sqlite3* db, string& name);
// Destructor
bool deleteCourse(sqlite3* db, int courseID);

// Accessor Methods
int getCourseID(sqlite3* db, string name);
string getCourseName(sqlite3* db, int courseID);

//Mutator method
bool modifyCourseName(sqlite3* db, int UserID, string newCourseName);

void courseTester(sqlite3* db);

#endif