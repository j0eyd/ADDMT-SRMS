#ifndef _GRADE
#define _GRADE
#include "Course.h"
#include "Student.h"

bool newGrade(sqlite3* db, int studentID, int courseID, float points, float outOf, float coeff);
bool deleteGrade(sqlite3* db, int gradeID);

//returns the IDs of the grades affected to a student for a specific course
vector<int> getStudentCourseGradeIDs(sqlite3* db, int studentID, int courseID);

    // Student* getStudent() const;
    // Course* getCourse() const;
    // string getIdentifier() const;
    // float getPoints() const;
    // float getOutOf() const;
    // float getValue() const;
    // float getCoeff() const;

    // // Mutator methods
    // void setStudent(Student& student);
    // void setIdentifier(const string& newIdentifier);
    // void setPoints(const float& newPoints);
    // void setOutOf(const float& newOutOf);
    // void setValue();
    // void setCoeff(const float& newCoeff);

#endif