#ifndef _LECTURE
#define _LECTURE

#include "Course.h"
#include <vector>

bool newLecture(sqlite3* db, string name, int associatedCourseID);
bool deleteLecture(sqlite3* db, int lectureID);

string getLectureName(sqlite3* db, int lectureID);
string getAttendanceTableName(sqlite3* db, int lectureID);
int getLectureCourseID(sqlite3* db, int lectureID);

//Returns true if the student with the ID studentID attended the lecture with the ID lectureID
bool getAttendanceStatus(sqlite3* db, int lectureID, int studentID);

bool modifyLectureName(sqlite3* db, int lectureID, string newLectureName);
bool addAttendingStudent(sqlite3* db, int lectureID, int studentID);
bool addMissingStudent(sqlite3* db, int lectureID, int studentID);
void lectureTester(sqlite3* db);
#endif