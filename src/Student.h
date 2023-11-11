#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include <vector>
#include <unordered_map>
using namespace std;

class Student : public User {
private:
    int ID;
    string firstName;
    string lastName;
    string biography;
    string username;
    string password;
    vector<Course*> coursesEnrolled;
    vector<Grade*> grades;
public:
    //crea
    Student(const string& userID, const string& username, const string& password);
    ~Student();
    int getID();
    string getFirstName();
    string getLastName();
    string getBiography();
    string getUsername();
    string getPassword(); //lol
    vector<Course*> getCourses();
    vector<Grade*> getGrades();

    // Additional methods as required...
};

#endif // STUDENT_H
