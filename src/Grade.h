#ifndef _GRADE
#define _GRADE
#include "Course.h"
#include "Student.h"
#include <string>

using namespace std;

class Student;
class Course;

class Grade {
private:
    Student* student;
    Course* course;
    string identifier;
    float points;
    float outOf;
    float value;
    float coeff;

public:
    // Constructor, Destructor
    Grade();
    Grade(Student& student, Course& course, const string& identifier,
        const float& points, const float& outOf, const float& value,
        const float& coeff);
    ~Grade();

    // Accessor methods
    Student* getStudent() const;
    Course* getCourse() const;
    string getIdentifier() const;
    float getPoints() const;
    float getOutOf() const;
    float getValue() const;
    float getCoeff() const;

    // Mutator methods
    void setStudent(Student& student);
    void setCourse(Course& course);
    void setIdentifier(const string& newIdentifier);
    void setPoints(const float& newPoints);
    void setOutOf(const float& newOutOf);
    void setValue();
    void setCoeff(const float& newCoeff);
};

#endif