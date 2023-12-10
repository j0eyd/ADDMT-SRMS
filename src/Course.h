#ifndef _COURSE
#define _COURSE

#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include "lib/sqlite3.h"
#include "Teacher.h"
using namespace std;

//vector to string
string vect_to_string(vector<int> IDs);

// Constructor
bool newCourse(sqlite3* db, string name);
// Destructor
bool deleteCourse(sqlite3* db, int courseID);

// Accessor Methods
int getCourseID(sqlite3* db, string name);
string getCourseName(sqlite3* db, int courseID);
//return all lectures attached to a course
vector<int> getCourseStudentIDs(sqlite3* db, int courseID);

//Mutator method
bool modifyCourseName(sqlite3* db, int UserID, string newCourseName);
//returns a list of the IDs of students enrolled in a specific course.

//adds some admins to the database - the other types are to be
//added with designated teacher and student methods
bool courseFillDatabase(sqlite3* db);
//makes some operations on database users
bool courseTestDatabase(sqlite3* db);

#endif