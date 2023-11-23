#include "Database.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

// Constructor
Database::Database() {
    // Initialization if necessary
}

// Destructor
Database::~Database() {
    for (auto* student : studentList) delete student;
    for (auto* teacher : teacherList) delete teacher;
    for (auto* course : courseList) delete course;
}

// Student-related methods
void Database::saveStudent(Student* student) {
    studentList.push_back(student);
}

void Database::deleteStudent(const std::string& studentId) {
    // ... implementation
}


// Teacher-related methods
void Database::saveTeacher(Teacher* teacher) {
    teacherList.push_back(teacher);
}

void Database::deleteTeacher(const std::string& teacherId) {
    auto it = std::find_if(teacherList.begin(), teacherList.end(),
        [&teacherId](const Teacher* teacher) {
            return teacher->getID() == std::stoi(teacherId);
        });
    if (it != teacherList.end()) {
        delete* it;  // Free memory
        teacherList.erase(it);
    }
}

// Course-related methods
void Database::saveCourse(Course* course) {
    courseList.push_back(course);
}

void Database::deleteCourse(const std::string& courseId) {
    auto it = std::find_if(courseList.begin(), courseList.end(),
        [&courseId](const Course* course) {
            return course->getID() == std::stoi(courseId);
        });
    if (it != courseList.end()) {
        delete* it;  // Free memory
        courseList.erase(it);
    }
}


// File IO methods
void saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    // Write the header
    file << "ID,Username,Password,FirstName,LastName,Type\n";

    // Serialize and write students
    for (const auto& student : studentList) {
        file << student->getID() << ","
            << student->getUsername() << ","
            << student->getPassword() << ","
            << student->getFirstName() << ","
            << student->getLastName() << ","
            << "Student" << "\n";
    }
    // Repeat for teachers, admins, and courses
    // ...

    file.close();
}

void loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    // Skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, username, password, firstName, lastName, type;
        std::getline(ss, id, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, type, ',');

        if (type == "Student") {
            // Construct a new student object and add to the database
        }
        // Repeat for teachers, admins, and courses
        // ...
    }
    file.close();
}

void Database::modifyStudentGrade(const std::string& studentId, const std::string& courseId, float newGrade) {
    // Find the student by ID
    auto studentIter = std::find_if(studentList.begin(), studentList.end(),
                                    [&studentId](const Student* student) {
                                        return student->getID() == std::stoi(studentId);
                                    });

    if (studentIter != studentList.end()) {
        Student* student = *studentIter;
        // Find the corresponding course
        auto courseIter = std::find_if(courseList.begin(), courseList.end(),
                                       [&courseId](const Course* course) {
                                           return course->getID() == std::stoi(courseId);
                                       });

        if (courseIter != courseList.end()) {
            Course* course = *courseIter;
            // Now find and update the grade
            for (Grade* grade : student->getCourseGrades(*course)) {
                grade->setPoints(newGrade); // Assuming Grade class has a method to set new grade points
                // Perform any additional updates required for the Grade object
                break;
            }
        }
    }
}


// Move constructor and move assignment operator if needed
Database::Database(Database&&) noexcept = default;
Database& Database::operator=(Database&&) noexcept = default;