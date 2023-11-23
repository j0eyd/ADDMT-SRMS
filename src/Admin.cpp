#include <iostream>
#include <vector>
#include <string>
#include "Admin.h"
#include "User.h"

class Admin : public User{
public:
    Admin(const int& ID, const std::string& username, const std::string& password,
        const std::string& firstName, const std::string& lastName)
        : User(ID, username, password, firstName, lastName) {}

    void Admin::createStudentProfile(const Student& student) {
        // Add student to data storage (e.g., database, file)
        std::cout << "Student profile created for: " << student.getFirstName() << std::endl;
    }

    void Admin::createTeacherProfile(const Teacher& teacher) {
        // Add teacher to data storage
        std::cout << "Teacher profile created for: " << teacher.getFirstName() << std::endl;
    }

    void Admin::deleteProfile(const std::string& userID) {
        // Remove user (student/teacher) from data storage
        std::cout << "Profile deleted for user ID: " << userID << std::endl;
    }

    void Admin::modifyStudentProfile(const std::string& userID, const Student& newStudentData) {
        // Update student information in data storage
        std::cout << "Student profile updated for user ID: " << userID << std::endl;
    }

    void Admin::modifyTeacherProfile(const std::string& userID, const Teacher& newTeacherData) {
        // Update teacher information in data storage
        std::cout << "Teacher profile updated for user ID: " << userID << std::endl;
    }

    void Admin::enrollStudentInCourse(Student& student, Course& course) {
        student.addEnrolledCourse(course);
        std::cout << "Student " << student.getFirstName() << " enrolled in course: " << course.getName() << std::endl;
    }

    void Admin::unenrollStudentFromCourse(Student& student, Course& course) {
        student.dropEnrolledCourse(course);
        std::cout << "Student " << student.getFirstName() << " unenrolled from course: " << course.getName() << std::endl;
    }

    void Admin::assignGradeToStudent(Student& student, Grade& grade) {
        student.addGrade(grade);
        std::cout << "Grade assigned to student " << student.getFirstName() << std::endl;
    }

    void Admin::modifyStudentGrade(Student& student, Grade& newGradeData) {
        // Assume we can identify the grade to modify
        // This would require more detailed implementation
        std::cout << "Student grade modified for " << student.getFirstName() << std::endl;
    }

    //Method to manually save a local backup file
    void saveBackup(const std::string& filepath){
        
    }

    //Method to load a local backup file
    void loadBackup(const std::string& filepath){
        
    }
};