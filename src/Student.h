#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include "Grade.h"
#include <vector>
using namespace std;

class Student : public User {
private:
    int studentID;
    string studentName;
    string Biography;
    vector<Course*> coursesEnrolled;
    vector<Grade*> gradeList;

public:
    // Creator
    Student();
    Student(const int& userID, const string& username, const string& password, 
            const int& sID, const string& sName);
    // Destructor
    ~Student();

    // Accessor Methods
    int getID() const;
    string getName() const;
    vector<Grade*> getGrades(Course& course);

    // Mutator Methods
    void setID(const int& newID);
    void setName(const string& newName);
    bool updateBio(const string& biography);
    //addgrade, dropgrade. set the whole grade paradigm. write methods to get attendance for teachers.
};

#endif // STUDENT_H