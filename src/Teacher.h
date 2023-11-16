#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Student.h"
#include "Course.h"
#include "Grade.h"

class Teacher : public User {
protected:
    vector<Course*> coursesTaught;
    //as well as all attributes from User
public:
    // Creators
    Teacher();
    Teacher(const int& ID, const string& username, const string& password, 
            const string& firstName, const string& lastName,
            vector<Course*> coursesTaught);

    // Destructor
    virtual ~Teacher();

    // All user-related accessors and mutators are inherited from user
    //Accessors
    vector<Course*> getCoursesTaught() const;
    bool getStudentLectureAttendance(const Lecture& lecture,
        Student& student) const;
    vector<Grade*> getStudentCourseGrades(const Student& student,
        Course& course) const;

    //Mutators
    bool addCourseTaught(Course& course);
    bool dropCourseTaught(Course& course);
    bool addLecturePresentStudent(Lecture& lecture, Student& student);
    bool dropLectureMissingStudent(Lecture& lecture, Student& student);
    bool addStudentGrade(Student& student, Grade& grade);
    bool modifyStudentGrade(const Student& student, Grade& grade,
        const string& newIdentifier, const float& newPoints, const float& newOutOf,
        const float& newCoeff);
    bool dropStudentGrade(Student& student, Grade& oldGrade);
};

#endif // TEACHER_H
