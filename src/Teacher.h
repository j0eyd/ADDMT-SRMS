#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Student.h"
#include "Course.h"
#include "Grade.h"
#include <vector>
using namespace std;

class Teacher : public User {
private:
    std::string teacherID;
    std::string teacherName;
    std::vector<Course*> courseTaught;

public:
    // Creator
    Teacher();
    Teacher(const std::string& userID, const std::string& username, const std::string& password);
    // Destructor
    ~Teacher();

    // Accessor Methods
    string getID() const;
    string getName() const;

    // Mutator Methods
    void setID(const std::string& newID);
    void setName(const std::string& newName);

    void assignGrade(Student& student, Course& course, Grade& grade, Attendance& attendance);
    void addCourse(Course&);
    void removeCourse(Course&);
    void viewCourseGrades(Course&);
    
};

#endif // TEACHER_H
