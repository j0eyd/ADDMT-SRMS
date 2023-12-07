#ifndef _COURSE
#define _COURSE

#include <string>
#include <iostream>
#include <vector>
#include "lib/sqlite3.h"
using namespace std;

// Constructor
bool newCourse(sqlite3* db, string& name);
// Destructor
bool deleteCourse(sqlite3* db, int courseID);

// Accessor Methods
int getCourseID(sqlite3* db, string name);
string getCourseName(sqlite3* db, int courseID);
//return all lectures attached to a course
vector<int> getLecturesIDFromCourse(sqlite3* db, int courseID);

//Mutator method
bool modifyCourseName(sqlite3* db, int UserID, string newCourseName);
//returns a list of the IDs of students enrolled in a specific course.
vector<int> getCourseStudentIDs(sqlite3* db, int courseID);
void courseTester(sqlite3* db);

#endif