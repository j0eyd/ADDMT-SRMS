#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include "Grade.h"
#include <vector>
using namespace std;

class Student : public User {
private:
    std::string studentID;
    std::string studentName;
    std::vector<Course*> coursesEnrolled;
    std::vector<Grade*> gradeList;

public:
    // Creator
    Student();
    Student(const std::string& userID, const std::string& username, const std::string& password, 
            const std::string& sID, const std::string& sName);
    // Destructor
    ~Student();

    // Accessor Methods
    string getID() const;
    string getName() const;
    Grade* getGrade(Course& course);

    // Mutator Methods
    void setID(const std::string& newID);
    void setName(const std::string& newName);
    bool updateBio(const std::string& biography);
};

#endif // STUDENT_H