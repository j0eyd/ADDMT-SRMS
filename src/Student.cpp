#include "Student.h"

Student::Student() {}

Student::Student(const int& userID, const string& username, const string& password, 
            const int& sID, const string& sName)
    : User(userID, username, password), studentID(sID), studentName(sName) {}

Student::~Student() {
}

int Student::getID() const {
    return ID;
}

string Student::getName() const {
    return username;
}

vector<Grade*> Student::getGrades(Course& course) {
    return gradeList;
}

// Mutator Methods
void Student::setID(const int& newID) {
    studentID = newID;
}

void Student::setName(const string& newName) {
    studentName = newName;
}

bool Student::updateBio(const string& newBiography) {
    Biography = newBiography;
    return true;
}
