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
    Teacher(const std::string& userID, const std::string& username, const std::string& password, 
            const std::string& tID, const std::string& tName)
    : User(userID, username, password), teacherID(tID), teacherName(tName) {}

    // Accessors
    string getID() const { return teacherID; }
    string getName() const { return teacherName; }

    // Mutators
    void setID(const std::string& newID) { teacherID = newID; }
    void setName(const std::string& newName) { teacherName = newName; }

    
};
