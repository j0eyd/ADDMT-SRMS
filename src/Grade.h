#ifndef _GRADE
#define _GRADE
#include "Course.h"
#include "Student.h"

bool newGrade(sqlite3* db, int studentID, int courseID, float points, float outOf, float coeff);
bool deleteGrade(sqlite3* db, int gradeID);

//returns the IDs of the grades affected to a student for a specific course
vector<int> getStudentCourseGradeIDs(sqlite3* db, int studentID, int courseID);

int getGradeStudentID(sqlite3* db, int gradeID);
int getGradeCourseID(sqlite3* db, int gradeID);
float getGradePoints(sqlite3* db, int gradeID);
float getGradeOutOf(sqlite3* db, int gradeID);
float getGradeValue(sqlite3* db, int gradeID);
float getGradeCoeff(sqlite3* db, int gradeID);

bool setGradeStudentID(sqlite3* db, int gradeID, int newStudentID);
bool setGradeCourseID(sqlite3* db, int gradeID, int newCourseID);
bool setGradePoints(sqlite3* db, int gradeID, float newPoints);
bool setGradeOutOf(sqlite3* db, int gradeID, float newOutOf);
//no need to specify points or outOf, this function simply makes sure that the value is correctly set
//this function is automatically called after any modification of the grade.
bool setGradeValue(sqlite3* db, int gradeID);
bool setGradeCoeff(sqlite3* db, int gradeID, float newCoeff);


#endif