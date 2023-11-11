#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Student : public User {
private:
    vector<Course*> coursesEnrolled;
    unordered_map<int,Grade*> grades; // Assuming getID() returns an int

public:
    Student(const string& userID, const string& username, const string& password);
    ~Student();
   
    Grade* newGrade(float points, float outOf, float coeff);
    Grade* updateGrade(Course& course);
    bool updateBio(const string& biography);

    // Additional methods as required...
};

#endif // STUDENT_H
