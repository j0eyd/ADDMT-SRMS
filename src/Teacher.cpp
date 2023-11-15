#include <iostream>
#include <vector>
#include <string>

#include "User.h"
#include "Student.h"

class Teacher : public User {
private:
    string teacherID;
    string teacherName; 
    vector<Course*> courseTaught;

public:
    Teacher(const string& userID, const string& username, const string& password, 
            const string& tID, const string& tName)
    : User(userID, username, password), teacherID(tID), teacherName(tName) {}

    // Accessors
    string getID() const { return teacherID; }
    string getName() const { return teacherName; }

    // Mutators
    void setID(const string& newID) { teacherID = newID; }
    void setName(const string& newName) { teacherName = newName; }

    
};
